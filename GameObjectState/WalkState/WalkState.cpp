//
//  WalkState.cpp
//  mayo
//
//  Created by jiehong jiang on 7/6/17.
//
//

#include "WalkState.hpp"
#include "IdleState.hpp"
#include "FallState.hpp"
#include "AttackState.hpp"
WalkState::WalkState(std::string actiontType) : BaseState(actiontType){};
BaseState* WalkState::commandHandler(GameObject* entity, commandType type){
    if (type == jump){
        return &GameObjectStates::jumpState;
    }
    switch (type) {
        case goRight:
            entity->getPhysicsComponent()->setVelocity(b2Vec2(entity->getPhysicsComponent()->getMoveSpeed(), 0));
            break;
        case goLeft:
            entity->getPhysicsComponent()->setVelocity(b2Vec2(-entity->getPhysicsComponent()->getMoveSpeed(), 0));
            break;
        case leftRelease:
            return &GameObjectStates::idleState;
            break;
        case attack:
            return &GameObjectStates::attackState;
        default:
            break;
    }
    
    return nullptr;
}

BaseState* WalkState::observing(GameObject* entity){
    auto velocity = entity->getPhysicsComponent()->getCurrentVelocity();
    if (velocity.y < -FLOAT_ACCURACY)return &GameObjectStates::fallState;
    return nullptr;
}

void WalkState::enter(GameObject* entity, commandType type){
    BaseState::enter(entity, type);
    switch (type) {
        case goRight:
            entity->getPhysicsComponent()->setVelocity(b2Vec2(entity->getPhysicsComponent()->getMoveSpeed(), 0));
            break;
        case goLeft:
            entity->getPhysicsComponent()->setVelocity(b2Vec2(-entity->getPhysicsComponent()->getMoveSpeed(), 0));
        default:
            break;
    }
    
}
void WalkState::leave(GameObject* entity){
    BaseState::leave(entity);
}

