//
//  ControlComponent.cpp
//  switch
//
//  Created by jiehong jiang on 7/25/17.
//
//

#include "ControlComponent.hpp"
#include "GameObject.hpp"
ControlComponent::ControlComponent(GameObject* container): ObjectComponent(container) {}

void ControlComponent::onLeft(){
    BaseState* newState = container_->currentState_->commandHandler(container_, goLeft);
    if (newState){
        container_->currentState_->leave(container_);
        container_->currentState_ = newState;
        container_->currentState_->enter(container_, goLeft);
    }
}

void ControlComponent::onRight(){
    BaseState* newState = container_->currentState_->commandHandler(container_, goRight);
    if (newState){
        container_->currentState_->leave(container_);
        container_->currentState_ = newState;
        container_->currentState_->enter(container_, goRight);
    }
}


void ControlComponent::onJump(){
    BaseState* newState = container_->currentState_->commandHandler(container_, jump);
    if (newState){
        container_->currentState_->leave(container_);
        container_->currentState_ = newState;
        container_->currentState_->enter(container_, jump);
    }
}

bool ControlComponent::onSummon(){
    BaseState* newState = container_->currentState_->commandHandler(container_, summon);
    if (newState){
        container_->currentState_->leave(container_);
        container_->currentState_ = newState;
        container_->currentState_->enter(container_, summon);
    }
    if (newState)return true;
    return false;
}

void ControlComponent::onIdle(){
    BaseState* newState = container_->currentState_->commandHandler(container_, idle);
    if (newState){
        container_->currentState_->leave(container_);
        container_->currentState_ = newState;
        container_->currentState_->enter(container_, idle);
    }
}

void ControlComponent::onSwitch(){
    BaseState* newState = container_->currentState_->commandHandler(container_, switch_);
    if (newState){
        container_->currentState_->leave(container_);
        container_->currentState_ = newState;
        container_->currentState_->enter(container_, switch_);
    }
}

void ControlComponent::onLeftRelease(){
    BaseState* newState = container_->currentState_->commandHandler(container_, leftRelease);
    if (newState){
        container_->currentState_->leave(container_);
        container_->currentState_ = newState;
        container_->currentState_->enter(container_, leftRelease);
    }
}

void ControlComponent::onSummonFailed(){
    BaseState* newState = container_->currentState_->commandHandler(container_, summonFailed);
    if (newState){
        container_->currentState_->leave(container_);
        container_->currentState_ = newState;
        container_->currentState_->enter(container_, summonFailed);
    }
}

void ControlComponent::onSummoned(){
    BaseState* newState = container_->currentState_->commandHandler(container_, summoned);
    if (newState){
        container_->currentState_->leave(container_);
        container_->currentState_ = newState;
        container_->currentState_->enter(container_, summoned);
    }
}

bool ControlComponent::onRecall(){
    BaseState* newState = container_->currentState_->commandHandler(container_, recall);
    if (newState){
        container_->currentState_->leave(container_);
        container_->currentState_ = newState;
        container_->currentState_->enter(container_, recall);
    }
    
    if(newState)return true;
    else return false;
}

void ControlComponent::onRecalled(){
    BaseState* newState = container_->currentState_->commandHandler(container_, recalled);
    if (newState){
        container_->currentState_->leave(container_);
        container_->currentState_ = newState;
        container_->currentState_->enter(container_, recalled);
    }
}
