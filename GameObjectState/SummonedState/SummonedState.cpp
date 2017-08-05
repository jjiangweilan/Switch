//
//  SummonedState.cpp
//  switch
//
//  Created by jiehong jiang on 8/4/17.
//
//

#include "SummonedState.hpp"
#include "GameObject.hpp"
#include "IdleState.hpp"
BaseState* SummonedState::commandHandler(GameObject* entity, commandType type){
    
    return nullptr;
}

BaseState* SummonedState::observing(GameObject* entity) {
    auto animate = static_cast<Animate*>(entity->getActionByTag(1));
    
    if (animate == NULL){
        return &GameObjectStates::idleState;
    }
    return nullptr;
}

void SummonedState::enter(GameObject* entity, commandType type) {
    BaseState::enter(entity, type);
    entity->getPhysicsComponent()->setVelocity(b2Vec2_zero);
}
void SummonedState::leave(GameObject*) {
    
}
