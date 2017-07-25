//
//  Hero.hpp
//  switch
//
//  Created by jiehong jiang on 7/25/17.
//
//

#ifndef Hero_hpp
#define Hero_hpp
#include "GameObject.hpp"
class Hero : public GameObject {
    static Hero* create(const std::string& name,const b2Vec2& bodySize);
private:
    bool init();
    Hero(const std::string& name,const b2Vec2& bodySize);
    ~Hero();
};

#endif /* Hero_hpp */
