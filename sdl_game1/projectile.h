//
//  projectile.h
//  sdl_game1
//
//  Created by Ridhwaan on 10/1/17.
//  Copyright © 2017 Ridhwaan. All rights reserved.
//

#ifndef projectile_h
#define projectile_h

#include <stdio.h>



void renderBullet(SDL_Renderer *renderer, SDL_Texture *texture);
void clearBullet(int i );
void enterBullet(float x, float y, float dx, float dy);

typedef struct
{
    float x;
    float y;
    float delta_x;
    float delta_y;
    
} Bullet;

#endif /* projectile_h */
