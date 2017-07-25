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

GameObject::GameObject(){
    currentState_ = &GameObjectStates::idleState;
}
