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
     */
    void onSummon();
    
    /**
     should be called when press switch
     */
    void onSwitch();
};

#endif /* ControlComponent_hpp */
