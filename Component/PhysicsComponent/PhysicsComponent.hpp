//
//  PhysicsComponent.hpp
//  switch
//
//  Created by jiehong jiang on 7/25/17.
//
//

#ifndef PhysicsComponent_hpp
#define PhysicsComponent_hpp

#include "ObjectComponent.hpp"
#include "Box2D/Box2D.h"

class PhysicsComponent : ObjectComponent
{
public:
    PhysicsComponent(GameObject* container, b2Body* body = NULL, float moveSpeed = -1, float jumpSpeed = -1, b2Vec2 bodySize = b2Vec2_zero);
    /*    getter    */
    /**
     get current velocity of the body attached to the physicsComponent

     @return the velocity
     */
    b2Vec2 getCurrentVelocity() {return body_->GetLinearVelocity();}
    
    /**
     get the move speed of the object, default to -1

     @return move speed
     */
    float getMoveSpeed() {return moveSpeed_;}
    
    /**
     get the jump speed of the object ,default to -1

     @return jump speed
     */
    float getJumpSpeed() {return jumpSpeed_;}
    /**
     when floating (jumping or falling) object moves, it may touch a wall which makes its speed zero,
     this method tracks the state we expect rather than testing on velocity.x

     @return is moving left or right
     */
    bool isMoving(){return isMoving_;}
    
    /*    setter   */
    /**
     set the velocity of the body

     @param v the velocity
     */
    void setVelocity(const b2Vec2& v, bool adjustMovingState = true);
    
    void setMoving(bool moving) {isMoving_ = moving;}
private:
    
    bool  isMoving_;
    float moveSpeed_;
    float jumpSpeed_;
    b2Vec2 bodySize_;
    b2Body* body_;
};

#endif /* PhysicsComponent_hpp */
