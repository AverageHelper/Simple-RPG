#ifndef Robot_h
#define Robot_h

#include <iostream>
#include <string>
#include "Fighter.h"

class Robot : public Fighter {
private:
    int energy;
    int bonusDamage;
    
public:
    Robot(std::string name = "Unnamed", int maxHitPoints = 10, int strength = 10, int speed = 10, int magic = 10);
    int getDamage();
    void reset();
    bool useAbility();
};

#endif /* Robot_h */
