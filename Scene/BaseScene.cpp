//
//  BaseScene.cpp
//  switch
//
//  Created by jiehong jiang on 7/27/17.
//
//

#include "BaseScene.hpp"

BaseScene::BaseScene() : scenePhysics(NULL){};
BaseScene::~BaseScene(){};

BaseScene* BaseScene::create(const b2Vec2& gravity){
    auto ptr = new BaseScene();
    if (ptr->init(gravity) && ptr) {
        ptr->autorelease();
        return ptr;
    }
    
    delete ptr;
    return ptr;
}

bool BaseScene::init(const b2Vec2& gravity){
    if (Scene::init()){
        scenePhysics = ScenePhysics(new b2World(gravity));
        return true;
    }
    
    return false;
}
