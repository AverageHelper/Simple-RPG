#include "Cleric.h"

Cleric::Cleric() {
    name = "Unnamed";
    maxHitPoints = 0;
    hitPoints = 0;
    strength = 0;
    speed = 0;
    magic = 0;
    usedAbility = 0;
}

std::string Cleric::getName() const {
    return name;
}

int Cleric::getMaximumHP() const {
    return maxHitPoints;
}

int Cleric::getCurrentHP() const {
    return hitPoints;
}

int Cleric::getStrength() const {
    return strength;
}

int Cleric::getSpeed() const {
    return speed;
}

int Cleric::getMagic() const {
    return magic;
}

int Cleric::getDamage() {
    return 0;
}

void Cleric::takeDamage(int damage) {
    
}

void Cleric::reset() {
    
}

void Cleric::regenerate() {
    
}

bool Cleric::useAbility() {
    return true;
}
