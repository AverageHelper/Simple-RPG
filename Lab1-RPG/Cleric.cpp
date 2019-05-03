#include "Cleric.h"

Cleric::Cleric(std::string name, int maxHitPoints, int strength, int speed, int magic) {
    this->name = name;
    this->maxHitPoints = maxHitPoints;
    this->hitPoints = maxHitPoints;
    this->strength = strength;
    this->speed = speed;
    this->magic = magic;
    this->mana = 5 * magic;
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
    return magic;
}

void Cleric::takeDamage(int damage) {
    int damageTaken = damage - (speed / 4);
    
    if (damageTaken < 1) {
        damageTaken = 1;
    }
    
    hitPoints -= damageTaken;
}

void Cleric::reset() {
    hitPoints = maxHitPoints;
    mana = 5 * magic;
}

void Cleric::regenerate() {
    int growthFactor = (strength / 6);
    int manaGrowthFactor = (magic / 5);
    
    if (growthFactor < 1) {
        growthFactor = 1;
    }
    
    if (manaGrowthFactor < 1) {
        manaGrowthFactor = 1;
    }
    
    hitPoints += growthFactor;
    mana += manaGrowthFactor;
    
    if (hitPoints > maxHitPoints) {
        hitPoints = maxHitPoints;
    }
    
    if (mana > 5 * magic) {
        mana = 5 * magic;
    }
}

bool Cleric::useAbility() {
    // Healing Light
    if (mana >= CLERIC_ABILITY_COST) {
        int increaseFactor = magic / 3;
        
        if (increaseFactor < 1) {
            increaseFactor = 1;
        }
        
        if (hitPoints + increaseFactor <= maxHitPoints) {
            hitPoints += increaseFactor;
        }
        
        mana -= CLERIC_ABILITY_COST;
        
        return true;
    }
    
    return false;
}
