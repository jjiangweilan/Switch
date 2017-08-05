//
//  EventManager.cpp
//  switch
//
//  Created by jiehong jiang on 8/7/17.
//
//

#include "EventManager.hpp"

void EventManager::registerEvent(const std::string & name, int count, std::function<void()> scrpit){
    gameEvent_d[name] = new GameEvent(count, scrpit);
}

void EventManager::checkEvent(const std::string & name){
    gameEvent_d[name]->checkOneMission();
}

EventManager::~EventManager(){
    for (auto x = gameEvent_d.begin() ;x != gameEvent_d.end(); x++){
        delete x->second;
    }
}
