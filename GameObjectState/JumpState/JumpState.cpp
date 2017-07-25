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
    auto velocity = entity->getPhysicsComponent()->getCurrentVelocity();
    
    switch (type) {
        case goRight:
            entity->getPhysicsComponent()->setVelocity(b2Vec2(entity->getPhysicsComponent()->getMoveSpeed(), velocity.y));
            break;
        case goLeft:
            entity->getPhysicsComponent()->setVelocity(b2Vec2(-entity->getPhysicsComponent()->getMoveSpeed(), velocity.y));
            break;
        case leftRelease:
            entity->getPhysicsComponent()->setVelocity(b2Vec2(0, velocity.y));
            break;
        default:
            break;
    }
    
    return nullptr;
}

BaseState* JumpState::observing(GameObject* entity){
    auto velocity = entity->getPhysicsComponent()->getCurrentVelocity();
    if (entity->getPhysicsComponent()->getCurrentVelocity().y < -FLOAT_ACCURACY)return &GameObjectStates::fallState;
    if (entity->getPhysicsComponent()->isMoving() == true && ARE_SAME(velocity.x, 0)){
        if (!entity->isFlippedX()) entity->getPhysicsComponent()->setVelocity(b2Vec2(entity->getPhysicsComponent()->getMoveSpeed(), velocity.y));
        else entity->getPhysicsComponent()->setVelocity(b2Vec2(-entity->getPhysicsComponent()->getMoveSpeed(), velocity.y));
        
    }
    return nullptr;
}

void JumpState::enter(GameObject* entity, commandType type){
    BaseState::enter(entity, type);
    auto currentVelocity = entity->getPhysicsComponent()->getCurrentVelocity();
    entity->getPhysicsComponent()->setVelocity(b2Vec2(currentVelocity.x, entity->getPhysicsComponent()->getJumpSpeed()), false);
    
}
void JumpState::leave(GameObject* _entity){
    BaseState::leave(_entity);
}
