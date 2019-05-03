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
    
    // (name) (type) (maximum hit points) (strength) (speed) (magic)
    
    return true;
}

bool Arena::removeFighter(std::string name) {
    
    return true;
}

FighterInterface* Arena::getFighter(std::string name) {
    
    return nullptr;
}

int Arena::getSize() const {
    return static_cast<int>(fighters.size());
}
