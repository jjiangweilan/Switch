//
//  IdleState.cpp
//  mayo
//
//  Created by jiehong jiang on 7/6/17.
//
//

#include "IdleState.hpp"
#include "WalkState.hpp"
#include "AttackState.hpp"
IdleState::IdleState(std::string actiontType) : BaseState(actiontType){};
BaseState* IdleState::commandHandler(GameObject* entity, commandType type){
    switch (type) {
        case goLeft:
        case goRight:
            return &GameObjectStates::walkState;
            break;
        case jump:
            return &GameObjectStates::jumpState;
            break;
        case attack:
            return &GameObjectStates::attackState;
            break;
        default:
            break;
    }
    return nullptr;
}

BaseState* IdleState::observing(GameObject* entity){
    return nullptr;
}

void IdleState::enter(GameObject* entity, commandType type){
    BaseState::enter(entity, type);
    entity->getPhysicsComponent()->setVelocity(b2Vec2_zero);
}
void IdleState::leave(GameObject* _entity){
    BaseState::leave(_entity);
}
