#pragma once
#include "engine/core/Application.h"

struct SDL_FRect;

class PongApp : public engine::core::Application {
    public:
        PongApp();
    protected:
        void onStart() override;
        void onUpdate(float deltaTime) override;
        void onRender() override;
        void onTerminate() override;
    private:
        static constexpr float WINDOW_WIDTH = 800.0f;
        static constexpr float WINDOW_HEIGHT = 600.0f;

        static constexpr float PADDLE_MARGIN = 25.0f;
        static constexpr float PADDLE_WIDTH = 25.0f;
        static constexpr float PADDLE_HEIGHT = 100.0f;
        static constexpr float LEFT_PADDLE_X = PADDLE_MARGIN;
        static constexpr float RIGHT_PADDLE_X = WINDOW_WIDTH - PADDLE_WIDTH - PADDLE_MARGIN;

        static constexpr float BALL_SIZE = 25.0f;

        static constexpr float PADDLE_SPEED = 300.0f;
        static constexpr float BALL_SPEED = 250.0f;   

        static constexpr float PADDLE_MIN_Y = 0.0f;
        static constexpr float PADDLE_MAX_Y = WINDOW_HEIGHT - PADDLE_HEIGHT;

        float m_leftPaddleY = (WINDOW_HEIGHT - PADDLE_HEIGHT) / 2.0f;
        float m_rightPaddleY = (WINDOW_HEIGHT - PADDLE_HEIGHT) / 2.0f;

        float m_ballX = (WINDOW_WIDTH - BALL_SIZE) / 2.0f;
        float m_ballY = (WINDOW_HEIGHT - BALL_SIZE) / 2.0f; 

        float m_ballVX = BALL_SPEED;
        float m_ballVY = BALL_SPEED;

        int player1Points = 0;
        int player2Points = 0;

        void handleInput(float deltaTime);
        void resetBall(bool whoScored);
};

       bool rectangleOverlaps(const SDL_FRect& a, const SDL_FRect& b);
