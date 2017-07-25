//
//  PhysicsComponent.cpp
//  switch
//
//  Created by jiehong jiang on 7/25/17.
//
//

#include "PhysicsComponent.hpp"
#include "GameObject.hpp"
PhysicsComponent::PhysicsComponent(GameObject* container, b2Body* body, float moveSpeed, float jumpSpeed, b2Vec2 bodySize) : ObjectComponent(container)
{
    isMoving_ = false;
    moveSpeed_ = moveSpeed;
    body_= body;
    jumpSpeed_ = jumpSpeed;
    bodySize_ = bodySize;
}

void PhysicsComponent::setVelocity(const b2Vec2& v, bool adjustMovingState)
{
    if(body_)
    {
        body_->SetLinearVelocity(v);
        if (adjustMovingState){
            if (ARE_SAME(v.x, 0)) setMoving(false);
            else setMoving(true);
            if(v.x > FLOAT_ACCURACY)container_->setFlippedX(false);
            else if(v.x < -FLOAT_ACCURACY)container_->setFlippedX(true);
        }
    }
}
