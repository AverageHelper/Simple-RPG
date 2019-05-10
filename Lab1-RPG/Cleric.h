#ifndef Cleric_h
#define Cleric_h

#include <iostream>
#include "Fighter.h"

class Cleric : public Fighter {
private:
    int mana;
    
public:
    Cleric(std::string name = "Unnamed", int maxHitPoints = 10, int strength = 10, int speed = 10, int magic = 10);
    int getDamage();
    void reset();
    void regenerate();
    bool useAbility();
};

#endif /* Cleric_h */
