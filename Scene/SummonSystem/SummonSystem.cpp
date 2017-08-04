//
//  SummonSystem.cpp
//  switch
//
//  Created by jiehong jiang on 8/3/17.
//
//

#include "SummonSystem.hpp"
#include "GameScene.hpp"
#include "GameInfo.hpp"
void SummonSystem::summon(HeroType type){
    Hero* current = type == bro ? sis_ : bro_;
    Hero* summon = type == bro ? bro_ : sis_;
    std::string currentName = type == bro ? "sis" : "bro";
    std::string summonName = type == bro ? "bro" : "sis";
    auto heroBody = reinterpret_cast<b2Body*>(current->getUserData());
    auto physics = scene_->getScenePhysics();
    
    b2Vec2 heroPos = heroBody->GetPosition();
    float checkPointDistance = GameInfo::gameInfo["hero_information"][currentName.c_str()]["body_size"][0].GetFloat() / PTM_RATIO + 1; //width
    
    float summonWidth = GameInfo::gameInfo["hero_information"][summonName.c_str()]["body_size"][0].GetFloat();
    
    //check collision
    bool hasCollision = false;
    if (!current->isFlippedX()){
        hasCollision = physics->hasCollisionInArea(b2Vec2(heroPos.x + checkPointDistance, heroPos.y), summonWidth / PTM_RATIO);
    }
    else {
        hasCollision = physics->hasCollisionInArea(b2Vec2(heroPos.x - checkPointDistance, heroPos.y), summonWidth / PTM_RATIO);
    }
    //test
    if (hasCollision){
        log("yes");
    }
    else {
        log("no");
    }
    //animation
    if(hasCollision == true)
        current->getControlComponent()->onSummonFailed();
    else{
        current->getControlComponent()->onSummon();
        summon->getControlComponent()->onSummoned();
    }
    
    //sprite and physics
    if(!current->isFlippedX())
        scene_->showHero(summon, Vec2((heroPos.x + checkPointDistance) * PTM_RATIO, heroPos.y * PTM_RATIO));
    else
        scene_->showHero(summon, Vec2((heroPos.x - checkPointDistance) * PTM_RATIO, heroPos.y * PTM_RATIO));
    
    switchTo(summon);
    
}
void SummonSystem::switchTo(Hero* hero){
    auto uiLayer = scene_->getUILayer();
    uiLayer->getControllerLayer()->setControlCompoenet(hero->getControlComponent());
}
void SummonSystem::recall(Hero* hero){
    scene_->hideHero(hero);
    
}
