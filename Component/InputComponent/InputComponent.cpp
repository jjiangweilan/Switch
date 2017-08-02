//
//  InputComponent.cpp
//  switch
//
//  Created by jiehong jiang on 7/25/17.
//
//

#include "InputComponent.hpp"
#include "GameObject.hpp"
#include "cocos2d.h"

USING_NS_CC;

InputComponent::InputComponent(GameObject* container) : ObjectComponent(container), scene_(scene_){
    auto touch = EventListenerTouchOneByOne::create();
    
    
    touch->onTouchBegan = [&](Touch* touch, Event* event) -> bool {
        
        return true;
    };
    
    touch->onTouchMoved = [&](Touch* touch, Event* event) -> bool {
        log("move");
        return true;
    };
    
    touch->onTouchEnded =
    touch->onTouchCancelled = [&](Touch* touch, Event* event) -> bool {
        log("end or cancel");
        return true;
    };
    
    container->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touch, container);
};
