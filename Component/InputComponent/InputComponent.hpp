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
    InputComponent(GameObject* container) : ObjectComponent(container){
        
    };
};
#endif /* InputComponent_hpp */
