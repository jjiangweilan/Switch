//
//  BaseSate.cpp
//  mayo
//
//  Created by jiehong jiang on 7/6/17.
//
//

#include "BaseState.hpp"
#include "GameObject.hpp"

BaseState::BaseState(std::string actionType){this->actionType = actionType;}
void BaseState::enter(GameObject * entity, commandType type){
    entity->stopActionByTag(1);
    
    std::string animationName = entity->getObjectName() + "_" + actionType;
    auto animation = AnimationCache::getInstance()->getAnimation(animationName);
    if (animation == nullptr)return;
    animation->setLoops(-1);
    
    auto animated = Animate::create(animation);
    animated->setTag(1);
    
    entity->runAction(animated);
}

void BaseState::leave(GameObject* _entity){
    
}
