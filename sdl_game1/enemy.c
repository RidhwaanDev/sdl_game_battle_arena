//
//  enemy.c
//  sdl_game1
//
//  Created by Ridhwaan on 10/5/17.
//  Copyright © 2017 Ridhwaan. All rights reserved.
//

#include "enemy.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>



//array of pointer structs
Enemy *enemy[MAX_ENEMY] = {NULL};


    void renderEnemy(SDL_Renderer *renderer, SDL_Texture *texture){
// render bullet

}

    void addEnemy(int x, int y, float dx, float dy){
        int enemy_found = -1;

        for(int i = 0; i < MAX_ENEMY; i++){
            if(enemy[i] == NULL){
                enemy_found = i;
                break;
            }
        }
        if(enemy_found >= 0){
            int find = enemy_found;
            enemy[find] = malloc(sizeof(enemy));
            
        }
        
}

void clearEnemy(int i){
    for (int i = 0; i < MAX_ENEMY; ++i) {
        if(enemy[i]){
            free(enemy[i]);
            enemy[i] = NULL;
        }
    }
}




