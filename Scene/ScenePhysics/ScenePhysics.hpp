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
    ScenePhysics(b2Vec2 gravity, b2ContactListener* listener);
    ~ScenePhysics();
    /* getter */
    /**
     get the physics world
     
     @return the box2d physics world
     */
    b2World* const getWorld() {return world_;};
    
    /* setter */
    
    /* support */
    void step();
private:
    const float timeStep_;
    const int velocityIterations_;
    const int positionIterations_;
    b2World* world_;
};

#endif /*ScenePhysics_hpp */
