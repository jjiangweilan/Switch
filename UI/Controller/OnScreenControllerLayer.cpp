//
//  OnScreenController.cpp
//  mayo
//
//  Created by jiehong jiang on 7/9/17.
//
//

#include "OnScreenControllerLayer.hpp"

OnScreenControllerLayer* OnScreenControllerLayer::create(const Size& screenSize){
    OnScreenControllerLayer *pRet = new(std::nothrow) OnScreenControllerLayer(screenSize);
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    delete pRet;
    pRet = nullptr;
    return nullptr;
}


void OnScreenControllerLayer::addLeftSpace(){
    //left layer
    leftSpace = Sprite::create();
    leftSpace->setAnchorPoint(Vec2::ZERO);
    leftSpace->setPosition(Vec2::ZERO);
    leftSpace->setContentSize(Size(screenSize.width / 2, screenSize.height));
    addChild(leftSpace);
    
    auto touch = EventListenerTouchOneByOne::create();
    touch->onTouchBegan = [&](Touch* touch, Event* event) -> bool{
        auto pos = touch->getLocation();
        if (!leftSpace->getBoundingBox().containsPoint(pos))return false;
        this->showStickLayer(pos);
        return true;
    };
    
    touch->onTouchMoved = [&](Touch* touch, Event* event) -> bool{
        
        Vec2 orinPos = stickLayer->getPosition();
        Vec2 currPos = touch->getLocation();
        Vec2 prePos = touch->getPreviousLocation();
        Vec2 CODiff = currPos - orinPos;
        
        float radius = 50;
        float length = CODiff.length();
        
        stick->setPosition(currPos);

        //move stick
        if (length >= radius){
            Vec2 CPDiff = currPos - prePos;
            Vec2 PODiff = prePos - orinPos;
            Vec2 delta = CPDiff + PODiff;
            float radio = (delta.length() - radius) / delta.length();
            delta *= radio;
            stickLayer->setPosition(stickLayer->getPosition() + delta);
        }
        
        auto stickRelativePos = stick->getPosition() - stickLayer->getPosition();
        if (stickRelativePos.x > 30){if (onRight)onRight();}
        else if (stickRelativePos.x < -30){if(onLeft)onLeft();}
        
        //this is for testing. The original design is trigglering abilities
        if (stickRelativePos.y > 30){if(onUp)onUp();}
        else if (stickRelativePos.y < -30){if(onDown)onDown();}
        
        return true;
    };
    
    touch->onTouchEnded = [&](Touch* touch, Event* event) -> bool {
        this->hideStickLayer();
        if(onLeftRelease)onLeftRelease();
        return true;
    };
    
    leftSpace->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touch, leftSpace);
    
}

void OnScreenControllerLayer::addRightSpace(){
    rightSpace = Sprite::create();
    rightSpace->setAnchorPoint(Vec2::ZERO);
    rightSpace->setPosition(Vec2(screenSize.width / 2, 0));
    rightSpace->setContentSize(Size(screenSize.width / 2, screenSize.height));
    
    auto touch = EventListenerTouchOneByOne::create();
    addChild(rightSpace);
    touch->onTouchBegan = [&](Touch* touch, Event* event) -> bool{
        auto pos = touch->getLocation();
        if (!rightSpace->getBoundingBox().containsPoint(pos)) return false;
        else if (jump->getBoundingBox().containsPoint(pos)){if(onPressJump)onPressJump();}
        else if (summon->getBoundingBox().containsPoint(pos)){
            if(onPressSummon)onPressSummon();
            changeSummonAndRecallButton();
        }
        else if (switch_->getBoundingBox().containsPoint(pos)){if(onPressSwitch)onPressSwitch();}
        return true;
    };
    
    rightSpace->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touch, rightSpace);
    
    
}

void OnScreenControllerLayer::showStickLayer(const Vec2& pos){
    stickLayer->setVisible(true);
    stick->setVisible(true);
    stick->setPosition(pos);
    stickLayer->setPosition(pos);
}

void OnScreenControllerLayer::hideStickLayer(){
    stickLayer->setVisible(false);
    stick->setVisible(false);
}

void OnScreenControllerLayer::addRightController(){
    
}

OnScreenControllerLayer::OnScreenControllerLayer(const Size& screenSize) : screenSize(screenSize){
    onRight = NULL;
    onLeft = NULL;
    onLeftRelease = NULL;
    onRightRelease = NULL;
    onPressJump = NULL;
    
    addLeftSpace();
    addRightSpace();
    addRightController();
    
    stickLayer = Sprite::create("res/UI/onScreenControl/stick_layer.png");
    stickLayer->setScale(0.7);
    stick = Sprite::create("res/UI/onScreenControl/stick.png");
    stick->setScale(0.7);
    stickLayer->setVisible(false);
    stick->setVisible(false);
    
    //jumpButton
    jump = Sprite::create("res/UI/onScreenControl/jump.png");
    jump->setPosition(Vec2(5.0 / 6.0 * screenSize.width, 1.0 / 4.0 * screenSize.height));
    jump->setScale(1.3);
    
    //switch button
    switch_ = Sprite::create("res/UI/onScreenControl/jump.png");
    switch_->setPosition(Vec2(5.0 / 6.0 * screenSize.width, 2.0 / 4.0 * screenSize.height));
    switch_->setScale(1.3);
    
    //summon and recall button
    summon = Sprite::create("res/UI/onScreenControl/jump.png");
    summon->setPosition(Vec2(5.0 / 6.0 * screenSize.width, 3.0 / 4.0 * screenSize.height));
    summon->setScale(1.4);
    
    addChild(switch_);
    addChild(summon);
    addChild(jump);
    addChild(stick);
    addChild(stickLayer);
}

void OnScreenControllerLayer::changeSummonAndRecallButton(){
    if(isSummonButton){
        auto frame = SpriteFrame::create("res/UI/onScreenControl/stick.png", Rect(0, 0, summon->getContentSize().width, summon->getContentSize().height));
        summon->setSpriteFrame(frame);
    }
    else{
        auto frame = SpriteFrame::create("res/UI/onScreenControl/jump.png", Rect(0, 0, summon->getContentSize().width, summon->getContentSize().height));
        summon->setSpriteFrame(frame);
    }
}
OnScreenControllerLayer::~OnScreenControllerLayer(){
    
}
