//
//  player.h
//  sdl_game1
//
//  Created by Ridhwaan on 9/29/17.
//  Copyright © 2017 Ridhwaan. All rights reserved.
//

 
#ifndef player_h
#define player_h

#include <stdio.h>
#include <SDL2/SDL.h>



void moveTexture(SDL_Texture *playerTexture);
void controlTexture(SDL_Renderer *renderer, SDL_Texture *texture, int* mouse_x, int* mouse_y);
double getRotationOfMouse(int mouse_x, int mouse_y, int texture_x, int texture_y);




#endif  /* player_h */
