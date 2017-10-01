//
//  player.c
//  sdl_game1
//
//  Created by Ridhwaan on 9/29/17.
//  Copyright © 2017 Ridhwaan. All rights reserved.
//


 
#include "player.h"
#include <SDL2/SDL.h>
#include<math.h>

double convertFromRadianToDeg(double rad);

void moveTexture(SDL_Texture *playerTexture){

    
}

void controlTexture(SDL_Renderer *renderer, SDL_Texture *texture, int *mouse_x, int *mouse_y) {
    
}

double getRotationOfMouse(int mouse_x, int mouse_y, int texture_x, int texture_y) {
    
    double x = (double) (mouse_x - texture_x);
    double y = (double) (mouse_y - texture_y);
    double xycalc = y / x ;
    double rotation = atan(xycalc);
    
    
    return convertFromRadianToDeg(rotation);
}

double convertFromRadianToDeg(double rad){

    return rad * (180 / M_PI);
}

