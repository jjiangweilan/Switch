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
#include "SummonSystem.hpp"
#include "GameInfo.hpp"
SummonState::SummonState(std::string name) : BaseState(name){
    
}

BaseState* SummonState::commandHandler(GameObject* entity, commandType){
    return nullptr;
}
BaseState* SummonState::observing(GameObject* entity){
    auto animate = static_cast<Animate*>(entity->getActionByTag(1));
    
    if (animate == NULL){
        return &GameObjectStates::idleState;
    }
    return nullptr;
}

void SummonState::enter(GameObject* entity, commandType type){
    BaseState::enter(entity, type);
    auto scene = static_cast<GameScene*>(entity->getParent());
    entity->getPhysicsComponent()->setVelocity(b2Vec2_zero);
    if (entity->getName() == "bro")
        scene->getSummonSystem()->summon(sis);
    else
        scene->getSummonSystem()->summon(bro);
}
void SummonState::leave(GameObject* entity){
    
}
