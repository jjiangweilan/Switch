//
//  SummonFailedState.cpp
//  switch
//
//  Created by jiehong jiang on 8/4/17.
//
//

#include "SummonFailedState.hpp"
#include "GameObject.hpp"
#include "IdleState.hpp"
BaseState* SummonFailedState::commandHandler(GameObject* entity, commandType){
    return nullptr;
}

BaseState* SummonFailedState::observing(GameObject* entity){
    auto animate = static_cast<Animate*>(entity->getActionByTag(1));
    
    if (animate == NULL){
        return &GameObjectStates::idleState;
    }
    return nullptr;
}

void SummonFailedState::enter(GameObject* entity, commandType type){
    BaseState::enter(entity, type);
}

void SummonFailedState::leave(GameObject*){
    
}
