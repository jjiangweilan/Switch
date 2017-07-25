//
//  AttackState.cpp
//  mayo
//
//  Created by jiehong jiang on 7/8/17.
//
//

#include "AttackState.hpp"
#include "GameObject.hpp"
#include "WalkState.hpp"
BaseState* AttackState::commandHandler(GameObject* entity, commandType type){
    switch (type) {
        case goLeft:
        case goRight:
            return &GameObjectStates::walkState;
            break;
            
        default:
            break;
    }
    return nullptr;
}

BaseState* AttackState::observing(GameObject* entity){
    return nullptr;
}

void AttackState::enter(GameObject* entity, commandType type){
    entity->getPhysicsComponent()->setVelocity(b2Vec2_zero);
    
    entity->stopActionByTag(1);
    char number = {0};
    if (type == attack_1)number = '1';
    else if (type == attack_2)number = '2';
    else if (type == attack_3)number = '3';
    else throw std::invalid_argument("no such attack type");
    
    std::string animationName = entity->getName() + "_" + actionType + "_" + number;
    auto animation = AnimationCache::getInstance()->getAnimation(animationName);
    if (animation == nullptr)return;
    animation->setLoops(-1);
    
    auto animated = Animate::create(animation);
    animated->setTag(1);
    
    entity->runAction(animated);
}
void AttackState::leave(GameObject* entity){
    BaseState::leave(entity);
    entity->setAnchorPoint(Vec2(0.5, 0.5));
}
