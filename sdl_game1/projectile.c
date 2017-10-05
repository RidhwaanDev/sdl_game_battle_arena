//
//  projectile.c
//  sdl_game1
//
//  Created by Ridhwaan on 10/1/17.
//  Copyright © 2017 Ridhwaan. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>

#include "projectile.h"

#define BULLET_HEIGHT 25
#define BULLET_WIDTH 25

#define BULLET_VELOC 5

#define TOTAL_BULLET 50



 Bullet *bullet[TOTAL_BULLET] = {NULL};

void enterBullet(float x, float y, float dx , float dy){

    int found = -1;
    //if the i'th bullet is empty, we can allocate memoery for it.
    for (int i = 0; i < TOTAL_BULLET; ++i) {
        if (bullet[i] == NULL){
            found = i;
            break;
        }
    }
    if(found >= 0){
        int i = found;
        bullet[i] = malloc(sizeof(bullet));
        bullet[i]->x = x;
        bullet[i]->y = y;
        bullet[i]->delta_x = dx;
        bullet[i]->delta_y = dy;
    }
}

void clearBullet(int i ){
    if(bullet[i]){
        free(bullet[i]);
        bullet[i] = NULL;
    }
}

void renderBullet(SDL_Renderer *renderer, SDL_Texture *texture){
    for (int i = 0; i < TOTAL_BULLET; ++i) {
        if(bullet[i]){
            
                bullet[i]->x += bullet[i]->delta_x;
                bullet[i]->y += bullet[i]->delta_y;
                SDL_Rect rect = {bullet[i]->x , bullet[i]->y, BULLET_HEIGHT , BULLET_WIDTH};
                SDL_RenderCopy(renderer, texture, NULL, &rect);
        

        }
    }
 
}





