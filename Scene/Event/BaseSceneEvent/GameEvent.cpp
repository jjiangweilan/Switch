//
//  Event.cpp
//  switch
//
//  Created by jiehong jiang on 7/30/17.
//
//

#include "GameEvent.hpp"



void GameEvent::checkOneMission(){
    --count_;
    if(count_ == 0){
        script_();
    }
}
