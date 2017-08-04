//
//  SummonSystem.hpp
//  switch
//
//  Created by jiehong jiang on 8/3/17.
//
//

#ifndef SummonSystem_hpp
#define SummonSystem_hpp

#include "Hero.hpp"
#include "GameScene.hpp"
/*on-screen controller will change state of current controlled hero to display animation, and the the current controlled hero will work with this class to interacte with scene to show sprite and add physics body.
    
    summon system will manage the sprite and physics and current controlled hero in scene, Hero class will handle animation and controlling problem.
 */
class SummonSystem {
private:
    Hero* bro_;
    Hero* sis_;
    GameScene* scene_;
public:
    SummonSystem(Hero* bro, Hero* sis, GameScene* scene) : bro_(bro), sis_(sis), scene_(scene) {};
    ~SummonSystem(){};
    
    void summon(HeroType);
    void switchTo(Hero*);
    void recall(Hero*);
    
};

#endif /* SummonSystem_hpp */
