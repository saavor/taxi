#pragma once

namespace Taxi {
    struct Config
    {
        // App name
        const char* name;
        
        // App width
        int width;
        
        // App height
        int height;

        // App framerate (default is 60)
        int framerate = 60;
    };
}