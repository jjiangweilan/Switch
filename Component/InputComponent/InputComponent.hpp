//
//  InputComponent.hpp
//  switch
//
//  Created by jiehong jiang on 7/25/17.
//
//

#ifndef InputComponent_hpp
#define InputComponent_hpp

#include "ObjectComponent.hpp"

class InputComponent : public ObjectComponent
{
public:
    InputComponent(GameObject* container);
    void setScene(cocos2d::Scene* scene);
private:
    cocos2d::Scene* scene_;
    /* touch event */
};
#endif /* InputComponent_hpp */
