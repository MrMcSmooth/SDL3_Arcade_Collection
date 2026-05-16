#include "PongApp.h"
#include "SDL3/SDL_log.h"
#include <SDL3/SDL.h>
#include <algorithm>

PongApp::PongApp() : Application(engine::core::AppConfig{"Pong",static_cast<int>(WINDOW_WIDTH), static_cast<int>(WINDOW_HEIGHT)}){}

void PongApp::onStart() {
    SDL_Log("Pong Started"); 
} 

void PongApp::onUpdate(float deltaTime) {

    handleInput(deltaTime);

    //bounce off ceiling, preserve momentum
    if(m_ballY < 0 || m_ballY > WINDOW_HEIGHT - BALL_SIZE)
    {
        m_ballVY = -m_ballVY;
    }

    m_ballX += m_ballVX * deltaTime;
    m_ballY += m_ballVY * deltaTime;

    if(m_ballX <  0 - BALL_SIZE){
        player2Points++;
        resetBall(0);
    }
    if(m_ballX > WINDOW_WIDTH){
        player1Points++;
        resetBall(1);
    }


}

void PongApp::onRender() {
    SDL_FRect leftPaddle{LEFT_PADDLE_X, m_leftPaddleY, PADDLE_WIDTH, PADDLE_HEIGHT};
    SDL_FRect rightPaddle{RIGHT_PADDLE_X, m_rightPaddleY, PADDLE_WIDTH, PADDLE_HEIGHT};

    SDL_FRect ball{m_ballX, m_ballY, BALL_SIZE, BALL_SIZE};

    
    if (rectangleOverlaps(ball, leftPaddle))
    {
        m_ballX = LEFT_PADDLE_X + PADDLE_WIDTH;
        m_ballVX = -m_ballVX;
    }

    if (rectangleOverlaps(ball, rightPaddle))
    {
        m_ballX = RIGHT_PADDLE_X - BALL_SIZE;
        m_ballVX = -m_ballVX;
    }

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

bool rectangleOverlaps(const SDL_FRect& a, const SDL_FRect& b) {
    return a.x < b.x + b.w &&
           a.x + a.w > b.x &&
           a.y < b.y + b.h &&
           a.y + a.h > b.y;
}

void PongApp::handleInput(float deltaTime){
    const bool* state = SDL_GetKeyboardState(nullptr);
    //player 1
    if (state[SDL_SCANCODE_W]) m_leftPaddleY -= PADDLE_SPEED * deltaTime;
    if (state[SDL_SCANCODE_S]) m_leftPaddleY += PADDLE_SPEED * deltaTime;
    
    //player 2
    if (state[SDL_SCANCODE_UP]) m_rightPaddleY -= PADDLE_SPEED * deltaTime;
    if (state[SDL_SCANCODE_DOWN]) m_rightPaddleY += PADDLE_SPEED * deltaTime; 

    //quit
    if(state[SDL_SCANCODE_ESCAPE]) requestQuit();

    m_leftPaddleY = std::clamp(m_leftPaddleY, PADDLE_MIN_Y, PADDLE_MAX_Y);
    m_rightPaddleY = std::clamp(m_rightPaddleY, PADDLE_MIN_Y, PADDLE_MAX_Y);

}

void PongApp::resetBall(bool whoScored){
    m_ballX = (WINDOW_WIDTH - BALL_SIZE) / 2.0f;
    m_ballY = (WINDOW_HEIGHT - BALL_SIZE) / 2.0f;
    if(whoScored){
        m_ballVX = -BALL_SPEED;
    } else {
        m_ballVX = BALL_SPEED;
    }
    m_ballVY = BALL_SPEED;

    SDL_Log("%d : %d", player1Points, player2Points);
}