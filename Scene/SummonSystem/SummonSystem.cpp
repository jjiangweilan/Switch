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
    
    
    b2Vec2 heroPos = heroBody->GetPosition();
    float checkPointDistance = GameInfo::gameInfo["hero_information"][currentName.c_str()]["body_size"][0].GetFloat() / PTM_RATIO + 1; //width
    
    if(!current->isFlippedX())
        scene_->showHero(summon, Vec2((heroPos.x + checkPointDistance) * PTM_RATIO, heroPos.y * PTM_RATIO));
    else
        scene_->showHero(summon, Vec2((heroPos.x - checkPointDistance) * PTM_RATIO, heroPos.y * PTM_RATIO));
    
    summon->getControlComponent()->onSummoned();
    switchTo(summon);
    
}
void SummonSystem::switchTo(Hero* hero){
    bro_->getPhysicsComponent()->setVelocity(b2Vec2_zero);
    sis_->getPhysicsComponent()->setVelocity(b2Vec2_zero);
    auto uiLayer = scene_->getUILayer();
    uiLayer->getControllerLayer()->setControlCompoenet(hero->getControlComponent());
}
void SummonSystem::recall(Hero* hero){
    scene_->hideHero(hero);
    
}
