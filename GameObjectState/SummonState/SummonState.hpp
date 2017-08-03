//
//  SummonState.hpp
//  switch
//
//  Created by jiehong jiang on 8/3/17.
//
//

#ifndef SummonState_hpp
#define SummonState_hpp
#include "BaseState.hpp"
class SummonState : BaseState {
public:
    SummonState(std::string);
    virtual BaseState* commandHandler(GameObject* entity, commandType) override;
    virtual BaseState* observing(GameObject*) override;
    
    virtual void enter(GameObject* entity, commandType) override;
    virtual void leave(GameObject*) override;
};

#endif /* SummonState_hpp */
