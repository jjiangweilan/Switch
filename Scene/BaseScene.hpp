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
#include "ScenePhysics.hpp"
#include "Box2D/Box2D.h"
#include "GameInfo.hpp"
USING_NS_CC;

class BaseScene : public Scene {
public:
    
    static BaseScene* create(const b2Vec2& gravity);
    
    BaseScene();
    ~BaseScene();
    
private:
    bool init(const b2Vec2& gravity);
    ScenePhysics scenePhysics;
};

#endif /* BaseScene_hpp */
