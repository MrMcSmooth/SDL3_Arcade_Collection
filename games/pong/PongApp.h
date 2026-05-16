#pragma once
#include "engine/core/Application.h"

class PongApp : public engine::core::Application {
    public:
        PongApp();
    protected:
        void onStart() override;
        void onUpdate(float deltaTime) override;
        void onRender() override;
        void onTerminate() override;
    private:
        enum class Player {Left, Right};
        
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

        int m_player1Points = 0;
        int m_player2Points = 0;

        void handleInput(float deltaTime);

        void resetBall(Player scoredBy);
};