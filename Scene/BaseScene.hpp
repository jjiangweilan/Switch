//
//  BaseScene.hpp
//  switch
//
//  Created by jiehong jiang on 7/27/17.
//
//

#ifndef BaseScene_hpp
#define BaseScene_hpp
#include "cocos2d.h"
#include "Box2D/Box2D.h"

#include "ScenePhysics.hpp"
#include "GameInfo.hpp"
#include "GameObject.hpp"
#include "BaseContactListener.hpp"
USING_NS_CC;
typedef std::vector<GameObject*> GameObject_v;

class BaseScene : public Scene {
public:
    
    static BaseScene* create(const b2Vec2& gravity, BaseContactListener* listener);
    
    BaseScene();
    virtual ~BaseScene();
    
    /**
     update function to override

     @param delta time step
     */
    virtual void update(float delta);
private:
    bool init(const b2Vec2& gravity, BaseContactListener* listener);
    
    ScenePhysics* scenePhysics_;
    GameObject_v gameObjects_;
};

#endif /* BaseScene_hpp */
