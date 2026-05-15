#include "engine/core/Application.h"
#include "SDL3/SDL.h"

namespace engine::core {


    Application::Application(const AppConfig& config) : m_config(config){}

    Application::~Application(){
        terminate();
    }

    void Application::onUpdate(float deltaTime) {}
    void Application::onStart() {}
    void Application::onRender() {}
    void Application::onTerminate() {}



    //initializes and creates window
    bool Application::initialize(){
        if(!SDL_Init(SDL_INIT_VIDEO)){
            return false;
        }

        m_window = SDL_CreateWindow(m_config.title, 
            m_config.window_width, m_config.window_height, SDL_WINDOW_RESIZABLE);
        if(!m_window){
            return false;
        }

        m_renderer = SDL_CreateRenderer(m_window, nullptr);
        if(!m_renderer){
            return false;
        }

        m_running = true;
        return true;        
    }

    void Application::terminate(){

        onTerminate();

        if(m_renderer) {
            SDL_DestroyRenderer(m_renderer);
            m_renderer = nullptr;
        }

        if(m_window){
            SDL_DestroyWindow(m_window);
            m_window = nullptr;
        }

        
        SDL_Quit();
    }

    //one tick of time during the loop
    void Application::tick(){

        SDL_Event event;

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_EVENT_QUIT){
                m_running = false;
            }
        }
    }


    //runs through main loop, call all necessar y engine functions
    //while calculating frames and deltaTime
    void Application::run(){

        int frames_per_second = 0;
        Uint64 lastTime = SDL_GetTicks();
        Uint64 fpsTimer = lastTime;

        onStart();

        while(m_running){
            Uint64 currentTime = SDL_GetTicks();

             //elapsed time.
            float deltaTime = (currentTime - lastTime) / 1000.0f; 
            lastTime = currentTime;       
            
            tick();
            onUpdate(deltaTime);
            //252, 127, 3
            SDL_SetRenderDrawColor(m_renderer, 252, 127, 3, 255);
            SDL_RenderClear(m_renderer);
            onRender();
            SDL_RenderPresent(m_renderer);
            
            //fps
            frames_per_second++;
           
            //fps counter
            if(currentTime - fpsTimer >= 1000){
                SDL_Log("%d FPS", frames_per_second);
                frames_per_second = 0;
                fpsTimer = currentTime;
            }
        }           
    }
}//namespace engine::core