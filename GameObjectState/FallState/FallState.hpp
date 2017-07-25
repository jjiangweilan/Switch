//
//  FallState.hpp
//  mayo
//
//  Created by jiehong jiang on 7/7/17.
//
//

#ifndef FallState_hpp
#define FallState_hpp
#include "BaseState.hpp"
class FallState : public BaseState {
public:
    FallState(std::string name) : BaseState(name){};
    virtual BaseState* commandHandler(GameObject* entity, commandType) override;
    virtual BaseState* observing(GameObject*) override;
    
    virtual void enter(GameObject* entity, commandType) override;
    virtual void leave(GameObject*) override;
};

#endif /* FallState_hpp */
