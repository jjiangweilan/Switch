//
//  EventManager.hpp
//  switch
//
//  Created by jiehong jiang on 8/7/17.
//
//

#ifndef EventManager_hpp
#define EventManager_hpp
#include "GameEvent.hpp"
#include <map>
#include <functional>
typedef std::map<std::string, GameEvent*> GameEvent_d;
class EventManager {
public:
    EventManager() : gameEvent_d(){} ;
    ~EventManager();
    /**
     add a event with a name and it's script

     @param std::string& event's name
     @param std::function<void()> the script that will be ran
     */
    void registerEvent(const std::string & name, int count, std::function<void()> scrpit);
    /**
     check event with the name

     @return return if this event is triggered
     */
    void checkEvent(const std::string & name);
private:
    GameEvent_d gameEvent_d;
};

#endif /* EventManager_hpp */
