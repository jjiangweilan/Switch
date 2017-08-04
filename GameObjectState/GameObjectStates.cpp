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
#include "SummonState.hpp"
#include "SummonedState.hpp"
#include "RecallState.hpp"
#include "RecalledState.hpp"

IdleState GameObjectStates::idleState("idle");
JumpState GameObjectStates::jumpState("jump");
WalkState GameObjectStates::walkState("walk");
FallState GameObjectStates::fallState("fall");
AttackState GameObjectStates::attackState("attack");
SummonState GameObjectStates::summonState("summon");
SummonedState GameObjectStates::summonedState("summoned");
RecallState GameObjectStates::recallState("recall");
RecalledState GameObjectStates::recalledState("recalled");
