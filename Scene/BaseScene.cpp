//
//  BaseScene.cpp
//  switch
//
//  Created by jiehong jiang on 7/27/17.
//
//

#include "BaseScene.hpp"

BaseScene::BaseScene() : scenePhysics_(NULL), gameObjects_(){};
BaseScene::~BaseScene(){
    if(scenePhysics_) delete scenePhysics_;
};

BaseScene* BaseScene::create(const b2Vec2& gravity, BaseContactListener* listener){
    auto ptr = new BaseScene();
    if (ptr->init(gravity, listener) && ptr) {
        ptr->autorelease();
        return ptr;
    }
    
    delete ptr;
    return ptr;
}

bool BaseScene::init(const b2Vec2& gravity, BaseContactListener* listener){
    if (Scene::init()){
        scenePhysics_ = new ScenePhysics(gravity, listener);
        return true;
    }
    
    return false;
}

void BaseScene::update(float delta){
    for (auto object : gameObjects_){
        object->update();
    }
}
