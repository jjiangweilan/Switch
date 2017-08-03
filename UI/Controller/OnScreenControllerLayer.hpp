//
//  OnScreenController.hpp
//  mayo
//
//  Created by jiehong jiang on 7/9/17.
//
//

#ifndef OnScreenControllerLayer_hpp
#define OnScreenControllerLayer_hpp

#include "cocos2d.h"
#include "ControlComponent.hpp"
USING_NS_CC;

class OnScreenControllerLayer : public Sprite{
private:
    //object
    ControlComponent* controlComponent_;
    
    //button
    Sprite* leftSpace;
    Sprite* rightSpace;
    Sprite* jump;
    Sprite* switch_;
    Sprite* summon;
    bool isSummonButton = true;
    
    Sprite* stickLayer;
    Sprite* stick;
    
    Size screenSize;
    
    void addLeftSpace();
    void addRightSpace();
    void showStickLayer(const Vec2& pos);
    void hideStickLayer();
    void addRightController();
public:
    static OnScreenControllerLayer* create(const Size& screenSize);
    
    OnScreenControllerLayer(const Size& screenSize);
    ~OnScreenControllerLayer();
    
    //change ui
    void changeSummonAndRecallButton();
    void setControlCompoenet(ControlComponent* cc) {controlComponent_ = cc;}
};

#endif /* OnScreenController_hpp */
