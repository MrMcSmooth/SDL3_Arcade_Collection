#pragma once
#include <SDL3/SDL.h>

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

class Application {
    public:
        SDL_Window* window;
        bool running = true;
    
        Application();
        ~Application();

        void instant();
        void MainLoop();
};
