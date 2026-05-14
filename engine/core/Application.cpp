#include "engine/core/Application.h"



namespace engine::core {


    Application::Application(const AppConfig& config) : m_config(config){}

    Application::~Application(){

    }

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
        if(m_window){
            SDL_DestroyWindow(m_window);
            m_window = nullptr;
        }
        
        SDL_Quit();
    }

    void Application::instant(){

        SDL_Event event;

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_EVENT_QUIT){
                m_running = false;
            }
        }
    }

    void Application::run(){

        while(m_running){
            instant();                
        }
                    
    }
}//namespace engine::core