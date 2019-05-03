#include "Robot.h"

Robot::Robot() {
    name = "Unnamed";
    usedAbility = false;
    maxHitPoints = 10;
    hitPoints = 10;
    strength = 10;
    speed = 10;
    energy = 10;
    magic = 1;
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
        return strength + ROBOT_ABILITY_COST;
    }
    return strength;
}

void Robot::takeDamage(int damage) {
    hitPoints -= damage - (speed / 4);
}

void Robot::reset() {
    hitPoints = maxHitPoints;
    energy = magic * 2;
    usedAbility = false;
}

void Robot::regenerate() {
    int growthFactor = (strength / 6);
    if (growthFactor <= 0) {
        growthFactor = 1;
    }
    
    hitPoints += growthFactor;
    
    if (hitPoints > maxHitPoints) {
        hitPoints = maxHitPoints;
    }
}

bool Robot::useAbility() {
    // Shockwave Punch
    
    return true;
}
