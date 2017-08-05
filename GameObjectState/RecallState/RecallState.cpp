//
//  RecallState.cpp
//  switch
//
//  Created by jiehong jiang on 8/5/17.
//
//

#include "RecallState.hpp"
#include "IdleState.hpp"
#include "GameScene.hpp"
#include "SummonSystem.hpp"
BaseState* RecallState::commandHandler(GameObject* entity, commandType){
    return nullptr;
}
BaseState* RecallState::observing(GameObject* entity) {
    auto animate = static_cast<Animate*>(entity->getActionByTag(1));
    
    if (animate == NULL){
        return &GameObjectStates::idleState;
    }
    return nullptr;
}

void RecallState::enter(GameObject* entity, commandType type){
    BaseState::enter(entity, type);
    entity->getPhysicsComponent()->setVelocity(b2Vec2_zero);
    auto scene = static_cast<GameScene*>(entity->getParent());
    auto recalledHero = entity->getName() == "bro" ? scene->getChildByName<Hero*>("sis") : scene->getChildByName<Hero*>("bro");
    
    recalledHero->getControlComponent()->onRecalled();
}

void RecallState::leave(GameObject*){
    
}
