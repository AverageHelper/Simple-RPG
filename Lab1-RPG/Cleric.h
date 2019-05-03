#ifndef Cleric_h
#define Cleric_h

#include <stdio.h>
#include "FighterInterface.h"

class Cleric : public FighterInterface {
private:
    std::string name;
    int maxHitPoints;
    int hitPoints;
    int strength;
    int speed;
    int magic;
    bool usedAbility;
    
public:
    Cleric();
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

#endif /* Cleric_h */
