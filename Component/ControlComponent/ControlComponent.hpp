//
//  ControlComponent.hpp
//  switch
//
//  Created by jiehong jiang on 7/25/17.
//
//

#ifndef ControlComponent_hpp
#define ControlComponent_hpp

#include "ObjectComponent.hpp"

//this class is designed for hero class, since in the game only hero can be controlled
class ControlComponent : public ObjectComponent
{
public:
    ControlComponent(GameObject* container);
    
    //    void connectingToControllerUI(ControllerUI);
    
    /**
     should be called when press left
     */
    void onLeft();
    
    /**
     should be called when press right
     */
    void onRight();
    
    /**
     should be called when press jump
     */
    void onJump();
    
    /**
     should be called when press summon

     @return return true if hero successfully enter summon state
     */
    bool onSummon();
    
    /**
     should be called when press switch
     */
    void onSwitch();
    
    /**
     should be called when press released on left space
     */
    void onLeftRelease();
    
    /**
     should be called when we want the container to be idle
     */
    void onIdle();
    
    /**
     shold be called when summon failed
     */
    void onSummonFailed();
    
    /**
     should be called when summoned
     */
    void onSummoned();
    
    /**
     shoule be called when recalling another hero

     @return true if hero successfully enter recall state
     */
    bool onRecall();
    
    /**
     should be called when recalled
     */
    void onRecalled();
};

#endif /* ControlComponent_hpp */
