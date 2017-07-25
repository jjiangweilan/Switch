//
//  WalkState.hpp
//  mayo
//
//  Created by jiehong jiang on 7/6/17.
//
//

#ifndef WalkState_hpp
#define WalkState_hpp
#include "BaseState.hpp"
#include "JumpState.hpp"
#include "GameObject.hpp"
class WalkState : public BaseState {
public:
    WalkState(std::string);
    virtual BaseState* commandHandler(GameObject* entity, commandType) override;
    virtual BaseState* observing(GameObject*) override;
    
    virtual void enter(GameObject* entity, commandType) override;
    virtual void leave(GameObject*) override;
};


#endif /* WalkState_hpp */
