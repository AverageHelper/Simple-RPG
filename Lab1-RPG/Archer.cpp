#include "Archer.h"

Archer::Archer(std::string name, int maxHitPoints, int strength, int speed, int magic) {
    this->name = name;
    this->maxHitPoints = maxHitPoints;
    this->hitPoints = maxHitPoints;
    this->strength = strength;
    this->speed = speed;
    this->magic = magic;
    this->usedAbility = false;
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
