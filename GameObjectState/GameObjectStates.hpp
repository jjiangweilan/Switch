//
//  GameObjectState.hpp
//  mayo
//
//  Created by jiehong jiang on 7/6/17.
//
//

#ifndef GameObjectStates_hpp
#define GameObjectStates_hpp

class IdleState;
class JumpState;
class WalkState;
class FallState;
class AttackState;

class GameObjectStates {
public:
    static IdleState idleState;
    static JumpState jumpState;
    static WalkState walkState;
    static FallState fallState;
    static AttackState attackState;
};

#endif /* GameObjectState_hpp */