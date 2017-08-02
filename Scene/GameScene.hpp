//
//  GameScene.hpp
//  switch
//
//  Created by jiehong jiang on 7/27/17.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp
#include "cocos2d.h"
#include "Box2D/Box2D.h"

#include "ScenePhysics.hpp"
#include "GameInfo.hpp"
#include "GameObject.hpp"
#include "GameEvent.hpp"
#include "InputComponent.hpp"
USING_NS_CC;
typedef std::vector<GameObject*> GameObject_v;
typedef std::map<std::string, GameEvent*> GameEvent_v;
class GameScene : public Scene {
public:
    GameScene();
    virtual ~GameScene();
    
    /**
     update function to override

     @param delta time step
     */
    virtual void update(float delta) override;
    
    /**
     draw for debug

     @param renderer
     @param transform
     @param flags 
     */
    void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags) override{
        Scene::draw(renderer, transform, flags);
        
        scenePhysics_->getWorld()->DrawDebugData();
    }
    
    /**
     register a event

     @param GameEvent the event
     */
protected:
    ScenePhysics* scenePhysics_;
    GameObject_v gameObjects_;
    InputComponent* inputComponent_;
    bool init(TMXTiledMap* map, const b2Vec2& gravity);
    /**
     add a new event recorder to game event map

     @param std::string& name of the event
     @param count the number of mission that need to accomplish
     @param std::function<void()> callback function when mission is completed
     */
    void registerEvent(const std::string&, int count, std::function<void()>);
    
    /**
     check one event with the name

     @param std::string& the name of the evnet
     */
    void checkEvent(const std::string&);
    
    
private:
    TMXTiledMap* tiledMap_;
    GameEvent_v gameEvent_v_;
};

#endif /* GameScene_hpp */
