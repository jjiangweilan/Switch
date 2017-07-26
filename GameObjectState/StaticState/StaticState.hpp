//
//  StaticState.hpp
//  switch
//
//  Created by jiehong jiang on 7/26/17.
//
//

#ifndef StaticState_hpp
#define StaticState_hpp

#include "BaseState.hpp"

class StaticState : BaseState {
    StaticState(std::string name) : BaseState(name){};
    virtual BaseState* commandHandler(GameObject* entity, commandType) override;
    virtual BaseState* observing(GameObject*) override;
    
    virtual void enter(GameObject* entity, commandType) override;
    virtual void leave(GameObject*) override;
};

#endif /* StaticState_hpp */
