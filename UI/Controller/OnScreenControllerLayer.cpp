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
    leftSpace_ = Sprite::create();
    leftSpace_->setAnchorPoint(Vec2::ZERO);
    leftSpace_->setPosition(Vec2::ZERO);
    leftSpace_->setContentSize(Size(screenSize_.width / 2, screenSize_.height));
    addChild(leftSpace_);
    
    auto touch = EventListenerTouchOneByOne::create();
    touch->onTouchBegan = [&](Touch* touch, Event* event) -> bool{
        auto pos = touch->getLocation();
        if (!leftSpace_->getBoundingBox().containsPoint(pos))return false;
        this->showStickLayer(pos);
        return true;
    };
    
    touch->onTouchMoved = [&](Touch* touch, Event* event) -> bool{
        
        Vec2 orinPos = stickLayer_->getPosition();
        Vec2 currPos = touch->getLocation();
        Vec2 prePos = touch->getPreviousLocation();
        Vec2 CODiff = currPos - orinPos;
        
        float radius = 50;
        float length = CODiff.length();
        
        stick_->setPosition(currPos);
        
        //move stick
        if (length >= radius){
            Vec2 CPDiff = currPos - prePos;
            Vec2 PODiff = prePos - orinPos;
            Vec2 delta = CPDiff + PODiff;
            float radio = (delta.length() - radius) / delta.length();
            delta *= radio;
            stickLayer_->setPosition(stickLayer_->getPosition() + delta);
        }
        
        auto stickRelativePos = stick_->getPosition() - stickLayer_->getPosition();
        
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
    
    leftSpace_->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touch, leftSpace_);
    
}

void OnScreenControllerLayer::addRightSpace(){
    rightSpace_ = Sprite::create();
    rightSpace_->setAnchorPoint(Vec2::ZERO);
    rightSpace_->setPosition(Vec2(screenSize_.width / 2, 0));
    rightSpace_->setContentSize(Size(screenSize_.width / 2, screenSize_.height));
    
    auto touch = EventListenerTouchOneByOne::create();
    addChild(rightSpace_);
    
    
    touch->onTouchBegan = [&](Touch* touch, Event* event) -> bool{
        auto jump = getChildByName<Sprite*>("jump");
        auto summonAndRecall = getChildByName<Sprite*>("sr");
        auto switch_ = getChildByName<Sprite*>("switch");
        
        auto pos = touch->getLocation();
        if (!rightSpace_->getBoundingBox().containsPoint(pos)) return false;
        //jump
        else if (jump->getBoundingBox().containsPoint(pos)){
            if(controlComponent_) controlComponent_->onJump();
        }
        //summon and recall
        else if (summonAndRecall->getBoundingBox().containsPoint(pos)){
            if(cooldown_ == false)startSwitchCoolDown();
            else return true;
            if(controlComponent_ && !isSummoned_){
                isSummoned_ = controlComponent_->onSummon();
                if (isSummoned_ == false) return true;
            }
            
            else if (controlComponent_ && isSummoned_) {
                isSummoned_ = !controlComponent_->onRecall();
            }
            
            
        }
        
        //switch
        else if (hasSwitch_ && switch_->getBoundingBox().containsPoint(pos)){if(controlComponent_)
            controlComponent_->onSwitch();
        }
        return true;
    };
    
    rightSpace_->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touch, rightSpace_);
    
    
}

void OnScreenControllerLayer::showStickLayer(const Vec2& pos){
    stickLayer_->setVisible(true);
    stick_->setVisible(true);
    stick_->setPosition(pos);
    stickLayer_->setPosition(pos);
}

void OnScreenControllerLayer::hideStickLayer(){
    stickLayer_->setVisible(false);
    stick_->setVisible(false);
}

void OnScreenControllerLayer::addRightController(){
    
}

void OnScreenControllerLayer::startSwitchCoolDown(){
    cooldown_ = true;
    CallFunc* callback = CallFunc::create([&](){
        switchSummonAndRecallButton();
        this->cooldown_ = false;
    });
    
    this->runAction(Sequence::create(DelayTime::create(1), callback,NULL));
}

OnScreenControllerLayer::OnScreenControllerLayer(const Size& screenSize) : screenSize_(screenSize){
    
    addLeftSpace();
    addRightSpace();
    addRightController();
    
    stickLayer_ = Sprite::create("res/UI/onScreenControl/stick_layer.png");
    stickLayer_->setScale(0.7);
    stick_ = Sprite::create("res/UI/onScreenControl/stick.png");
    stick_->setScale(0.7);
    stickLayer_->setVisible(false);
    stick_->setVisible(false);
    
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
    addChild(stick_);
    addChild(stickLayer_);
}

void OnScreenControllerLayer::switchSummonAndRecallButton(){
    auto sr = getChildByName<Sprite*>("sr");
    if (isSummoned_){ // to recall
        Texture2D *texture = Director::getInstance()->getTextureCache()->addImage("res/UI/onScreenControl/recall.png");
        auto size = texture->getContentSize();
        auto frame = SpriteFrame::createWithTexture(texture, Rect(0, 0, size.width, size.height));
        sr->setSpriteFrame(frame);
        
        hasSwitch_ = true;
        auto switch_ = getChildByName<Sprite*>("switch");
        switch_->setVisible(true);
    }
    else {
        Texture2D *texture = Director::getInstance()->getTextureCache()->addImage("res/UI/onScreenControl/summon.png");
        auto size = texture->getContentSize();
        auto frame = SpriteFrame::createWithTexture(texture, Rect(0, 0, size.width, size.height));
        sr->setSpriteFrame(frame);
        
        hasSwitch_ = false;
        auto switch_ = getChildByName<Sprite*>("switch");
        switch_->setVisible(false);
    }
    
}
OnScreenControllerLayer::~OnScreenControllerLayer(){
    
}
