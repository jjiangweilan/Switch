//
//  ScenePhysics.cpp
//  switch
//
//  Created by jiehong jiang on 7/27/17.
//
//

#include "ScenePhysics.hpp"
#include "QueryCallback.hpp"
ScenePhysics::ScenePhysics(b2Vec2 gravity, b2ContactListener* listener) : world_(new b2World(gravity)), timeStep_(1.0 / 60.0), velocityIterations_(3), positionIterations_(8){
    world_->SetContactListener(listener);
};

ScenePhysics::~ScenePhysics(){
    if(world_)delete world_;
}

void ScenePhysics::step(){
    world_->Step(timeStep_, velocityIterations_, positionIterations_);
}

void ScenePhysics::createMapPhysicsOutline(TMXTiledMap* map){
    b2BodyDef bodyDef;
    bodyDef.type = b2BodyType::b2_staticBody;
    bodyDef.position = b2Vec2_zero;
    physicsOutlineBody_ = world_->CreateBody(&bodyDef); //create body
    
    auto objectGroups = map->getObjectGroups();
    auto outlines = map->getObjectGroup(GameInfo::gameInfo["tiled_map"]["physics_outline_name"].GetString());
    
    for (auto line : outlines->getObjects()){
        b2FixtureDef fixture;
        b2ChainShape shape;
        fixture.filter.categoryBits = GameInfo::gameInfo["physics_category"]["wall"].GetInt();
        fixture.filter.maskBits = GameInfo::gameInfo["physics_category"]["hero"].GetInt();
        auto lineValueMap = line.asValueMap();

        Vec2 startPoint(lineValueMap["x"].asFloat(), lineValueMap["y"].asFloat());
        auto points = lineValueMap["polylinePoints"].asValueVector();
        auto b2Points = convertPointsToB2Points(map, startPoint, points);
        b2Vec2 vertex[b2Points.size()];
        for (int i = 0; i < b2Points.size(); i++){
            vertex[i] = b2Points[i];
        }
        
        shape.CreateChain(vertex, (int)b2Points.size());
        fixture.shape = &shape;
        physicsOutlineBody_->CreateFixture(&fixture);  //create fixture
    }
}

b2Points ScenePhysics::convertPointsToB2Points(TMXTiledMap* map, Vec2 startingPoint, ValueVector points){
    b2Points b2Points;
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    for (auto point : points){
        float b2x = (origin.x + startingPoint.x + point.asValueMap()["x"].asFloat()) / PTM_RATIO;
        float b2y = ((startingPoint.y - point.asValueMap()["y"].asFloat())) / PTM_RATIO;
        
        b2Points.push_back(b2Vec2(b2x, b2y));
    }
    
    return b2Points;
}

bool ScenePhysics::hasCollisionInArea(b2Vec2 center, float side){
    b2AABB aabb;
    QueryCallback callback;
    aabb.lowerBound.Set(center.x - side / 2.0, center.y - side / 2.0);
    aabb.upperBound.Set(center.x + side / 2.0, center.y  + side / 2.0);
    
    world_->QueryAABB(&callback, aabb);
    return !callback.isEmpty();
}

