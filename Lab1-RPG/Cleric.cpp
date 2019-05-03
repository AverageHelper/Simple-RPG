#include "Cleric.h"

Cleric::Cleric(std::string name, int maxHitPoints, int strength, int speed, int magic) {
    this->name = name;
    this->maxHitPoints = maxHitPoints;
    this->hitPoints = maxHitPoints;
    this->strength = strength;
    this->speed = speed;
    this->magic = magic;
    this->usedAbility = false;
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
