//
//  ScenePhysics.hpp
//  switch
//
//  Created by jiehong jiang on 7/27/17.
//
//

#ifndef ScenePhysics_hpp
#define ScenePhysics_hpp
#include "Box2D/Box2D.h"
#include "GameInfo.hpp"
USING_NS_CC;
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
    /**
     take the tiled map instance and create outline based on the infomation from the tiled map

     @param TMXTiledMap the tiled map
     */
    void createMapPhysicsOutline(TMXTiledMap*);
    
    /**
     this method is used to convert points based on tile map to b2 coordinate system Points are based on tilemap coordinate system

     @param cocos2d::Vec2 startingPoint
     @param cocos2d::ValueVector points based on the tile
     @return points based on b2 coordinate system
     */
    b2Points convertPointsToB2Points(TMXTiledMap* map, cocos2d::Vec2, cocos2d::ValueVector);
    
    /**
     check if there is a fixture within in the area

     @param center the center of the area
     @param side the side length of the area
     @return whether there is a body
     */
    bool hasCollisionInArea(b2Vec2 center, float side);
private:
    const float timeStep_;
    const int velocityIterations_;
    const int positionIterations_;
    b2World* world_;
    b2Body* physicsOutlineBody_;
};

#endif /*ScenePhysics_hpp */
