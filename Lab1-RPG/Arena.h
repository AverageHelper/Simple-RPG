#ifndef Arena_h
#define Arena_h

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "ArenaInterface.h"
#include "Robot.h"
#include "Archer.h"
#include "Cleric.h"

class Arena : public ArenaInterface {
public:
    Arena();
    ~Arena();
    bool addFighter(std::string info);
    bool removeFighter(std::string name);
    FighterInterface* getFighter(std::string name);
    int getSize() const;
    
private:
    std::vector<FighterInterface*> fighters;
    int indexOfFighterNamed(std::string name);
};

#endif /* Arena_h */
