//
//  GameSceneEvent.hpp
//  switch
//
//  Created by jiehong jiang on 7/30/17.
//
//

#ifndef GameEvent_hpp
#define GameEvent_hpp

#include <functional>
class GameEvent {
    
public:
    GameEvent(int count, std::function<void()> script) : count_(count), script_(script){};
    void checkOneMission();
private:
    int count_;
    std::function<void()> script_;
};

#endif /* GameEvent_hpp */
