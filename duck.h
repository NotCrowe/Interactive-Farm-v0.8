#include <string>
#include "animal.h"

class Duck:public Animal{
    public:
        std::string featherColor;
        
        Duck(std::string n, std::string i, float pX, float pY, int s);

        using Animal::printInfo;
        std::string printInfo();
};