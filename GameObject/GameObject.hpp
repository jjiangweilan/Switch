//
//  GameObject.hpp
//  switch
//
//  Created by jiehong jiang on 7/25/17.
//
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include "cocos2d.h"
#include "BaseState.hpp"
#include "GameObjectStates.hpp"
#include "PhysicsComponent.hpp"
#include "InputComponent.hpp"
#include "ControlComponent.hpp"
USING_NS_CC;

class GameObject : public Sprite {
public:
    /* setter */
    /**
     set physics component

     @param PhysicsComponent Physics Component
     */
    void setPhysicsComponent(PhysicsComponent* pc) {physicsComponent_ = pc;};
    
    /**
     set input component

     @param InputComponent Input Component
     */
    void setInputComponent(InputComponent* ic) {inputComponent_ = ic;}
    
    /**
     set control component

     @param ControlComponent control component
     */
    void setControlComponent(ControlComponent* cc) {controlComponent_ = cc;}
    
    /* getter */
    /**
     get physics component

     @return current physicsComponent
     */
    PhysicsComponent* getPhysicsComponent(){return physicsComponent_;}
    
    /**
     get input component

     @return current input component
     */
    InputComponent* getInputComponent(){return inputComponent_;}
    
    /**
     get control component

     @return current control component
     */
    ControlComponent* getControlComponent(){return controlComponent_;}
    
    /**
     get the object name for animation

     @return name
     */
    std::string getObjectName() {return objectName_;}
protected:
    BaseState* currentState_;
    
    GameObject(const std::string& name);
    ~GameObject();
private:
    PhysicsComponent* physicsComponent_;
    InputComponent* inputComponent_;
    ControlComponent* controlComponent_;
    
    std::string objectName_;
    
    friend ControlComponent;
};

#define FLOAT_ACCURACY 0.00000001
#define ARE_SAME(_x, _y) fabsf(_x - _y) < FLOAT_ACCURACY
#define EMPTY_CATELOGUE      0b0
#define HERO_CATELOGUE       0b1
#define ENEMY_CATELOGUE      0b10
#define SENSOR_CATELOGUE     0b100
#define GROUND_CATELOGUE     0b1000
#define ENEMY_ALERT_AREA     0b10000
#define ENEMY_ATTACK_AREA    0b100000
#define HERO_SENSOR_CATELOGUE (HERO_CATELOGUE | SENSOR_CATELOGUE)
#define NO_CONTACT_GROUP -99
#endif /* GameObject_hpp */
