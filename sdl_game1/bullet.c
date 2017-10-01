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
#define BULLET_COUNT_INIT 20

 int bulletCount = 0;


SDL_Rect bullet_rect[BULLET_COUNT_INIT];
SDL_Rect *bullet_array;

// struct Bullet *bullet;

int x_speed = 0;

void allocateBulletMemory(){
    
  //  bullet_array = malloc(1000 * sizeof(SDL_Rect));
   // bullet = malloc(bulletCount * sizeof(struct Bullet));
}

void addbullet(){
   // printf("BULLET ADDED\n");
    bulletCount++;
    
}

void updateBullet(SDL_Renderer *renderer, int x_pos, int y_pos, float dt,double rotation, SDL_Texture *textureBullet) {
      /* for(int i = 0; i < bulletCount; i ++) {
        
        SDL_Rect bullet;
        
        bullet_rect[i] =  bullet;
        
        bullet_rect[i].x = x_pos;
        bullet_rect[i].y = y_pos;
        bullet_rect[i].w = BULLET_WIDTH;
        bullet_rect[i].h = BULLET_HEIGHT;
        
        
        SDL_RenderCopyEx(renderer, textureBullet, NULL, &bullet_rect[i], rotation, NULL, 0);

    }*/
    
    for (int i = 0; i < bulletCount; ++i) {
        
       // printf("LOOP entered  \n: %d" , i);
        SDL_Rect bullet;
        
        bullet.x = 0;
        bullet.y = 0;
        bullet.w = BULLET_WIDTH;
        bullet.h = BULLET_HEIGHT;
        
        *(bullet_array + i) = bullet;
        

       // SDL_RenderCopyEx(renderer, textureBullet, NULL, &bullet_array[i], rotation, NULL, 0);

    }
    
    
    for (int i = 0; i < bulletCount; ++i) {
        
      //  printf(" PLOOP entered : %d\n" , i);

        
        SDL_Rect *rect_bullet = (bullet_array + i);
        rect_bullet->x += 100;
        
    //    printf(" Rect entered : %d\n" , rect_bullet->x);

    }
    
    
    for (int i = 0; i < bulletCount; ++i) {
        if(bulletCount == 0){
            return;
        }
        
        printf("BULLET ADDED %d\n", i);

        Bullet b;
        b.x = x_pos;
        b.y = y_pos;
        b.isAlive = true;
        b.texture = textureBullet;
        
        SDL_Rect r;
        b.rect = r;
        r.x = b.x;
        r.y = b.y;
        
   //     bullet[i] = b;
        
        SDL_RenderCopyEx(renderer, b.texture, NULL, &b.rect, rotation, NULL, 0);

    }
    
}








