//
//  FirstSceneEvent.hpp
//  switch
//
//  Created by jiehong jiang on 8/1/17.
//
//

#ifndef FirstScene_hpp
#define FirstScene_hpp

#include "GameScene.hpp"
class FirstScene : public GameScene{
public:
    static FirstScene* create(TMXTiledMap* map, const b2Vec2& gravity);
    
    FirstScene(): GameScene() {};
    ~FirstScene(){};
    
    /**
     update function to override
     
     @param delta time step
     */
    virtual void update(float dt) override;
private:
    bool init(TMXTiledMap* map, const b2Vec2& gravity);
    
    /**
     designed to separate event makeing up
     */
    void registerEvent();
    void heroInit();
    /* event script */
    void openDoor(){
        log("open door");
    }
    
    void initUI();
};

#endif /* FirstScene_hpp */
