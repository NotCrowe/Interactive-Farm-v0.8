#include <string>
#include "animal.h"

class Goat:public Animal{
    public:
        int hornLength;
        Goat(std::string n, std::string i, float pX, float pY, int s);

        using Animal::printInfo;
        std::string printInfo();
};