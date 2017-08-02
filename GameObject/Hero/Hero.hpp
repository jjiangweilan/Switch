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

enum HeroType {bro, sis};
class Hero : public GameObject {
public:
    ~Hero();
    /**
     create a hero

     @param HeroType bro or sis
     @return the ptr to the new hero
     */
    static Hero* create(const std::string&, HeroType, b2Body*);
    
    /**
     create default bro fixture def for world to generate physics body

     @return the fixture def
     */
    static std::vector<b2FixtureDef> createDefaultBroFixtureDef();
    
    /**
     create default sis fixture def for wolrd to generate physics body

     @return the default sis fixture def
     */
    static std::vector<b2FixtureDef> createDefaultSisFixtureDef();
    
    /**
     override sprite's update

     @param delta time step
     */
    void update(float delta) override;
private:
    b2PolygonShape* collisionAreaShape;
    
    //call sprite's init
    bool init() override;
    
    Hero(const std::string&, HeroType, b2Body*);
    
};

#endif /* Hero_hpp */
