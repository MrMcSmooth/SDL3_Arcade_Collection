#include <iostream>
#include "PongApp.h"

int main()
{
    PongApp pong;

    if(!pong.initialize()){
        return -1;
    }

    pong.run();
    pong.terminate();
    
    return 0;
}
