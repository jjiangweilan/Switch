//
//  Hero.cpp
//  switch
//
//  Created by jiehong jiang on 7/25/17.
//
//

#include "Hero.hpp"
#include "GameInfo.hpp"

Hero* Hero::create(const std::string& name, HeroType heroType, b2Body* body){
    Hero* ptr = new(std::nothrow) Hero(name, heroType, body);
    if(ptr && ptr->init())
    {
        ptr->autorelease();
        return ptr;
    }
    
    delete ptr;
    return nullptr;
}

Hero::Hero(const std::string& name, HeroType heroType, b2Body* body) : GameObject(name){
    rapidjson::Document& d = GameInfo::gameInfo;
    
    if (heroType == bro){
        rapidjson::Value& broInfo = d["hero_information"]["bro"];
        body->SetUserData(this);
        GameObject::setPhysicsComponent(new PhysicsComponent(this, body, broInfo["move_speed"].GetInt(), broInfo["jump_speed"].GetInt()));
    
        GameObject::setControlComponent(new ControlComponent(this));
        
        currentState_->enter(this, idle);
    }
}

Hero::~Hero(){
    if(collisionAreaShape)delete collisionAreaShape;
}

void Hero::update(){
    GameObject::update();
}

bool Hero::init(){
    return Sprite::init();
    
}
