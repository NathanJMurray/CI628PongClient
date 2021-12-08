#include "MyGame.h"

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
    player1.y = game_data.player1Y;
    
    //updates the Y position of the player 2 
    player2.y = game_data.player2Y;

    //updates the Y position of the ball
    ball.y = game_data.ballY;

    //updates the X position of the ball
    ball.x = game_data.ballX;
}

void MyGame::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    //SDL_RenderDrawRect(renderer, &player1);
    
    //Draws a filled rect for the player 1
    SDL_RenderFillRect(renderer, &player1);
    //SDL_RenderDrawRect(renderer, &player2);

    //Draws a filled rect for the player 2
    SDL_RenderFillRect(renderer, &player2);
    //SDL_RenderDrawRect(renderer, &ball);

    //Draws a filled rect for the ball
    SDL_RenderFillRect(renderer, &ball);
}