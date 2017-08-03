//
//  SummonState.cpp
//  switch
//
//  Created by jiehong jiang on 8/3/17.
//
//

#include "SummonState.hpp"
#include "GameObject.hpp"
#include "IdleState.hpp"
#include "GameScene.hpp"
SummonState::SummonState(std::string name) : BaseState(name){
    
}

BaseState* SummonState::commandHandler(GameObject* entity, commandType){
    return nullptr;
}
BaseState* SummonState::observing(GameObject* entity){
    auto animate = static_cast<Animate*>(entity->getActionByTag(1));
    unsigned int loop = animate->getAnimation()->getLoops();
    if (loop == 1){
        return &GameObjectStates::idleState;
    }
    return nullptr;
}

void SummonState::enter(GameObject* entity, commandType type){
    BaseState::enter(entity, type);
    auto scene = static_cast<GameScene*>(entity->getParent());
    scene->summon();
}
void SummonState::leave(GameObject* entity){
    
}
