#pragma once

struct SDL_Window;
struct SDL_Renderer;

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
            void requestQuit() {m_running = false;}
            

        protected:
            SDL_Window* m_window = nullptr;
            SDL_Renderer* m_renderer = nullptr;


            virtual void onStart();
            virtual void onUpdate(float deltaTime);
            virtual void onRender();
            virtual void onTerminate();

        private:
            bool m_running = false;
            AppConfig m_config;
            void tick();

    };
}//namespace engine::core