//
//  UILayer.hpp
//  mayo
//
//  Created by jiehong jiang on 6/26/17.
//
//

#ifndef UILayer_hpp
#define UILayer_hpp
#include "cocos2d.h"
#include "OnScreenControllerLayer.hpp"
USING_NS_CC;

enum LRState {
    onRight, onLeft, released
};
class UILayer : public Sprite {
private:
    
    Size layerSize;
    OnScreenControllerLayer* controllerLayer;
public:
    //all the sprites on UILayer
    Label* health;
    
    
    static UILayer* create(const Size&);
    virtual bool init() override;
    
    
    /*call this method with the amount to be displayed*/
    void changeHealth(int);
    
    //getter and setter
    OnScreenControllerLayer* getControllerLayer(){return controllerLayer;}
    UILayer(const Size&);
    ~UILayer();
};

#endif /* UILayer_hpp */
