#include <iostream>
#include "engine/core/Application.h"

int main()
{
    engine::core::AppConfig config;
    config.title = "Game";
    config.window_width = 800;
    config.window_height = 600;

    engine::core::Application app(config);
    if(!app.initialize()){
        return -1;
    }

    app.run();
    
    return 0;
}
