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
#include "Hero.hpp"
USING_NS_CC;

class OnScreenControllerLayer : public Sprite{
private:
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
    
    /*callback functions which respond to onScreen operations*/
    std::function<void()> onRight; //on stick right
    std::function<void()> onLeft; //on stick left
    std::function<void()> onLeftRelease; // release on layer
    std::function<void()> onRightRelease; // release on layer
    std::function<void()> onPressJump;
    std::function<void()> onPressAttack;
    std::function<void()> onUp;
    std::function<void()> onDown;
    std::function<void()> onPressSummon;
    std::function<void()> onPressSwitch;
    
    //change ui
    void changeSummonAndRecallButton();

};

#endif /* OnScreenController_hpp */
