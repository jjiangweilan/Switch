//
//  AttackState.hpp
//  mayo
//
//  Created by jiehong jiang on 7/8/17.
//
//

#ifndef AttackState_hpp
#define AttackState_hpp
#include "BaseState.hpp"
class AttackState : public BaseState {
public:
    AttackState(std::string name) : BaseState(name){};
    virtual BaseState* commandHandler(GameObject* entity, commandType) override;
    virtual BaseState* observing(GameObject*) override;
    
    virtual void enter(GameObject* entity, commandType) override;
    virtual void leave(GameObject*) override;
};

#endif /* AttackState_hpp */
