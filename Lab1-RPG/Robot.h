#ifndef Robot_h
#define Robot_h

#include <iostream>
#include <string>
#include "FighterInterface.h"

class Robot : public FighterInterface {
private:
    std::string name;
    int maxHitPoints;
    int hitPoints;
    int strength;
    int speed;
    int magic;
    int energy;
    int bonusDamage;
    bool usedAbility;
    
public:
    Robot(std::string name = "Unnamed", int maxHitPoints = 10, int strength = 10, int speed = 10, int magic = 10);
    std::string getName() const;
    int getMaximumHP() const;
    int getCurrentHP() const;
    int getStrength() const;
    int getSpeed() const;
    int getMagic() const;
    int getDamage();
    void takeDamage(int damage);
    void reset();
    void regenerate();
    bool useAbility();
};

#endif /* Robot_h */
