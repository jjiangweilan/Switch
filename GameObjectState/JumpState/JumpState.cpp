//
//  JumpState.cpp
//  mayo
//
//  Created by jiehong jiang on 7/6/17.
//
//

#include "JumpState.hpp"
#include "IdleState.hpp"
#include "FallState.hpp"
JumpState::JumpState(std::string actiontType) : BaseState(actiontType){};
BaseState* JumpState::commandHandler(GameObject* entity, commandType type){
    auto velocity = entity->getCurrentVelocity();
    
    switch (type) {
        case goRight:
            entity->setVelocity(b2Vec2(entity->getWalkSpeed(), velocity.y));
            break;
        case goLeft:
            entity->setVelocity(b2Vec2(-entity->getWalkSpeed(), velocity.y));
            break;
        case leftRelease:
            entity->setVelocity(b2Vec2(0, velocity.y));
            break;
        default:
            break;
    }
    
    return nullptr;
}

BaseState* JumpState::observing(GameObject* entity){
    auto velocity = entity->getCurrentVelocity();
    if (entity->getCurrentVelocity().y < -FLOAT_ACCURACY)return &GameObjectStates::fallState;
    if (entity->isMovingRF() == true && ARE_SAME(velocity.x, 0)){
        if (!entity->isFlippedX()) entity->setVelocity(b2Vec2(entity->getWalkSpeed(), velocity.y));
        else entity->setVelocity(b2Vec2(-entity->getWalkSpeed(), velocity.y));
        
    }
    return nullptr;
}

void JumpState::enter(GameObject* entity, commandType type){
    BaseState::enter(entity, type);
    auto currentVelocity = entity->getCurrentVelocity();
    entity->setVelocity(b2Vec2(currentVelocity.x, entity->getJumpSpeed()), false);
    
}
void JumpState::leave(GameObject* _entity){
    BaseState::leave(_entity);
}
