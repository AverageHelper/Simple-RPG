#include "Archer.h"

Archer::Archer(std::string name, int maxHitPoints, int strength, int speed, int magic) : Fighter(name, maxHitPoints, strength, speed, magic) {
    this->initialSpeed = speed;
}

/**
 *    getDamage()
 *
 *    Returns the amount of damage a fighter will deal.
 *
 *    This value is equal to the Archer's speed.
 */
int Archer::getDamage() {
    return speed;
}

/**
 *    reset()
 *
 *    Restores a fighter's current hit points to its maximum hit points.
 *
 *    Archer:
 *    Also resets an Archer's current speed to its original value.
 */
void Archer::reset() {
    Fighter::reset();
    speed = initialSpeed;
}

/**
 *    useAbility()
 *
 *    Attempts to perform a special ability based on the type of fighter.  The
 *    fighter will attempt to use this special ability just prior to attacking
 *    every turn.
 *
 *    Archer: Quickstep
 *    Increases the Archer's speed by one point each time the ability is used.
 *    This bonus lasts until the reset() method is used.
 *    This ability always works; there is no maximum bonus speed.
 *
 *    Return true if the ability was used; false otherwise.
 */
bool Archer::useAbility() {
    // Quickstep
    speed += 1;
    usedAbility = true;
    
    return true;
}
