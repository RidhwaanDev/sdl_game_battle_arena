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
#define WIDTH 500
#define HEIGHT 500
#define TITLE "Battle Arena"
// #define SPEED 5;

const unsigned int speed = 25;
unsigned int increment = 0;
unsigned int struct_linecount = 0;


void renderLine(SDL_Renderer *renderer);

struct Line {
    int x1;
    int x2;
    int y1;
    int y2;
};



struct Line lines[5];

int main(int argc, const char * argv[]) {
    
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
 
    SDL_Window *window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    SDL_Surface *imageSurface = IMG_Load("player_battle.png");
    
    if(imageSurface == NULL){
        printf("image is null ");
    }
    
    SDL_Texture *playerTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    
    
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
                        rightDown = false;
                        leftDown = true;
                      //  printf("X position is %d \n Y positions is %d \n", rect.x,rect.y);
            
                        break;
                    case SDLK_RIGHT:
                        leftDown = false;
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
                        downDown = true;
                        
                       // printf("\nX position is %d\nY positions is %d \n \t Height diff is: %d", rect.x,rect.y,HEIGHT - rect.y);
                        if((HEIGHT - rect.y) != rect.h){
                       //     rect.y+= (SPEED * deltaTime);
                        }
                        break;
                    case SDLK_UP:
                        
                        downDown = false;
                        upDown = true;
                        // printf("X position is %d \n Y positions is %d \n", rect.x,rect.y);
                       //     rect.y-= SPEED * deltaTime;
                        
                        break;
                    case SDLK_RETURN:
                        running = false;
                        break;
                        
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
            
            
         //   increment++;
          //   renderLine(renderer);
            struct_linecount++;

        }
        
      //  int i;
        
        if(struct_linecount > 50){
                struct_linecount = 0;
        }
        
        /*for ( i = 0; i < struct_linecount; i++){
        
            lines[i].x1 = i + 10;
            lines[i].x2 = i + 10;
            lines[i].y1 = i + 10;
            lines[i].y2 = i + 10;
            
            int mouseX;
            int mouseY;
            
            SDL_GetMouseState(&mouseX, &mouseY);

            SDL_RenderDrawLine(renderer, lines[i].x1, lines[i].y1, mouseX,mouseY);

        }*/
        
        int mouseX;
        int mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        
        double theta = getRotationOfMouse(mouseX, mouseY,rect.x,rect.y);
        
        SDL_Point centerOfRotation;
        centerOfRotation.x = 200;
        centerOfRotation.y = 200;
        
        printf("ROTATION OF MOUSE:%f\n PLAYER COORDINATES: %d, %d", theta,rect.x,rect.y);
        
        
        
        
        SDL_Rect dimenRect;
        dimenRect.x = WIDTH /2 ;
        dimenRect.y = HEIGHT /2 ;
        dimenRect.w = 100;
        dimenRect.h = 100;
        
       // renderLine(renderer);
     
       // SDL_RenderCopy(renderer, playerTexture, NULL, &rect);
        SDL_RenderCopyEx(renderer, playerTexture, NULL, &rect, theta ,NULL, 0);
     //   SDL_RenderDrawLine(renderer, rect.x , rect.y , rect.x +WIDTH + 50, rect.y - HEIGHT - 50);
     //   SDL_RenderDrawLine(renderer, rect.x + rect.h , rect.y , rect.x +WIDTH + 50, rect.y - HEIGHT - 50);
     //   SDL_RenderDrawLine(renderer, rect.x + rect.w , rect.y + rect.h , rect.x +WIDTH + 50, rect.y - HEIGHT - 50);
        
              
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

void renderLine(SDL_Renderer *renderer){
   struct Line line;
    line.x1 = 40;
    line.x2 = 100;
    line.y1 = 30;
    line.y2 = 20;
    
    
    SDL_SetRenderDrawColor(renderer, 180, 180, 180, 180);
    SDL_RenderDrawLine(renderer, line.x1,line.y2,line.x2,line.y2);
}


