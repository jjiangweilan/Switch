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
    
    static BaseScene* create(TMXTiledMap* map, const b2Vec2& gravity, BaseContactListener* listener);
    
    BaseScene();
    virtual ~BaseScene();
    
    /**
     update function to override

     @param delta time step
     */
    virtual void update(float delta);
    
    /**
     draw for debug

     @param renderer
     @param transform
     @param flags 
     */
    void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags){
        Scene::draw(renderer, transform, flags);
        
        scenePhysics_->getWorld()->DrawDebugData();
        
    }
private:
    bool init(TMXTiledMap* map, const b2Vec2& gravity, BaseContactListener* listener);
    
    ScenePhysics* scenePhysics_;
    GameObject_v gameObjects_;
    TMXTiledMap* tiledMap;
};

#endif /* BaseScene_hpp */
