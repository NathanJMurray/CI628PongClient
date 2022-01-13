#ifndef __MY_GAME_H__
#define __MY_GAME_H__

#include <iostream>
#include <vector>
#include <string>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

static struct GameData {
    int player1Y = 0;
    int player2Y = 0;
    int ballX = 0;
    int ballY = 0;
} game_data;
 
//class Player {
    //public:
        //int X;
        //int Y;
        //int Width;
        //int Height;
        //SDL_Rect player = { X, Y, Width, Height };
//};

class Texture {
    public:
        static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
};

//class applauseFX {
    
//};

//class Font { 
    //public:
        //static SDL_Texture* CreateTextTexture(TTF_Font* font, std::string text, SDL_Renderer* ren);
        //SDL_Texture* GetText(std::string text, std::string filename, int size);

    //private:
        //TTF_Font* GetFont(std::string filename, int size);
//};

class MyGame {

    private:
        SDL_Rect player1 = { 200, 0, 20, 60 };
        //Player Player1;

        SDL_Rect player2 = { 580, 0, 20, 60 };
        SDL_Rect ball = { 0, 0, 15, 15 };
        SDL_Rect score = { 0, 0, 50, 100};

    public:
        std::vector<std::string> messages;

        void on_receive(std::string message, std::vector<std::string>& args);
        void send(std::string message);
        void input(SDL_Event& event);
        void update();
        void render(SDL_Renderer* renderer);
};

#endif