#include "engine/core/Application.h"

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
        m_running = true;
        return true;        
    }

    void Application::terminate(){

        onTerminate();

        if(m_window){
            SDL_DestroyWindow(m_window);
            m_window = nullptr;
        }
        
        SDL_Quit();
    }

    


    //one instant of time during the loop
    void Application::instant(){

        SDL_Event event;

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_EVENT_QUIT){
                m_running = false;
            }
        }
    }

    //main loop
    void Application::run(){

        Uint64 frames_per_second = 0;
        Uint64 lastTime = SDL_GetTicks();

        onStart();

        while(m_running){
            Uint64 currentTime = SDL_GetTicks();

             //elapsed time.
            float deltaTime = (currentTime - lastTime);        
            
            instant();
            onUpdate(deltaTime);
            onRender();
            
            //fps
            frames_per_second++;
           
            //fps counter
            if(currentTime > lastTime + 1000){
                lastTime = currentTime;
                SDL_Log("%lu frames per second", frames_per_second);
                frames_per_second = 0;
            }
        }           
    }
}//namespace engine::core