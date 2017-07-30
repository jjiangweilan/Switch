//
//  ScenePhysics.cpp
//  switch
//
//  Created by jiehong jiang on 7/27/17.
//
//

#include "ScenePhysics.hpp"

ScenePhysics::ScenePhysics(b2Vec2 gravity, b2ContactListener* listener) : world_(new b2World(gravity)), timeStep_(1.0 / 60.0), velocityIterations_(3), positionIterations_(8){
    world_->SetContactListener(listener);
};

ScenePhysics::~ScenePhysics(){
    if(world_)delete world_;
}

void ScenePhysics::step(){
    world_->Step(timeStep_, velocityIterations_, positionIterations_);
}

