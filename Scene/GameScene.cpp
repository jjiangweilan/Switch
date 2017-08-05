//
//  GameScene.cpp
//  switch
//
//  Created by jiehong jiang on 7/27/17.
//
//

#include "GameScene.hpp"
#include "Hero.hpp"
#include "SummonSystem.hpp"
GameScene::GameScene() : scenePhysics_(NULL), summonSystem_(NULL), gameObjects_(), eventManager_(new EventManager), tiledMap_(NULL){};
GameScene::~GameScene(){
    if(scenePhysics_) delete scenePhysics_;
    if(eventManager_) delete eventManager_;
};

bool GameScene::init(TMXTiledMap* map, const b2Vec2& gravity){
    if (Scene::init()){
        tiledMap_ = map;
        
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        map->setPosition(origin);
        addChild(tiledMap_);
        
        return true;
    }
    
    return false;
}

void GameScene::initUI(){
    Size size = Director::getInstance()->getVisibleSize();
    uiLayer_ = UILayer::create(size);
    
    auto bro = getChildByName<Hero*>("bro");
    uiLayer_->setControlCompoenet(bro->getControlComponent());
    addChild(uiLayer_);
}

void GameScene::update(float delta){
    scenePhysics_->step();
    for (auto object : gameObjects_){
        object->update();
    }
}

void GameScene::initHero(){
    rapidjson::Value& broP = GameInfo::gameInfo["hero_information"]["bro"]["first_scene"]["init_pos"];
    rapidjson::Value& sisP = GameInfo::gameInfo["hero_information"]["sis"]["first_scene"]["init_pos"];
    
    Vec2 broPos(broP[0].GetInt(), broP[1].GetInt());
    Vec2 sisPos(sisP[0].GetInt(), sisP[1].GetInt());
    
    auto bro = Hero::create("egg_shell", HeroType::bro, createBroBody(broPos));
    bro->setName("bro");
    gameObjects_.push_back(bro);
    this->addChild(bro);
    
    auto sis = Hero::create("egg_shell", HeroType::sis, createSisBody(sisPos));
    sis->setName("sis");
    gameObjects_.push_back(sis);
    this->addChild(sis);
    
    hideHero(sis);
}

b2Body* GameScene::createBroBody(Vec2 pos){
    //bro
    rapidjson::Document& d = GameInfo::gameInfo;
    rapidjson::Value& broInfo = d["hero_information"]["bro"];
    
    //body
    b2BodyDef BodyDef;
    BodyDef.fixedRotation = true;
    BodyDef.position = b2Vec2(pos.x / PTM_RATIO, pos.y / PTM_RATIO);
    BodyDef.type = b2_dynamicBody;
    //fixture
    
    b2FixtureDef collisionArea;
    b2PolygonShape collisionAreaShape;
    collisionAreaShape.SetAsBox(broInfo["body_size"][0].GetFloat() / PTM_RATIO, broInfo["body_size"][1].GetFloat() / PTM_RATIO);
    collisionArea.density = broInfo["density"].GetFloat();
    collisionArea.shape = &collisionAreaShape;
    collisionArea.restitution = 0;
    collisionArea.friction = 0;
    collisionArea.filter.categoryBits = d["physics_category"]["hero"].GetInt();
    collisionArea.filter.maskBits = d["physics_category"]["wall"].GetInt();
    
    auto body = scenePhysics_->getWorld()->CreateBody(&BodyDef);
    body->CreateFixture(&collisionArea);
    return body;
}

b2Body* GameScene::createSisBody(Vec2 pos){
    b2BodyDef BodyDef;
    
    rapidjson::Value& sisInfo = GameInfo::gameInfo["hero_information"]["sis"];
    //body
    BodyDef.fixedRotation = true;
    BodyDef.position = b2Vec2(pos.x / PTM_RATIO, pos.y / PTM_RATIO);
    BodyDef.type = b2_dynamicBody;
    //fixture
    
    b2FixtureDef collisionArea;
    b2PolygonShape collisionAreaShape;
    collisionAreaShape.SetAsBox(sisInfo["body_size"][0].GetFloat() / PTM_RATIO, sisInfo["body_size"][1].GetFloat() / PTM_RATIO);
    collisionArea.density = sisInfo["density"].GetFloat();
    collisionArea.shape = &collisionAreaShape;
    collisionArea.restitution = 0;
    collisionArea.friction = 0;
    collisionArea.filter.categoryBits = GameInfo::gameInfo["physics_category"]["hero"].GetInt();
    collisionArea.filter.maskBits = GameInfo::gameInfo["physics_category"]["wall"].GetInt();
    
    auto sisBody = scenePhysics_->getWorld()->CreateBody(&BodyDef);
    sisBody->CreateFixture(&collisionArea);
    
    return sisBody;
}

void GameScene::hideHero(Hero* hero){
    //destroy body
    scenePhysics_->getWorld()->DestroyBody(reinterpret_cast<b2Body*>(hero->getUserData()));
    hero->getPhysicsComponent()->removeBody();
    
    //remove from game objects
    for (auto iter = gameObjects_.begin(); iter != gameObjects_.end();iter++){
        if (*iter == hero){
            gameObjects_.erase(iter);
            break;
        }
    }
    
    hero->setVisible(false);
}

void GameScene::showHero(Hero * hero, Vec2 pos){
    //add body
    if (hero->getName() == "bro"){
        hero->getPhysicsComponent()->setBody(createBroBody(pos));
    }
    else if (hero->getName() == "sis"){
        hero->getPhysicsComponent()->setBody(createSisBody(pos));
    }
    
    //add to game_objects
    hero->getControlComponent()->onIdle();
    gameObjects_.push_back(hero);
    
    hero->setVisible(true);
}

void GameScene::initSummonSystem(){
    auto bro = getChildByName<Hero*>("bro");
    auto sis = getChildByName<Hero*>("sis");
    
    assert(bro != NULL && sis != NULL);
    summonSystem_ = new SummonSystem(bro, sis, this);
}
