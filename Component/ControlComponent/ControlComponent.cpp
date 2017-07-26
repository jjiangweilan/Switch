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

void ControlComponent::onSummon(){
    BaseState* newState = container_->currentState_->commandHandler(container_, summon);
    if (newState){
        container_->currentState_->leave(container_);
        container_->currentState_ = newState;
        container_->currentState_->enter(container_, summon);
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
