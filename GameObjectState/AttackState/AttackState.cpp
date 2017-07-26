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
    BaseState::enter(entity, type);
}
void AttackState::leave(GameObject* entity){
    BaseState::leave(entity);
    entity->setAnchorPoint(Vec2(0.5, 0.5));
}
