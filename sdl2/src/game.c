#include <stdio.h>
#include <sdl.h>
#include <SDL_timer.h>
#include <SDL_image.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define SDL_INIT_ERROR 1
#define SDL_WIN_ERROR 2
#define SDL_RENDER_ERROR 3
#define SDL_SURFACE_ERROR 4
#define SDL_TEXTURE_ERROR 5

int SDL_main(int argc, char *argv[]) {

    int err = 0;

    // Init SDL
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0 ){
        err = SDL_INIT_ERROR;
        goto ERROR_0;
    }

    // Create a window
    SDL_Window *win = SDL_CreateWindow("My Game",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        WINDOW_WIDTH,  WINDOW_HEIGHT, 0);
    if(!win) {
        err = SDL_WIN_ERROR;
        goto ERROR_1;
    }

    // Create a renderer
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer *render = SDL_CreateRenderer(win, -1, render_flags);
    if(!render) {
        err = SDL_WIN_ERROR;
        goto ERROR_2;
    }
    // Set a draw colour
    SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
    
    // Create a surface and load an image
    SDL_Surface *surface = IMG_Load("Attack1.png");
    if(!surface) {
        err = SDL_SURFACE_ERROR;
        goto ERROR_3;
    }
    
    // Load the image into the graphics hardware memory using a SDL_Texture
    SDL_Texture *tex = SDL_CreateTextureFromSurface(render, surface);
    SDL_FreeSurface(surface);
    if(!tex) {
        err = SDL_TEXTURE_ERROR;
        goto ERROR_3;
    }

    // Make a rect struct to hold the image.
    SDL_Rect dest;
    SDL_Rect src;

    // Get the dimensions of tex
    SDL_QueryTexture(tex, NULL, NULL, &src.w, &src.h);

    dest.h = (int) src.h / 5;
    dest.w = (int) src.w / 5;
    dest.x = (WINDOW_WIDTH - dest.w)/2;
    dest.y = (WINDOW_HEIGHT - dest.h)/2; 
    
    int running = 1;
    while (running) {
        SDL_Event evt;
        while(SDL_PollEvent(&evt)){
            switch(evt.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_KEYDOWN:
                    switch(evt.key.keysym.scancode) {
                        case SDL_SCANCODE_UP:
                            dest.y -= 10;
                            break;
                        case SDL_SCANCODE_DOWN:
                            dest.y += 10;
                            break;
                        case SDL_SCANCODE_LEFT:
                            dest.x -= 10;
                            break;
                        case SDL_SCANCODE_RIGHT:
                            dest.x += 10;
                            break;      
                    }
                }
            }

        // Clear the window
        SDL_RenderClear(render);

        // Draw the image to the window
        SDL_RenderCopy(render, tex, NULL, &dest);
        SDL_RenderPresent(render);

        SDL_Delay(40);
    }
 
ERROR_3:
    SDL_DestroyRenderer(render);
ERROR_2:    
    SDL_DestroyWindow(win);
ERROR_1:
    SDL_Quit();
ERROR_0:
    return err;
}













