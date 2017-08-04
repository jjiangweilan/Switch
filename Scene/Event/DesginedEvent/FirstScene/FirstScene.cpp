//
//  FirstSceneEvent.cpp
//  switch
//
//  Created by jiehong jiang on 8/1/17.
//
//

#include "Hero.hpp"
#include "FirstScene.hpp"
#include "FirstSceneContactListener.hpp"
#include "GLES-Render.h"
FirstScene* FirstScene::create(TMXTiledMap* map, const b2Vec2& gravity){
    auto ptr = new FirstScene();
    if (ptr->init(map, gravity) && ptr) {
        ptr->autorelease();
        return ptr;
    }
    
    delete ptr;
    return ptr;
}

bool FirstScene::init(TMXTiledMap* map, const b2Vec2& gravity){
    GameScene::init(map, gravity);
    auto contactListener = new FirstSceneContactListener();
    scenePhysics_ = new ScenePhysics(gravity, contactListener);
    scenePhysics_->createMapPhysicsOutline(map);
    
    GLESDebugDraw* debug = new GLESDebugDraw(PTM_RATIO);
    scenePhysics_->getWorld()->SetDebugDraw(debug);
    debug->SetFlags(debug->e_shapeBit | debug->e_pairBit);
    
    registerEvent();
    
    //event test
    auto li = EventListenerTouchOneByOne::create();
    li->onTouchBegan = [&](Touch* touch, Event* event) -> bool{
        GameScene::checkEvent("open_door");
        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(li, this);
    
    //
    initHero();
    initUI();
    initSummonSystem();
    return true;
}

void FirstScene::registerEvent(){
    GameScene::registerEvent("open_door", 4, CC_CALLBACK_0(FirstScene::openDoor, this));
}



void FirstScene::update(float delta){
    GameScene::update(delta);
}

