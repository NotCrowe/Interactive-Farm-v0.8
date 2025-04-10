#include "raylib.h"
#include "goat.h"
#include "duck.h"
#include <vector>
#include <string>
#include <iostream>

int main(void){
    //Intitialize
    InitWindow(1000,800,"Interactive Farm v0.5");

    SetTargetFPS(60);

    std::vector<Animal*> farmAnimals;
    std::vector<Texture2D> im;

    std::string text1 = "";

    //Create animals and put them in the vector of animals
    Animal cow("Cow","assets/images/cow.png",100,200,100);
    Animal sheep("Sheep","assets/images/sheep.png",100,500,100);
    Goat goat("Goat","assets/images/goat.png",700,200,100);
    Duck duck("Duck","assets/images/duck.png",700,500,100);

    goat.hornLength = 8;
    duck.featherColor = "Yellow";

    farmAnimals.push_back(&cow);
    farmAnimals.push_back(&sheep);
    farmAnimals.push_back(&goat);
    farmAnimals.push_back(&duck);

    //Load textures of animals to draw later
    for(Animal* anim : farmAnimals){
        Animal ans = *anim;
        Image gt = LoadImage(ans.getImage().c_str());
        ImageResize(&gt,ans.getSizeX(),ans.getSizeY());
        im.push_back(LoadTextureFromImage(gt));
    }

    while(!WindowShouldClose()){
        Rectangle mp;
        std::vector<Rectangle> anR;

        //check for mouse input and set text to animal info if collides with animal
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            Vector2 pos = GetMousePosition();
            for(Animal* anim : farmAnimals){
                Animal ans = *anim;
                mp = {pos.x,pos.y,5,5};
                Rectangle ansr = {ans.getPosX(),ans.getPosY(),((float)ans.getSizeX()),((float)ans.getSizeY())};
                anR.push_back(ansr);
                if(CheckCollisionRecs(mp,ansr)){
                    text1 = anim->printInfo();
                }
            }
            

            
        }

        //Draw the animals
        BeginDrawing();
            ClearBackground(DARKGREEN);
            int i = 0;
            for(Animal* anim : farmAnimals){
                Animal ans = *anim;
                DrawTextureRec(im.at(i),{ans.getPosX(),ans.getPosY(),((float)ans.getSizeX()),((float)ans.getSizeY())},{ans.getPosX(),ans.getPosY()},WHITE);
                i += 1;
            }

            if(text1 != "")DrawText(text1.c_str(),300,720,25,WHITE);
            
        EndDrawing();
    }

    CloseWindow();
    return 0;
}