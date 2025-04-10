#include <string>
#include "goat.h"

Goat::Goat(std::string n, std::string i, float pX, float pY, int s) : Animal(n, i, pX, pY, s){}
std::string Goat::printInfo(){
    std::string goa = (Animal::printInfo() + ", Horn length: " + std::to_string(hornLength));
    return goa;
}