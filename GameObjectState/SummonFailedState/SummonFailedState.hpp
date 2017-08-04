//
//  SummonFailedState.hpp
//  switch
//
//  Created by jiehong jiang on 8/4/17.
//
//

#ifndef SummonFailedState_hpp
#define SummonFailedState_hpp
#include "BaseState.hpp"

class SummonFailedState : public BaseState {
public:
    SummonFailedState(std::string name) : BaseState(name){};
    virtual BaseState* commandHandler(GameObject* entity, commandType) override;
    virtual BaseState* observing(GameObject*) override;
    
    virtual void enter(GameObject* entity, commandType) override;
    virtual void leave(GameObject*) override;
};
#endif /* SummonFailedState_hpp */
