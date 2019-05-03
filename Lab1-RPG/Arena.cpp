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

bool Arena::getFighterInfoFromInput(std::istringstream &inputStream, std::string &name, char &typeID, int &maxHitPoints, int &strength, int &speed, int &magic) {
    
    // (name) (type) (maximum hit points) (strength) (speed) (magic)
    
    inputStream >> name;
    if (inputStream.fail() || inputStream.eof()) {
        inputStream.clear();
        return false;
    }
    
    inputStream >> typeID;
    if (inputStream.fail() || inputStream.eof()) {
        inputStream.clear();
        return false;
    }
    
    inputStream >> maxHitPoints;
    if (inputStream.fail() || inputStream.eof()) {
        inputStream.clear();
        return false;
    }
    
    inputStream >> strength;
    if (inputStream.fail() || inputStream.eof()) {
        inputStream.clear();
        return false;
    }
    
    inputStream >> speed;
    if (inputStream.fail() || inputStream.eof()) {
        inputStream.clear();
        return false;
    }
    
    inputStream >> magic;
    if (inputStream.fail() || inputStream.eof()) {
        inputStream.clear();
        return false;
    }
    
    return (maxHitPoints > 0 &&
            strength > 0 &&
            speed > 0 &&
            magic > 0);
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
    
    bool result = getFighterInfoFromInput(infoStream,
                                          fighterName,
                                          fighterTypeID,
                                          maxHitPoints,
                                          fighterStrength,
                                          fighterSpeed,
                                          fighterMagic);
    
    if (!result) {
        return false;
    }
    
    // rejecting any string that is not of the correct format or that would add a duplicate name to the arena.
    if (getFighter(fighterName) != nullptr) {
        std::cout << "We already have a fighter by that name." << std::endl;
        return false;
    }
    
    if (fighterTypeID == 'R') {
        // Robot
        newFighter = new Robot(fighterName, maxHitPoints, fighterStrength, fighterSpeed, fighterMagic);
        
    } else if (fighterTypeID == 'A') {
        // Archer
        newFighter = new Archer(fighterName, maxHitPoints, fighterStrength, fighterSpeed, fighterMagic);
    
    } else if (fighterTypeID == 'C') {
        // Cleric
        newFighter = new Cleric(fighterName, maxHitPoints, fighterStrength, fighterSpeed, fighterMagic);
        
    } else {
        // Unknown type
        return false;
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
    
    std::cout << "That fighter is not in the arena." << std::endl;
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
