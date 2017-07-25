//
//  FallState.cpp
//  mayo
//
//  Created by jiehong jiang on 7/7/17.
//
//

#include "FallState.hpp"
#include "GameObject.hpp"
#include "IdleState.hpp"
#include "WalkState.hpp"
BaseState* FallState::commandHandler(GameObject* entity, commandType command){
    auto velocity = entity->getCurrentVelocity();
    
    switch (command) {
        case goRight:
            entity->setVelocity(b2Vec2(entity->getWalkSpeed(), velocity.y));
            break;
        case goLeft:
            entity->setVelocity(b2Vec2(-entity->getWalkSpeed(), velocity.y));
            break;
        case leftRelease:
            entity->setVelocity(b2Vec2(0, velocity.y));
            break;
            break;
        default:
            break;
    }
    return nullptr;
}

BaseState* FallState::observing(GameObject* entity){
    if (ARE_SAME(entity->getCurrentVelocity().x, 0) && ARE_SAME(entity->getCurrentVelocity().y, 0)) return &GameObjectStates::idleState;
    
    if (!(ARE_SAME(entity->getCurrentVelocity().x, 0)) && ARE_SAME(entity->getCurrentVelocity().y, 0)) return &GameObjectStates::walkState;
    
    auto velocity = entity->getCurrentVelocity();
    if (entity->isMovingRF() == true && ARE_SAME(velocity.x, 0)){
        if (!entity->isFlippedX()) entity->setVelocity(b2Vec2(entity->getWalkSpeed(), velocity.y));
        else entity->setVelocity(b2Vec2(-entity->getWalkSpeed(), velocity.y));
        
    }
    return nullptr;
}

void FallState::enter(GameObject* entity, commandType type){
    BaseState::enter(entity, type);
}
void FallState::leave(GameObject* entity){
    BaseState::leave(entity);
    
}
