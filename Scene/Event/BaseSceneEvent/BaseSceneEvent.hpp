//
//  BaseSceneEvent.hpp
//  switch
//
//  Created by jiehong jiang on 7/30/17.
//
//

#ifndef BaseSceneEvent_hpp
#define BaseSceneEvent_hpp

#include <functional>
class BaseSceneEvent {
    
public:
    BaseSceneEvent(int count, std::function<void()> script) : count_(count), script_(script){};
    void checkOneMission();
private:
    int count_;
    std::function<void()> script_;
};

#endif /* BaseSceneEvent_hpp */
