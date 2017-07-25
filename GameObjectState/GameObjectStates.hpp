//
//  CharacterState.hpp
//  mayo
//
//  Created by jiehong jiang on 7/6/17.
//
//

#ifndef CharacterStates_hpp
#define CharacterStates_hpp

class IdleState;
class JumpState;
class WalkState;
class FallState;
class AttackState;
class CharacterStates {
public:
    static IdleState idleState;
    static JumpState jumpState;
    static WalkState walkState;
    static FallState fallState;
    static AttackState attackState;
};

#endif /* CharacterState_hpp */
