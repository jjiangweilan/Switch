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
    
    void onLeft();
    void onRight();
    void onJump();
    void onSummon();
    void onSwitch();
};

#endif /* ControlComponent_hpp */
