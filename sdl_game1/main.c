//
//  main.c
//  sdl_game1
//
//  Created by Ridhwaan on 9/15/17.
//  Copyright © 2017 Ridhwaan. All rights reserved.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>
#include "player.h"
#include "bullet.h"
#define WIDTH 500
#define HEIGHT 500
#define TITLE "Battle Arena"
// #define SPEED 5;

const unsigned int speed = 25;
int increment = 0;
unsigned int bullet_count = 0;


int main(int argc, const char * argv[]) {
    
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    allocateBulletMemory();
    
    SDL_Window *window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    SDL_Surface *imageSurface = IMG_Load("player_battle.png");
    SDL_Surface *bulletSurface = IMG_Load("new_bullet.png");
    
    //to-do check if bullet surface is nUL
    
    if(imageSurface == NULL){
        printf("image is null ");
    }
    
    SDL_Texture *playerTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_Texture *bulletTexture = SDL_CreateTextureFromSurface(renderer, bulletSurface);
    
    
    
    int mouseX,mouseY;
    
    SDL_GetMouseState(&mouseX, &mouseY);
    
    SDL_Rect rect;
    rect.h = 100;
    rect.w = 100;
    rect.x = (WIDTH - rect.w) /2 ;
    rect.y = (HEIGHT - rect.h) /2;
    
 
    
    
    bool running = true;
    
    //Control Variables
    bool rightDown = false;
    bool leftDown = false;
    bool upDown = false;
    bool downDown = false;

    SDL_Event event;
   
    float deltaTime = 0.0;
    
    unsigned int lastTime = 0;
    unsigned int currentTime;
    
    
    while(running){
        
        currentTime = SDL_GetTicks();
        
        if(rightDown){
            rect.x += speed * deltaTime;
        }
        
        if(leftDown){
            rect.x -= speed * deltaTime;
        }
        
        if(upDown){
            rect.y -= speed * deltaTime;
        }
        
        if(downDown){
            rect.y += speed * deltaTime;
        }
        
        
        
        
        
        // if a second has passed
        if(currentTime > lastTime + 100){
            
             deltaTime = ((float)(currentTime - lastTime)) / 1000;
            // printf("delta time times speed is: %f \n",  deltaTime);
             lastTime = currentTime;
        }

   // printf("LAST TIME: %d \t DELTA TIME: %f \t NOW TIME:%d \t \n",last,deltaTime,now);
        
      
    while(SDL_PollEvent(&event)){
        
            if(event.type == SDL_QUIT){
                running = false;
            }
    
            if(event.type == SDL_KEYDOWN){
                
                switch(event.key.keysym.sym){
                
                case SDLK_LEFT:
                        downDown = false;
                        upDown = false;
                        rightDown = false;
                        
                        leftDown = true;
                      //  printf("X position is %d \n Y positions is %d \n", rect.x,rect.y);
            
                        break;
                    case SDLK_RIGHT:
                        leftDown = false;
                        upDown = false;
                        downDown = false;
                        rightDown = true;
                        
                        
                      //  printf("\nX position is %d \nY positions is %d \n", rect.x,rect.y);
                     //   if ((WIDTH - rect.x) != rect.w) {
                     //       printf("\t \t delta time times speed is: %f",  deltaTime);
                     //
                          //  rect.x +=  speed * deltaTime;
                       // }
                        break;
                    case SDLK_DOWN:
                        
                        upDown = false;
                        rightDown = false;
                        leftDown = false;
                        
                        downDown = true;
                        
                       // printf("\nX position is %d\nY positions is %d \n \t Height diff is: %d", rect.x,rect.y,HEIGHT - rect.y);
                        if((HEIGHT - rect.y) != rect.h){
                       //     rect.y+= (SPEED * deltaTime);
                        }
                        break;
                    case SDLK_UP:
                        
                        downDown = false;
                        rightDown = false;
                        leftDown = false;
                        upDown = true;
                        // printf("X position is %d \n Y positions is %d \n", rect.x,rect.y);
                       //     rect.y-= SPEED * deltaTime;
                        
                        break;
                    case SDLK_RETURN:
                        running = false;
                        break;
                        
                    case SDLK_SPACE:
                        downDown = false;
                        rightDown = false;
                        leftDown = false;
                        upDown = false;
                        
                        default:
                        printf("DEFAULT BEHAV");
                        
                
                }
            }
    }
    
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        

        SDL_SetRenderDrawColor(renderer, 255 ,0, 0, 255);
      //  SDL_RenderFillRect(renderer, &rect);
       // SDL_RenderDrawRect(renderer,  &rect);
        
        if (event.type == SDL_MOUSEBUTTONDOWN){
            
            addbullet();
        }
        
        int mouseX;
        int mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        
        double theta = getRotationOfMouse(mouseX, mouseY,rect.x,rect.y);
        
       // printf("ROTATION OF MOUSE:%f\n PLAYER COORDINATES: %d, %d", theta,rect.x,rect.y);
        
        updateBullet(renderer, rect.x, rect.y, deltaTime,theta,bulletTexture);
        
        
        SDL_RenderCopyEx(renderer, playerTexture, NULL, &rect, 0 ,NULL, 0);
         
        SDL_RenderPresent(renderer);
        
    }
    //release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(playerTexture);
    SDL_FreeSurface(imageSurface);
    IMG_Quit();
    SDL_Quit();
    
    return 0;
}






