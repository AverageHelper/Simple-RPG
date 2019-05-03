#include "Archer.h"

Archer::Archer(std::string name, int maxHitPoints, int strength, int speed, int magic) {
    this->name = name;
    this->maxHitPoints = maxHitPoints;
    this->hitPoints = maxHitPoints;
    this->strength = strength;
    this->initialSpeed = speed;
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
    return speed;
}

void Archer::takeDamage(int damage) {
    int damageTaken = damage - (speed / 4);
    
    if (damageTaken < 1) {
        damageTaken = 1;
    }
    
    hitPoints -= damageTaken;
}

void Archer::reset() {
    hitPoints = maxHitPoints;
    speed = initialSpeed;
}

void Archer::regenerate() {
    int growthFactor = (strength / 6);
    
    if (growthFactor < 1) {
        growthFactor = 1;
    }
    
    hitPoints += growthFactor;
    
    if (hitPoints > maxHitPoints) {
        hitPoints = maxHitPoints;
    }
}

bool Archer::useAbility() {
    // Quickstep
    speed += 1;
    
    return true;
}
