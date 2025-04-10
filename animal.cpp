#include <string>
#include "animal.h"

Animal::Animal(std::string n, std::string i, float pX, float pY, int s) : name(n), image(i), posX(pX), posY(pY){sizeX = s; sizeY = s;}
std::string Animal::printInfo(){
    return "Animal : " + name;
}
std::string Animal::getImage(){return image;}
std::string Animal::getName(){return name;}
void Animal::setSize(int x, int y){sizeX = x; sizeY = y;}
int Animal::getSizeX(){return sizeX;}
int Animal::getSizeY(){return sizeY;}
float Animal::getPosX(){return posX;}
float Animal::getPosY(){return posY;}