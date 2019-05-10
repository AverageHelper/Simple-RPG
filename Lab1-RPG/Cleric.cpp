#include "Cleric.h"

Cleric::Cleric(std::string name, int maxHitPoints, int strength, int speed, int magic) : Fighter(name, maxHitPoints, strength, speed, magic) {
    this->mana = 5 * magic;
}

/**
 *    getDamage()
 *
 *    Returns the amount of damage a fighter will deal.
 *
 *    This value is equal to the Cleric's magic.
 */
int Cleric::getDamage() {
    return magic;
}

/**
 *    reset()
 *
 *    Restores a fighter's current hit points to its maximum hit points.
 *
 *    Cleric:
 *    Also restores a Cleric's current mana to its maximum value (which is 5 times its magic).
 */
void Cleric::reset() {
    Fighter::reset();
    mana = 5 * magic;
}

/**
 *    regenerate()
 *
 *    Increases the fighter's current hit points by an amount equal to one sixth of
 *    the fighter's strength.  This method must increase the fighter's current hit
 *    points by at least one.  Do not allow the current hit points to exceed the
 *    maximum hit points.
 *
 *    Cleric:
 *    Also increases a Cleric's current mana by an amount equal to one fifth of the
 *    Cleric's magic.  This method must increase the Cleric's current mana by at
 *    least one.  Do not allow the current mana to exceed the maximum mana (again, 5 times its magic).
 */
void Cleric::regenerate() {
    Fighter::regenerate();
    int manaGrowthFactor = (magic / 5);
    
    if (manaGrowthFactor < 1) {
        manaGrowthFactor = 1;
    }
    
    mana += manaGrowthFactor;
    
    if (mana > 5 * magic) {
        mana = 5 * magic;
    }
}

/**
 *    useAbility()
 *
 *    Attempts to perform a special ability based on the type of fighter.  The
 *    fighter will attempt to use this special ability just prior to attacking
 *    every turn.
 *
 *    Cleric: Healing Light
 *    Increases the Cleric's current hit points by an amount equal to one third of its magic.
 *    Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
 *    Will be used even if the Cleric's current HP is equal to their maximum HP.
 *    Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
 *    Cleric Note:
 *    This ability, when successful, must increase the Cleric's current hit points
 *    by at least one, unless doing so would given the Cleric more hit points than its maximum hit points.
 *    Do not allow the current hit points to exceed the maximum hit points.
 *
 *    Return true if the ability was used; false otherwise.
 */
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
        usedAbility = true;
        
        return true;
    }
    
    return false;
}
