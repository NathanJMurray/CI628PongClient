#include "MyGame.h"

Rect scoreRect;
Font scoreFont;

SDL_Texture* Texture::LoadTexture(const char* texture, SDL_Renderer* ren) {
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}

SDL_Texture* ballTex;



//SDL_Texture* Font::CreateTextTexture(TTF_Font* font, std::string text, SDL_Renderer* ren) {
    //SDL_Surface* tempSurface = TTF_RenderText_Solid(font, text.c_str(), { 255, 255, 255 });
    //SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
    //SDL_FreeSurface(tempSurface);

    //return tex;
//}

//SDL_Texture* Font;

//TTF_Font* Font::GetFont(std::string filename, int size) {
//    std::string fullPath = SDL_GetBasePath();
//    fullPath.append("assests/" + filename);
//    std::string key = fullPath + (char)size;
//}
//
//SDL_Texture* Font::GetText(std::string text, std::string filename, int size) {
//    TTF_Font* font = GetFont(filename, size);
//    std::string key = text + filename + (char)size;
//}
//SDL_Texture* scoretxt;

void MyGame::on_receive(std::string cmd, std::vector<std::string>& args) {
    if (cmd == "GAME_DATA") {
        // we should have exactly 4 arguments
        if (args.size() == 4) {
            game_data.player1Y = stoi(args.at(0));
            game_data.player2Y = stoi(args.at(1));
            game_data.ballX = stoi(args.at(2));
            game_data.ballY = stoi(args.at(3));
        }
    } else {
        std::cout << "Received: " << cmd << std::endl;
    }
}

void MyGame::send(std::string message) {
    messages.push_back(message);
}

void MyGame::input(SDL_Event& event) {
    switch (event.key.keysym.sym) {
        //checks for key down event on the W key
        case SDLK_w:
            send(event.type == SDL_KEYDOWN ? "W_DOWN" : "W_UP");
            break;

        //checks for key down event on the S key
        case SDLK_s:
            send(event.type == SDL_KEYDOWN ? "S_DOWN" : "S_UP");
            break;

        //checks for key down event on the I key
        case SDLK_i:
            send(event.type == SDL_KEYDOWN ? "I_DOWN" : "I_UP");
            break;

        //checks for key down event on the K key
        case SDLK_k:
            send(event.type == SDL_KEYDOWN ? "K_DOWN" : "K_UP");
            break;
    }
}

void MyGame::update() {
    //Player1.X = 200;
    //Player1.Y = 0;
    //Player1.Width = 20;
    //Player1.Height = 60;
    player1.y = game_data.player1Y;
    
    //updates the Y position of the player 2 
    player2.y = game_data.player2Y;

    //updates the Y position of the ball
    ball.y = game_data.ballY;

    //updates the X position of the ball
    ball.x = game_data.ballX;
}

void MyGame::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, ballTex, NULL, &ball);
    //SDL_RenderCopy(renderer, scoreTxt, NULL, &score);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        
    //Draws a filled rect for the player 1
    //SDL_RenderFillRect(renderer, player1);
    SDL_RenderFillRect(renderer, &player1);


    //Draws a filled rect for the player 2
    SDL_RenderFillRect(renderer, &player2);
    //SDL_RenderDrawRect(renderer, player2);

    //Draws a filled rect for the ball    
    //SDL_RenderFillRect(renderer, &ball);
    
    ballTex = Texture::LoadTexture("assets/SoccerBallV7.png", renderer);
    //Font = Texture::LoadTexture("assets/calibri.ttf", renderer);

    scoreFont.fontRender(renderer);
    SDL_RenderCopy(renderer, scoreFont.texture, NULL, &scoreRect.score);
}

