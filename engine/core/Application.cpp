#include "engine/core/Application.h"

Application::Application(){
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("SDL3", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
}

Application::~Application(){
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Application::instant(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_EVENT_QUIT){
            running = false;
        }
    }
}

void Application::MainLoop(){
    while(running){
        instant();                
    }
                
}
