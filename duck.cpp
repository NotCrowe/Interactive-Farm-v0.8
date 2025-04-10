#include <string>
#include "duck.h"

Duck::Duck(std::string n, std::string i, float pX, float pY, int s) : Animal(n, i, pX, pY, s){}
std::string Duck::printInfo(){
    return (Animal::printInfo() + ", Feather Color: " + featherColor);
}