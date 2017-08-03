//
//  GameScene.cpp
//  switch
//
//  Created by jiehong jiang on 7/27/17.
//
//

#include "GameScene.hpp"
#include "Hero.hpp"
GameScene::GameScene() : scenePhysics_(NULL), gameObjects_(), gameEvent_v_(), tiledMap_(NULL){};
GameScene::~GameScene(){
    if(scenePhysics_) delete scenePhysics_;
    for (auto event : gameEvent_v_){
        delete event.second;
    }
};

bool GameScene::init(TMXTiledMap* map, const b2Vec2& gravity){
    if (Scene::init()){
        tiledMap_ = map;
        
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        map->setPosition(origin);
        addChild(tiledMap_);
        
        heroInit();
        return true;
    }
    
    return false;
}

void GameScene::initUI(){
    Size size = Director::getInstance()->getVisibleSize();
    uiLayer_ = UILayer::create(size);
    
    auto bro = static_cast<Hero*>( getChildByTag(GameInfo::gameInfo["hero_information"]["bro"]["tag"].GetInt()));
    uiLayer_->setControlCompoenet(bro->getControlComponent());
    addChild(uiLayer_);
}

void GameScene::update(float delta){
    scenePhysics_->step();
    for (auto object : gameObjects_){
        object->update();
    }
}

void GameScene::summon(){
    
}

void GameScene::heroInit(){
    rapidjson::Document& d = GameInfo::gameInfo;
    rapidjson::Value& broInfo = d["hero_information"]["bro"];
    //body
    b2BodyDef broBodyDef;
    broBodyDef.fixedRotation = true;
    broBodyDef.position = b2Vec2(broInfo["first_scene"]["init_pos"][0].GetInt() / PTM_RATIO, broInfo["first_scene"]["init_pos"][1].GetInt() / PTM_RATIO);
    broBodyDef.type = b2_dynamicBody;
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
    
    auto body = scenePhysics_->getWorld()->CreateBody(&broBodyDef);
    body->CreateFixture(&collisionArea);
    auto bro = Hero::create("egg_shell", HeroType::bro, body);
    bro->setTag(broInfo["tag"].GetInt());
    gameObjects_.push_back(bro);
    this->addChild(bro);
}

void GameScene::registerEvent(const std::string & name, int count, std::function<void()> scrpit){
    gameEvent_v_[name] = new GameEvent(count, scrpit);
}

void GameScene::checkEvent(const std::string & name){
    gameEvent_v_[name]->checkOneMission();
}
