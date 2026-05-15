#pragma once
#include "SDL3/SDL_render.h"
#include <SDL3/SDL.h>
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_video.h"

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

namespace engine::core{
    
    struct AppConfig {
        const char* title = "AppWindow";
        int window_width = 800;
        int window_height = 600;
    };


    class Application {
        public:      
            Application(const AppConfig& config);
            ~Application();

            bool initialize();
            void run();
            void terminate();

        protected:
            SDL_Window* m_window = nullptr;
            SDL_Renderer* m_renderer = nullptr;

            virtual void onStart();
            virtual void onUpdate(float deltaTime);
            virtual void onRender();
            virtual void onTerminate();

        private:
            bool m_running;
            AppConfig m_config;
            void instant();
            void update();
    };
}//namespace engine::core