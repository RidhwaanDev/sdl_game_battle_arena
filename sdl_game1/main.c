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
#include "math.h"
#include <SDL2/SDL_image.h>
#include "player.h"
#include "projectile.h"
#define WIDTH 500
#define HEIGHT 500
#define TITLE "Battle Arena"

// #define SPEED 5;

const unsigned int speed = 25;
int increment = 0;
unsigned int bullet_count = 0;

float dx,dy;

double distanceCharToMouse(int char_x1 , int char_y1, int mouse_x1, int mouse_y2);
double getXChange(double theta, double distance);
double getYChange(double theta , double distance);

int main(int argc, const char * argv[]) {
    
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    
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
    free(imageSurface);
    free(bulletSurface);
    
    
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
                
                case SDLK_a:
                        downDown = false;
                        upDown = false;
                        rightDown = false;
                        
                        leftDown = true;
                      //  printf("X position is %d \n Y positions is %d \n", rect.x,rect.y);
            
                        break;
                    case SDLK_d:
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
                    case SDLK_s:
                        
                        upDown = false;
                        rightDown = false;
                        leftDown = false;
                        
                        downDown = true;
                        
                       // printf("\nX position is %d\nY positions is %d \n \t Height diff is: %d", rect.x,rect.y,HEIGHT - rect.y);
                        if((HEIGHT - rect.y) != rect.h){
                       //     rect.y+= (SPEED * deltaTime);
                        }
                        break;
                    case SDLK_w:
                        
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
                    /*    downDown = false;
                        rightDown = false;
                        leftDown = false;
                        upDown = false;*/
                        
                        enterBullet( (rect.x + rect.w) - 50 , (rect.y) + 50 , dx / 5 , dy / 5);
                        
                    case SDLK_e:
                        

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
        
        if (event.type == SDL_MOUSEBUTTONUP){
           // enterBullet(rect.x, rect.y, 3);
          
        }
        
      
        SDL_GetMouseState(&mouseX, &mouseY);
        
        double theta = getRotationOfMouse(mouseX, mouseY,rect.x,rect.y);
        double x = distanceCharToMouse(rect.x, rect.y, mouseX, mouseY);
        
          dx = getXChange(theta, x);
          dy = getYChange(theta, x);
      
    //      printf("ChangeX is %f, Change Y is %f \n",dx,dy);
         printf("Theta is %f \n", -1 * theta);

          fflush(stdout);
        
       // printf("ROTATION OF MOUSE:%f\n PLAYER COORDINATES: %d, %d", theta,rect.x,rect.y);
        
        renderBullet(renderer, bulletTexture);
        SDL_RenderDrawLine(renderer, rect.x + (rect.w / 2), rect.y +( rect.h / 2), mouseX, mouseY);
        
        SDL_SetRenderDrawColor(renderer, 85 ,73, 23, 76);
        SDL_RenderDrawLine(renderer, 0, HEIGHT / 2, WIDTH, HEIGHT / 2);
        SDL_RenderDrawLine(renderer, WIDTH / 2, 0, WIDTH/2, HEIGHT);



        
        SDL_RenderCopyEx(renderer, playerTexture, NULL, &rect, theta ,NULL, 0);
         
        SDL_RenderPresent(renderer);
        
    }
    //release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(playerTexture);
  //  SDL_FreeSurface(imageSurface);
    IMG_Quit();
    SDL_Quit();
    
    return 0;
}

double distanceCharToMouse(int char_x1 , int char_y1, int mouse_x1, int mouse_y1){
    //distance formula
    int x_naut = mouse_x1 - char_x1;
    int x = x_naut * x_naut;
    
    int y_naut = mouse_y1 - char_y1;
    int y = y_naut * y_naut;
    int final_comp = x + y;
    
    return (double)sqrt(final_comp);
    
}

double getXChange (double theta, double distance) {
    double x =( cos(theta) * distance) / 10;
    
    printf("COSX CHANGE METHO: %f\n ", x);
    fflush(stdout);
    
    return x;
}

double getYChange(double theta, double distance){
    double y =  (sin(theta) * distance ) / 10;

    printf("SINY CHANGE METHO: %f\n ", y);
    fflush(stdout);

    return y;
}











