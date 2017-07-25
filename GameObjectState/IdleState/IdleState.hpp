//
//  IdleState.hpp
//  mayo
//
//  Created by jiehong jiang on 7/6/17.
//
//

#ifndef IdleState_hpp
#define IdleState_hpp
#include "BaseState.hpp"
#include "JumpState.hpp"
#include "WalkState.hpp"
#include "GameObject.hpp"

class IdleState : public BaseState {
public:
    IdleState(std::string);
    virtual BaseState* commandHandler(GameObject* entity, commandType) override;
    virtual BaseState* observing(GameObject*) override;
    
    virtual void enter(GameObject* entity, commandType) override;
    virtual void leave(GameObject*) override;
};
#endif /* IdleState_hpp */
