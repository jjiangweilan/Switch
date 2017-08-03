//
//  UILayer.cpp
//  mayo
//
//  Created by jiehong jiang on 6/26/17.
//
//

#include "UILayer.hpp"
UILayer* UILayer::create(const Size& layerSize){
    UILayer *pRet = new(std::nothrow) UILayer();
    if (pRet && pRet->init(layerSize))
    {
        pRet->autorelease();
        return pRet;
    }
    delete pRet;
    pRet = nullptr;
    return nullptr;
}

void UILayer::changeHealth(int health_){
    if (health_ < 0) health_ = 0;
    char newHealth[10] = {0};
    sprintf(newHealth, "%d", health_);
    health->setString(newHealth);
}

bool UILayer::init(const Size& size){
    Sprite::init();
    
    layerSize = size;
    Sprite::init();
    controllerLayer = OnScreenControllerLayer::create(layerSize);
    controllerLayer->setAnchorPoint(Vec2::ZERO);
    controllerLayer->setPosition(Vec2::ZERO);
    addChild(controllerLayer);
    
    //health bar
    health = Label::createWithCharMap("fonts/font_number.png", 40, 40, '0');
    health->setAnchorPoint(Vec2(0, 1));
    health->setPosition(Vec2(10, layerSize.height - 10));
    
    health->setString("100");
    addChild(health);
    
    //background
    
    return true;
}

UILayer::UILayer(){
}
UILayer::~UILayer(){
    
}


