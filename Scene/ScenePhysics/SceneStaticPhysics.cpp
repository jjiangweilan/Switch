//
//  ScenePhysics.cpp
//  switch
//
//  Created by jiehong jiang on 7/27/17.
//
//

#include "SceneStaticPhysics.hpp"
#include "Box2D/Box2D.h"
typedef std::vector<b2Vec2> b2Points;

class SceneStaticPhysics {
public:
    /* getter */
    /**
     get the physics world

     @return the box2d physics world
     */
    b2World* getWorld() {return world_;};
    
    /* setter */
    
    /* support */
    
private:
    b2World* world_;
};
