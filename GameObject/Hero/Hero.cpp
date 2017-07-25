//
//  Hero.cpp
//  switch
//
//  Created by jiehong jiang on 7/25/17.
//
//

#include "Hero.hpp"
#include "GameInfo.hpp"

Hero* Hero::create(HeroType heroType, b2Body* body){
    Hero* ptr = new(std::nothrow) Hero(heroType, body);
    if(ptr && ptr->init())
    {
        ptr->autorelease();
        return ptr;
    }
    delete ptr;
    return nullptr;
}

Hero::Hero(HeroType heroType, b2Body* body) : GameObject(){
    rapidjson::Document& d = GameInfo::gameInfo;
    
    if (heroType == bro){
        rapidjson::Value& broInfo = d["hero_information"]["bro"];
        GameObject::setPhysicsComponent(new PhysicsComponent(this, body, broInfo["move_speed"].GetInt(), broInfo["jump_speed"].GetInt()));
        GameObject::setInputComponent(new InputComponent(this));
    }
}

Hero::~Hero(){
    if(collisionAreaShape)delete collisionAreaShape;
}

std::vector<b2FixtureDef> Hero::createDefaultBroFixtureDef(){
    rapidjson::Document& d = GameInfo::gameInfo;
    rapidjson::Value& broInfo = d["hero_information"]["bro"];
    std::vector<b2FixtureDef> fixtures;
    b2FixtureDef collisionArea;
    
    collisionAreaShape = new b2PolygonShape();
    collisionAreaShape->SetAsBox(broInfo["body_size"][0].GetFloat(), broInfo["body_size"][1].GetFloat());
    collisionArea.density = 2;
    collisionArea.shape = collisionAreaShape;
    collisionArea.restitution = 0;
    collisionArea.friction = 0;
    collisionArea.filter.categoryBits = HERO_CATELOGUE;
    
    fixtures.push_back(collisionArea);
    
    return fixtures;
}

std::vector<b2FixtureDef> Hero::createDefaultSisFixtureDef(){
    rapidjson::Document& d = GameInfo::gameInfo;
    rapidjson::Value& broInfo = d["hero_information"]["sis"];
    std::vector<b2FixtureDef> fixtures;
    b2FixtureDef collisionArea;
    
    collisionAreaShape = new b2PolygonShape();
    collisionAreaShape->SetAsBox(broInfo["body_size"][0].GetFloat(), broInfo["body_size"][1].GetFloat());
    collisionArea.density = 2;
    collisionArea.shape = collisionAreaShape;
    collisionArea.restitution = 0;
    collisionArea.friction = 0;
    collisionArea.filter.categoryBits = HERO_CATELOGUE;
    
    fixtures.push_back(collisionArea);
    
    return fixtures;
}

void Hero::update(float delta){
    b2Vec2 b2Pos = getPhysicsComponent()->getBodyPosition();
    this->setPosition(Vec2(b2Pos.x * PTM_RATIO, b2Pos.y * PTM_RATIO));
}

bool Hero::init(){
    return Sprite::init();
}
