//
//  StaticState.cpp
//  switch
//
//  Created by jiehong jiang on 7/26/17.
//
//

#include "StaticState.hpp"

#define INVALID_CALL assert(1==0)

BaseState* commandHandler(GameObject* entity, commandType type){
    switch (type) {
        default:
            INVALID_CALL;
    }
}

BaseState* StaticState::observing(GameObject*){INVALID_CALL;};

void StaticState::enter(GameObject* entity, commandType type){
    //TO_DO: since it's static. A static picture (sprite frame rather than animation) should be displayed.
}

void StaticState::leave(GameObject*){INVALID_CALL;}
