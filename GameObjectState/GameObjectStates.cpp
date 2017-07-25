//
//  GameObjectState.cpp
//  mayo
//
//  Created by jiehong jiang on 7/6/17.
//
//

#include "GameObjectStates.hpp"
#include "IdleState.hpp"
#include "JumpState.hpp"
#include "WalkState.hpp"
#include "FallState.hpp"
#include "AttackState.hpp"

IdleState GameObjectStates::idleState = IdleState("idle");
JumpState GameObjectStates::jumpState = JumpState("jump");
WalkState GameObjectStates::walkState = WalkState("walk");
FallState GameObjectStates::fallState = FallState("fall");
AttackState GameObjectStates::attackState = AttackState("attack");
