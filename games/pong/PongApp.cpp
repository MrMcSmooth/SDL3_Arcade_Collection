#include "PongApp.h"
#include <SDL3/SDL.h>

PongApp::PongApp() : Application(engine::core::AppConfig{"Pong",static_cast<int>(WINDOW_WIDTH), static_cast<int>(WINDOW_HEIGHT)}){}

void PongApp::onStart() {
    SDL_Log("Pong Started"); 
} 

void PongApp::onUpdate(float deltaTime) {

}

void PongApp::onRender() {
    SDL_FRect leftPaddle{LEFT_PADDLE_X, m_leftPaddleY, PADDLE_WIDTH, PADDLE_HEIGHT};
    SDL_FRect rightPaddle{RIGHT_PADDLE_X, m_rightPaddleY, PADDLE_WIDTH, PADDLE_HEIGHT};

    SDL_FRect ball{m_ballX, m_ballY, BALL_SIZE, BALL_SIZE};

    // set color to white for draw
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    //player 1
    SDL_RenderFillRect(m_renderer, &leftPaddle);
    //player 2
    SDL_RenderFillRect(m_renderer, &rightPaddle);

    //ball
    SDL_RenderFillRect(m_renderer, &ball);

}

void PongApp::onTerminate() {

}