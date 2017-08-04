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
        
        //right
        if (stickRelativePos.x > 30){if (controlComponent_)controlComponent_->onRight();}
        //left
        else if (stickRelativePos.x < -30){if(controlComponent_)controlComponent_->onLeft();}
        
        
        return true;
    };
    
    touch->onTouchEnded = [&](Touch* touch, Event* event) -> bool {
        this->hideStickLayer();
        if(controlComponent_)controlComponent_->onLeftRelease();
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
        auto jump = getChildByName<Sprite*>("jump");
        auto summonAndRecall = getChildByName<Sprite*>("sr");
        auto switch_ = getChildByName<Sprite*>("switch");
        
        auto pos = touch->getLocation();
        if (!rightSpace->getBoundingBox().containsPoint(pos)) return false;
        //jump
        else if (jump->getBoundingBox().containsPoint(pos)){
            if(controlComponent_) controlComponent_->onJump();
        }
        //summon and recall
        else if (summonAndRecall->getBoundingBox().containsPoint(pos)){
            if(controlComponent_ && !isSummoned){
                isSummoned = controlComponent_->onSummon();
            }
            
            else if (controlComponent_ && isSummoned) {
                isSummoned = !controlComponent_->onRecall();
            }
            
            switchSummonAndRecallButton();
        }
        
        //switch
        else if (hasSwitch && switch_->getBoundingBox().containsPoint(pos)){if(controlComponent_)
            controlComponent_->onSwitch();
        }
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
    auto jump = Sprite::create("res/UI/onScreenControl/jump.png");
    jump->setName("jump");
    jump->setPosition(Vec2(5.0 / 6.0 * screenSize.width, 1.0 / 4.0 * screenSize.height));
    jump->setScale(1.3);
    
    //switch button
    auto switch_ = Sprite::create("res/UI/onScreenControl/switch.png");
    switch_->setPosition(Vec2(5.0 / 6.0 * screenSize.width, 2.0 / 4.0 * screenSize.height));
    switch_->setScale(1.3);
    switch_->setName("switch");
    switch_->setVisible(false);
    
    //summon and recall button
    auto summonAndRecall = Sprite::create("res/UI/onScreenControl/summon.png");
    summonAndRecall->setPosition(Vec2(5.0 / 6.0 * screenSize.width, 3.0 / 4.0 * screenSize.height));
    summonAndRecall->setScale(1.4);
    summonAndRecall->setName("sr");
    
    addChild(switch_);
    addChild(jump);
    addChild(summonAndRecall);
    addChild(stick);
    addChild(stickLayer);
}

void OnScreenControllerLayer::switchSummonAndRecallButton(){
    auto sr = getChildByName<Sprite*>("sr");
    if (isSummoned){ // to recall
        Texture2D *texture = Director::getInstance()->getTextureCache()->addImage("res/UI/onScreenControl/recall.png");
        auto size = texture->getContentSize();
        auto frame = SpriteFrame::createWithTexture(texture, Rect(0, 0, size.width, size.height));
        sr->setSpriteFrame(frame);
        
        hasSwitch = true;
        auto switch_ = getChildByName<Sprite*>("switch");
        switch_->setVisible(true);
    }
    else {
        Texture2D *texture = Director::getInstance()->getTextureCache()->addImage("res/UI/onScreenControl/summon.png");
        auto size = texture->getContentSize();
        auto frame = SpriteFrame::createWithTexture(texture, Rect(0, 0, size.width, size.height));
        sr->setSpriteFrame(frame);
        
        hasSwitch = false;
        auto switch_ = getChildByName<Sprite*>("switch");
        switch_->setVisible(false);
    }
    
}
OnScreenControllerLayer::~OnScreenControllerLayer(){
    
}
