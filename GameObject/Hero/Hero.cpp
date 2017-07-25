//
//  Hero.cpp
//  switch
//
//  Created by jiehong jiang on 7/25/17.
//
//

#include "Hero.hpp"
#include "GameInfo.hpp"
Hero* Hero::create(const std::string& name,const b2Vec2& bodySize){
    Hero* ptr = new(std::nothrow) Hero(name, bodySize);
    if(ptr && ptr->init())
    {
        ptr->autorelease();
        return ptr;
    }
    delete ptr;
    return nullptr;
}

Hero::Hero(const std::string& name,const b2Vec2& bodySize) : GameObject(name){
    rapidjson::Document& d = GameInfo::gameInfo;
    
    GameObject::setPhysicsComponent(new PhysicsComponent(this));
    GameObject::setInputComponent(new InputComponent(this));
}

bool Hero::init(){
    return Sprite::init();
}
