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

#define WIDTH 500
#define HEIGHT 500
#define SPEED 5


int main(int argc, const char * argv[]) {

    SDL_Init(SDL_INIT_VIDEO);
        
    SDL_Window *window = SDL_CreateWindow("MY GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    SDL_Rect rect;
    rect.h = 100;
    rect.w = 100;
    rect.x = (WIDTH - rect.w) /2 ;
    rect.y = (HEIGHT - rect.h) /2;
    
    
    
    bool running = true;
    
    SDL_Event event;
    
    
    float deltaTime = 0.0;
    int thisTime =0;
    int lastTime = 0;
    
    

    while(running){
        
        thisTime = SDL_GetTicks();
        deltaTime = ((float)(thisTime = lastTime)) / 1000;
        lastTime = thisTime;
        
        
        printf("this time: %d \t deltaTime: %f \t lastTime %d\n", thisTime, deltaTime,lastTime);
        
        while(SDL_PollEvent(&event)){
            
            

            if(event.type == SDL_QUIT){
                running = false;
            }
            
            if(event.type == SDL_KEYDOWN){
                
                switch(event.key.keysym.sym){
                
                case SDLK_LEFT:
                      //  printf("X position is %d \n Y positions is %d \n", rect.x,rect.y);
                            rect.x-= SPEED;
                    
                        break;
                    case SDLK_RIGHT:
                        printf("\nX position is %d \nY positions is %d \n", rect.x,rect.y);
                        if ( (WIDTH - rect.x) != rect.w) {
                            rect.x += SPEED * deltaTime;
                        }
                        break;
                    case SDLK_DOWN:
                       // printf("\nX position is %d\nY positions is %d \n \t Height diff is: %d", rect.x,rect.y,HEIGHT - rect.y);
                        if((HEIGHT - rect.y) != rect.h){
                            rect.y+= SPEED;
                        }
                        break;
                    case SDLK_UP:
                        // printf("X position is %d \n Y positions is %d \n", rect.x,rect.y);
                            rect.y-= SPEED;
                        
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
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderDrawRect(renderer,  &rect);
        SDL_RenderDrawLine(renderer, (WIDTH / 2) - 50 , (HEIGHT / 2) , WIDTH, HEIGHT);

        SDL_RenderPresent(renderer);
        
    }
    //release resources

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    
    return 0;
}



        










