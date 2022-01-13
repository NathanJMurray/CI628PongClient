#ifndef __MY_GAME_H__
#define __MY_GAME_H__

#include <iostream>
#include <vector>
#include <string>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

static struct GameData {
    int player1Y = 0;
    int player2Y = 0;
    int ballX = 0;
    int ballY = 0;
    int score1 = 0;
    int score2 = 0;
} game_data;
 

class Texture {
    public:
        static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
};


class Font { 
    public:
        TTF_Font* font = TTF_OpenFont("assets/arial.ttf", 100);
        SDL_Color White = { 255, 255, 255 };
        SDL_Surface* surface = TTF_RenderText_Solid(font, "Hi", White);
        SDL_Texture* texture = nullptr;
        void fontRender(SDL_Renderer* render) {
            texture = SDL_CreateTextureFromSurface(render, surface);
            SDL_FreeSurface(surface);
        }        
};

class Rect {
    public:
        SDL_Rect score = { 400, 400, 100, 100 };
};

class MyGame {

    private:
        SDL_Rect player1 = { 200, 0, 20, 60 };
        SDL_Rect player2 = { 580, 0, 20, 60 };
        SDL_Rect ball = { 0, 0, 15, 15 };

    public:
        std::vector<std::string> messages;

        void on_receive(std::string message, std::vector<std::string>& args);
        void send(std::string message);
        void input(SDL_Event& event);
        void update();
        void render(SDL_Renderer* renderer);
};

#endif