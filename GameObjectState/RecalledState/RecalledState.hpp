//
//  RecalledState.hpp
//  switch
//
//  Created by jiehong jiang on 8/5/17.
//
//

#ifndef RecalledState_hpp
#define RecalledState_hpp
#include "BaseState.hpp"

/*once hero enter this state and the animation is finished, this state machien will call summon system of the scene to delete it's body and hide it's sprite*/
class RecalledState : public BaseState {
public:
public:
    RecalledState(std::string name) : BaseState(name) {};
    virtual BaseState* commandHandler(GameObject* entity, commandType) override;
    virtual BaseState* observing(GameObject*) override;
    
    virtual void enter(GameObject* entity, commandType) override;
    virtual void leave(GameObject*) override;
};

#endif /* RecalledState_hpp */
