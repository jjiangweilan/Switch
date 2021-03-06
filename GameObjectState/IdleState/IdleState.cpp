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
#include "SummonState.hpp"
#include "RecallState.hpp"
#include "GameScene.hpp"
#include "SummonSystem.hpp"
#include "RecalledState.hpp"
#include "SummonFailedState.hpp"
#include "SummonedState.hpp"
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
        case summon:{
            auto scene = static_cast<GameScene*>(entity->getParent());
            auto physics = scene->getScenePhysics();
            std::string summonName = entity->getName() == "bro" ? "sis" : "bro";
            std::string currentName = entity->getName();
            float summonWidth = GameInfo::gameInfo["hero_information"][summonName.c_str()]["body_size"][0].GetFloat();
            bool hasCollision = false;
            auto hero = dynamic_cast<Hero*>(entity);
            assert(hero != NULL);
            b2Vec2 heroPos = hero->getPhysicsComponent()->getBodyPosition();
            
            float checkPointDistance = GameInfo::gameInfo["hero_information"][currentName.c_str()]["body_size"][0].GetFloat() / PTM_RATIO + 1; //width
            
            if (!entity->isFlippedX()){
                hasCollision = physics->hasCollisionInArea(b2Vec2(heroPos.x + checkPointDistance, heroPos.y), summonWidth / PTM_RATIO);
            }
            else {
                hasCollision = physics->hasCollisionInArea(b2Vec2(heroPos.x - checkPointDistance, heroPos.y), summonWidth / PTM_RATIO);
            }
            
            if (hasCollision){
                return nullptr;
            }
        }
            return &GameObjectStates::summonState;
            break;
        case recall:
            return &GameObjectStates::recallState;
            break;
        case recalled:
            return &GameObjectStates::recalledState;
            break;
        case switch_: {
            auto scene = static_cast<GameScene*>(entity->getParent());
            auto hero = entity->getName() == "bro" ? scene->getChildByName<Hero*>("sis") : scene->getChildByName<Hero*>("bro");
            scene->getSummonSystem()->switchTo(hero);
        }
            break;
        case summoned:
            return &GameObjectStates::summonedState;
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
