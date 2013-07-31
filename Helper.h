
#ifndef _HELPER_CPP_
#define _HELPER_CPP_

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string Int2String(int i) {
    std::stringstream sstream;

    sstream << i;

    return sstream.str();
}

#endif // _HELPER_CPP_

