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
    //functional
    /**
     when summon button is pressed, on screen controller layer should show switch button
     */
    void    showSwitchButton();
    
    /**
     when recall button is pressed, on screen controller layer should hide switch button
     */
    void    hideSwitchButton();
    
    /**
     summon and recall button shouldn't appear on screen in the same time.
     */
    void    switchSummonAndRecallButton();
    //support
    void    addLeftSpace();
    void    addRightSpace();
    void    showStickLayer(const Vec2& pos);
    void    hideStickLayer();
    void    addRightController();
    
    /**
     switch needs cooldown to prevent continuous click
     */
    void    startSwitchCoolDown();
    
    //object
    ControlComponent*   controlComponent_;
    
    //button
    Sprite* leftSpace_;
    Sprite* rightSpace_;
    Sprite* stickLayer_;
    Sprite* stick_;
    
    //boolean
    bool    isSummoned_ = false;
    bool    hasSwitch_ = false;
    bool    cooldown_ = false;
    Size    screenSize_;
public:
    static  OnScreenControllerLayer* create(const Size& screenSize);
    
    OnScreenControllerLayer(const Size& screenSize);
    ~OnScreenControllerLayer();
    
    //change ui
    
    void    setControlCompoenet(ControlComponent* cc) {controlComponent_ = cc;}
};

#endif /* OnScreenController_hpp */
