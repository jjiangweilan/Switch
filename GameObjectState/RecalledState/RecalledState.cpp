//
//  RecalledState.cpp
//  switch
//
//  Created by jiehong jiang on 8/5/17.
//
//

#include "RecalledState.hpp"
#include "GameScene.hpp"
#include "SummonSystem.hpp"
#include "IdleState.hpp"
BaseState* RecalledState::commandHandler(GameObject* entity, commandType type){
    switch (type) {
        case idle:
            return &GameObjectStates::idleState;
            break;
        default:
            break;
    }
    return nullptr;
}
BaseState* RecalledState::observing(GameObject* entity) {
    auto animate = static_cast<Animate*>(entity->getActionByTag(1));
    
    if (animate == NULL){
        auto scene = static_cast<GameScene*>(entity->getParent());
        auto hero = dynamic_cast<Hero*>(entity);
        if (hero)scene->getSummonSystem()->recall(hero);
    }
    return nullptr;
}

void RecalledState::enter(GameObject* entity, commandType type){
    BaseState::enter(entity, type);
}

void RecalledState::leave(GameObject*){
    
}
