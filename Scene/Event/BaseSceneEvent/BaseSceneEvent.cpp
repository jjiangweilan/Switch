//
//  BaseSceneEvent.cpp
//  switch
//
//  Created by jiehong jiang on 7/30/17.
//
//

#include "BaseSceneEvent.hpp"



void BaseSceneEvent::checkOneMission(){
    --count_;
    if(count_ == 0){
        script_();
    }
}
