#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal{
    protected:
        std::string image;
        std::string name;

        float posX;
        float posY;

        int sizeX;
        int sizeY;
    public:

        Animal(std::string n, std::string i, float pX, float pY, int s);
        virtual std::string printInfo();
        std::string getImage();
        std::string getName();

        void setSize(int x, int y);
        int getSizeX();
        int getSizeY();

        float getPosX();
        float getPosY();

};

#endif