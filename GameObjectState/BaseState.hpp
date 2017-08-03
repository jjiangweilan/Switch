//
//  BaseSate.hpp
//  mayo
//
//  Created by jiehong jiang on 7/6/17.
//
//

#ifndef BaseSate_hpp
#define BaseSate_hpp
#include "cocos2d.h"
class GameObject;
USING_NS_CC;
enum commandType {
    goLeft, switch_, goRight, jump, idle, static_, leftRelease, attack, summon, none
};

class BaseState {
protected:
    std::string actionType;
public:
    BaseState(std::string);
    virtual BaseState* commandHandler(GameObject* entity, commandType) = 0;
    virtual BaseState* observing(GameObject*) = 0;
    
    virtual void enter(GameObject* entity, commandType);
    virtual void leave(GameObject*);
    
    //getter and setter
    std::string getStateName();
};


#include "GameObjectStates.hpp"
#endif /* BaseSate_hpp */
