#ifndef Arena_h
#define Arena_h

#include <stdio.h>
#include <string>
#include <vector>
#include "ArenaInterface.h"

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
};

#endif /* Arena_h */
