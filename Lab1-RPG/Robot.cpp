#include "Robot.h"

Robot::Robot(std::string name, int maxHitPoints, int strength, int speed, int magic) {
    this->name = name;
    this->maxHitPoints = maxHitPoints;
    this->hitPoints = maxHitPoints;
    this->strength = strength;
    this->speed = speed;
    this->magic = magic;
    this->bonusDamage = 0;
    this->usedAbility = false;
    this->energy = 2 * magic;
}

std::string Robot::getName() const {
    return this->name;
}

int Robot::getMaximumHP() const {
    return this->maxHitPoints;
}

int Robot::getCurrentHP() const {
    return this->hitPoints;
}

int Robot::getStrength() const {
    return this->strength;
}

int Robot::getSpeed() const {
    return this->speed;
}

int Robot::getMagic() const {
    return this->magic;
}

int Robot::getDamage() {
    if (usedAbility) {
        usedAbility = false;
        return strength + bonusDamage;
    }
    return strength;
}

void Robot::takeDamage(int damage) {
    int damageTaken = damage - (speed / 4);
    
    if (damageTaken < 1) {
        damageTaken = 1;
    }
    
    hitPoints -= damageTaken;
}

void Robot::reset() {
    hitPoints = maxHitPoints;
    energy = magic * 2;
    usedAbility = false;
    bonusDamage = 0;
}

void Robot::regenerate() {
    int growthFactor = (strength / 6);
    
    if (growthFactor < 1) {
        growthFactor = 1;
    }
    
    hitPoints += growthFactor;
    
    if (hitPoints > maxHitPoints) {
        hitPoints = maxHitPoints;
    }
}

bool Robot::useAbility() {
    // Shockwave Punch
    
    if (energy >= ROBOT_ABILITY_COST) {
        const double energyFactor = energy / (2.0 * magic);
        const double energyFactor_4 = energyFactor * energyFactor * energyFactor * energyFactor;
        
        bonusDamage = static_cast<int>(strength * energyFactor_4);
        energy -= ROBOT_ABILITY_COST;
        
        return true;
    }
    
    return false;
}
