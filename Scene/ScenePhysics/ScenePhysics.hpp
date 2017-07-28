//
//  ScenePhysics.hpp
//  switch
//
//  Created by jiehong jiang on 7/27/17.
//
//

#ifndef ScenePhysics_hpp
#define ScenePhysics_hpp
#include "ScenePhysics.hpp"
#include "Box2D/Box2D.h"
typedef std::vector<b2Vec2> b2Points;

class ScenePhysics {
public:
    ScenePhysics(b2World* world) : world_(world){};
    ~ScenePhysics();
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

#endif /*ScenePhysics_hpp */
