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
#include "SummonState.hpp"
#include "RecallState.hpp"
#include "GameScene.hpp"
#include "SummonSystem.hpp"
#include "RecalledState.hpp"
#include "SummonFailedState.hpp"
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

