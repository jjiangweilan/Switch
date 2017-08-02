//
//  FirstSceneEvent.cpp
//  switch
//
//  Created by jiehong jiang on 8/1/17.
//
//

#include "Hero.hpp"
#include "FirstScene.hpp"
#include "FirstSceneContactListener.hpp"
#include "GLES-Render.h"
FirstScene* FirstScene::create(TMXTiledMap* map, const b2Vec2& gravity){
    auto ptr = new FirstScene();
    if (ptr->init(map, gravity) && ptr) {
        ptr->autorelease();
        return ptr;
    }
    
    delete ptr;
    return ptr;
}

bool FirstScene::init(TMXTiledMap* map, const b2Vec2& gravity){
    GameScene::init(map, gravity);
    auto contactListener = new FirstSceneContactListener();
    scenePhysics_ = new ScenePhysics(gravity, contactListener);
    scenePhysics_->createMapPhysicsOutline(map);
    
    GLESDebugDraw* debug = new GLESDebugDraw(PTM_RATIO);
    scenePhysics_->getWorld()->SetDebugDraw(debug);
    debug->SetFlags(debug->e_shapeBit | debug->e_pairBit);
    
    registerEvent();
    
    //event test
    auto li = EventListenerTouchOneByOne::create();
    li->onTouchBegan = [&](Touch* touch, Event* event) -> bool{
        GameScene::checkEvent("open_door");
        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(li, this);
    
    heroInit();
    initUI();
    return true;
}

void FirstScene::registerEvent(){
    GameScene::registerEvent("open_door", 4, CC_CALLBACK_0(FirstScene::openDoor, this));
}

void FirstScene::heroInit(){
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

void FirstScene::initUI(){
    GameScene::initUI();
    
    auto controller = uiLayer_->getControllerLayer();
    auto bro = dynamic_cast<GameObject*>(this->getChildByTag(GameInfo::gameInfo["hero_information"]["bro"]["tag"].GetInt()));
    auto bro_controlCompoenet = bro->getControlComponent();
    controller->onRight = CC_CALLBACK_0(ControlComponent::onRight, bro_controlCompoenet);
    controller->onLeft = CC_CALLBACK_0(ControlComponent::onLeft, bro_controlCompoenet);
    
}

void FirstScene::update(float delta){
    GameScene::update(delta);
}

