#include "Robot.h"

Robot::Robot(std::string name, int maxHitPoints, int strength, int speed, int magic) {
    this->name = name;
    this->maxHitPoints = maxHitPoints;
    this->hitPoints = maxHitPoints;
    this->strength = strength;
    this->speed = speed;
    this->magic = magic;
    this->usedAbility = false;
    this->energy = 10;
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
