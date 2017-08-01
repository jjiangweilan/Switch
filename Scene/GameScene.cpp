//
//  GameScene.cpp
//  switch
//
//  Created by jiehong jiang on 7/27/17.
//
//

#include "GameScene.hpp"


GameScene::GameScene() : scenePhysics_(NULL), gameObjects_(), gameEvent_v_(), tiledMap_(NULL){};
GameScene::~GameScene(){
    if(scenePhysics_) delete scenePhysics_;
    for (auto event : gameEvent_v_){
        delete event.second;
    }
};

bool GameScene::init(TMXTiledMap* map, const b2Vec2& gravity){
    if (Scene::init()){
        tiledMap_ = map;
        
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        map->setPosition(origin);
        addChild(tiledMap_);
        
        return true;
    }
    
    return false;
}

void GameScene::update(float delta){
    scenePhysics_->step();
    for (auto object : gameObjects_){
        object->update();
    }
}

void GameScene::registerEvent(const std::string & name, int count, std::function<void()> scrpit){
    gameEvent_v_[name] = new GameEvent(count, scrpit);
}

void GameScene::checkEvent(const std::string & name){
    gameEvent_v_[name]->checkOneMission();
}
