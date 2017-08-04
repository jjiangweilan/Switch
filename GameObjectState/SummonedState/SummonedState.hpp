//
//  SummonedState.hpp
//  switch
//
//  Created by jiehong jiang on 8/4/17.
//
//

#ifndef SummonedState_hpp
#define SummonedState_hpp
#include "BaseState.hpp"
class SummonedState : public BaseState{
public:
    SummonedState(std::string name) : BaseState(name){};
    virtual BaseState* commandHandler(GameObject* entity, commandType) override;
    virtual BaseState* observing(GameObject*) override;
    
    virtual void enter(GameObject* entity, commandType) override;
    virtual void leave(GameObject*) override;
};

#endif /* SummonedState_hpp */
