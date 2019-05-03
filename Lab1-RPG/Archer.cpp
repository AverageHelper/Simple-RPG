#include "Archer.h"

Archer::Archer() {
    name = "Unnamed";
    maxHitPoints = 0;
    hitPoints = 0;
    strength = 0;
    speed = 0;
    magic = 0;
    usedAbility = false;
}

std::string Archer::getName() const {
    return name;
}

int Archer::getMaximumHP() const {
    return maxHitPoints;
}

int Archer::getCurrentHP() const {
    return hitPoints;
}

int Archer::getStrength() const {
    return strength;
}

int Archer::getSpeed() const {
    return speed;
}

int Archer::getMagic() const {
    return magic;
}

int Archer::getDamage() {
    return 0;
}

void Archer::takeDamage(int damage) {
    
}

void Archer::reset() {
    
}

void Archer::regenerate() {
    
}

bool Archer::useAbility() {
    return true;
}
