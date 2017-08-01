//
//  BaseScene.cpp
//  switch
//
//  Created by jiehong jiang on 7/27/17.
//
//

#include "BaseScene.hpp"
#include "GLES-Render.h"

BaseScene::BaseScene() : scenePhysics_(NULL), gameObjects_(), tiledMap(NULL){};
BaseScene::~BaseScene(){
    if(scenePhysics_) delete scenePhysics_;
};

BaseScene* BaseScene::create(TMXTiledMap* map, const b2Vec2& gravity, BaseContactListener* listener){
    auto ptr = new BaseScene();
    if (ptr->init(map, gravity, listener) && ptr) {
        ptr->autorelease();
        return ptr;
    }
    
    delete ptr;
    return ptr;
}

bool BaseScene::init(TMXTiledMap* map, const b2Vec2& gravity, BaseContactListener* listener){
    if (Scene::init()){
        scenePhysics_ = new ScenePhysics(gravity, listener);
        tiledMap = map;
        
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        map->setPosition(origin);
        addChild(tiledMap);
        scenePhysics_->createMapPhysicsOutline(map);
        
        GLESDebugDraw* debug = new GLESDebugDraw(PTM_RATIO);
        scenePhysics_->getWorld()->SetDebugDraw(debug);
        debug->SetFlags(debug->e_shapeBit | debug->e_pairBit);
        
        return true;
    }
    
    return false;
}

void BaseScene::update(float delta){
    scenePhysics_->step();
    for (auto object : gameObjects_){
        object->update();
    }
}
