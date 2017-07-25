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

#define ARE_SAME(_x, _y) fabsf(_x - _y) < FLOAT_ACCURACY
#define FLOAT_ACCURACY 0.00000001
#endif /* Component_hpp */
