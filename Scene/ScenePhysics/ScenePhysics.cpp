//
//  ScenePhysics.cpp
//  switch
//
//  Created by jiehong jiang on 7/27/17.
//
//

#include "ScenePhysics.hpp"


ScenePhysics::~ScenePhysics(){
    if(world_) delete world_;
}

