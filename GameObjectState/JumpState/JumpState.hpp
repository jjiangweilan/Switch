//
//  JumpState.hpp
//  mayo
//
//  Created by jiehong jiang on 7/6/17.
//
//

#ifndef JumpState_hpp
#define JumpState_hpp
#include "BaseState.hpp"
#include "WalkState.hpp"
#include "GameObject.hpp"
class JumpState : public BaseState {
    
public:
    JumpState(std::string);
    virtual BaseState* commandHandler(GameObject* entity, commandType) override;
    virtual BaseState* observing(GameObject*) override;
    
    virtual void enter(GameObject* entity, commandType) override;
    virtual void leave(GameObject*) override;

};

#endif /* JumpState_hpp */
