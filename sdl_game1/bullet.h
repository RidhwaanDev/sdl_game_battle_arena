//
//  bullet.h
//  sdl_game1
//
//  Created by Ridhwaan on 9/29/17.
//  Copyright © 2017 Ridhwaan. All rights reserved.
//

#ifndef bullet_h
#define bullet_h

#include <stdio.h>


void updateBullet(SDL_Renderer *renderer, int x_pos, int y_pos, float dt,double rotation,  SDL_Texture *textureBullet);
void addbullet();
void allocateBulletMemory();

typedef struct Bullet {
    int x;
    int y;
    bool isAlive;
    SDL_Texture *texture;
    SDL_Rect rect;
    
} Bullet;




#endif /* bullet_h */
