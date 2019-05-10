#ifndef Fighter_h
#define Fighter_h

#include <iostream>
#include "FighterInterface.h"

class Fighter : public FighterInterface {
protected:
    std::string name;
    int maxHitPoints;
    int hitPoints;
    int strength;
    int speed;
    int magic;
    bool usedAbility;
    
public:
    Fighter(std::string name = "Unnamed", int maxHitPoints = 10, int strength = 10, int speed = 10, int magic = 10);
    std::string getName() const;
    int getMaximumHP() const;
    int getCurrentHP() const;
    int getStrength() const;
    int getSpeed() const;
    int getMagic() const;
    virtual int getDamage() = 0;
    void takeDamage(int damage);
    virtual void reset();
    virtual void regenerate();
    virtual bool useAbility() = 0;
};

#endif /* Fighter_h */
