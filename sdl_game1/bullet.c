//
//  bullet.c
//  sdl_game1
//
//  Created by Ridhwaan on 9/29/17.
//  Copyright © 2017 Ridhwaan. All rights reserved.
//


#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>

#include "bullet.h"


#define BULLET_WIDTH  40
#define BULLET_HEIGHT 40

 int bulletCount = 0;

SDL_Rect bullet_rect[10];


void addbullet(){
    bulletCount++;

}


void updateBullet(SDL_Renderer *renderer, int x_pos, int y_pos, float dt,double rotation, SDL_Texture *textureBullet) {
    
    for(int i = 0; i < bulletCount; i ++) {
        
        SDL_Rect bullet_rect[i];
        
        bullet_rect[i].x += x_pos + 5;
        bullet_rect[i].y += y_pos;
        bullet_rect[i].w = BULLET_WIDTH;
        bullet_rect[i].h = BULLET_HEIGHT;
        
        
        SDL_RenderCopyEx(renderer, textureBullet, NULL, &bullet_rect[i], rotation, NULL, 0);

    
    }

}


