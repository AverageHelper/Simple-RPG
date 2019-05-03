#include "Arena.h"

Arena::Arena() {
    // auto-allocates the vector
}

Arena::~Arena() {
    
    for (unsigned int i = 0; i < fighters.size(); i++) {
        delete fighters.at(i);
    }
    
    fighters.clear();
}

bool Arena::addFighter(std::string info) {
    std::istringstream infoStream;
    infoStream.str(info);
    
    FighterInterface* newFighter = nullptr;
    
    std::string fighterName = "";
    char fighterTypeID = '-';
    int maxHitPoints = 0;
    int fighterStrength = 0;
    int fighterSpeed = 0;
    int fighterMagic = 0;
    
    // (name) (type) (maximum hit points) (strength) (speed) (magic)
    infoStream >> fighterName;
    infoStream >> fighterTypeID;
    infoStream >> maxHitPoints;
    infoStream >> fighterStrength;
    infoStream >> fighterSpeed;
    infoStream >> fighterMagic;
    
    if (fighterTypeID == 'R') {
        // Robot
        newFighter = new Robot(fighterName, maxHitPoints, fighterStrength, fighterSpeed, fighterMagic);
        
    } else if (fighterTypeID == 'A') {
        // Archer
        newFighter = new Archer(fighterName, maxHitPoints, fighterStrength, fighterSpeed, fighterMagic);
    
    } else if (fighterTypeID == 'C') {
        // Cleric
        newFighter = new Cleric(fighterName, maxHitPoints, fighterStrength, fighterSpeed, fighterMagic);
    }
    
    fighters.push_back(newFighter);
    
    return true;
}

bool Arena::removeFighter(std::string name) {
    int fighterIndex = indexOfFighterNamed(name);
    
    if (fighterIndex >= 0) {
        fighters.erase(fighters.begin() + fighterIndex);
        return true;
    }
    
    return false;
}

FighterInterface* Arena::getFighter(std::string name) {
    int fighterIndex = indexOfFighterNamed(name);
    
    if (fighterIndex >= 0) {
        return fighters.at(fighterIndex);
    }
    
    return nullptr;
}

int Arena::getSize() const {
    return static_cast<int>(fighters.size());
}

int Arena::indexOfFighterNamed(std::string name) {
    
    for (unsigned int i = 0; i < fighters.size(); i++) {
        FighterInterface* foundFighter = fighters.at(i);
        if (foundFighter->getName() == name) {
            return i;
        }
    }
    
    return -1;
}
