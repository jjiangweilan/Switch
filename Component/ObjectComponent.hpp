//
//  Component.hpp
//  switch
//
//  Created by jiehong jiang on 7/25/17.
//
//

#ifndef Component_hpp
#define Component_hpp


class GameObject;
class ObjectComponent
{
protected:
    ObjectComponent(GameObject* container):container_(container){};
    GameObject* container_;
};

#endif /* Component_hpp */
