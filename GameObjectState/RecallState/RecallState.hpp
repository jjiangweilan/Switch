//
//  RecallState.hpp
//  switch
//
//  Created by jiehong jiang on 8/5/17.
//
//

#ifndef RecallState_hpp
#define RecallState_hpp
#include "BaseState.hpp"

/*once hero enter recall state it will use controlcompoenet of another hero to call it's onRecalled*/
class RecallState : public BaseState{
public:
    RecallState(std::string name) : BaseState(name) {};
    virtual BaseState* commandHandler(GameObject* entity, commandType) override;
    virtual BaseState* observing(GameObject*) override;
    
    virtual void enter(GameObject* entity, commandType) override;
    virtual void leave(GameObject*) override;
};

#endif /* RecallState_hpp */
