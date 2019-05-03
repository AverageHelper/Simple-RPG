#ifndef Robot_h
#define Robot_h

#include <stdio.h>
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
    bool usedAbility;
    
public:
    Robot();
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
