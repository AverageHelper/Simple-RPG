#ifndef Archer_h
#define Archer_h

#include <iostream>
#include "Fighter.h"

class Archer : public Fighter {
private:
    int initialSpeed;
    
public:
    Archer(std::string name = "Unnamed", int maxHitPoints = 10, int strength = 10, int speed = 10, int magic = 10);
    int getDamage();
    void reset();
    bool useAbility();
};

#endif /* Archer_h */
