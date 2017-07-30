//
//  GameObject.cpp
//  switch
//
//  Created by jiehong jiang on 7/25/17.
//
//

#include "GameObject.hpp"
#include "IdleState.hpp"
GameObject::~GameObject(){
    if(physicsComponent_)delete physicsComponent_;
    if(inputComponent_)delete inputComponent_;
    if(controlComponent_)delete controlComponent_;
}

GameObject::GameObject(const std::string& name) : objectName_(name){
    currentState_ = &GameObjectStates::idleState;
}

void GameObject::update(){
    if(physicsComponent_){
    auto bodyPos = physicsComponent_->getBodyPosition();
    setPosition(Vec2(bodyPos.x * PTM_RATIO, bodyPos.y * PTM_RATIO));
    }
}
