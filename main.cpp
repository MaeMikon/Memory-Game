#include<SDL.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<string>
#include<windows.h>
#include "My SDL.h"


const int SCREEN_HEIGHT=600;
const int SCREEN_WIDTH=600;
const int CARD_SIZE=SCREEN_HEIGHT/4;
SDL_Window*window;
SDL_Renderer*renderer;
SDL_Texture*background;
SDL_Texture*image1;
SDL_Texture*image2;
SDL_Event event;
SDL_Texture*current;



vector  <string > file={"Icon 1.bmp","Icon 2.bmp","Icon 3.bmp","Icon 4.bmp","Icon 5.bmp","Icon 6.bmp","Icon 7.bmp","Icon 8.bmp","Icon 1.bmp","Icon 2.bmp","Icon 3.bmp","Icon 4.bmp","Icon 5.bmp","Icon 6.bmp","Icon 7.bmp","Icon 8.bmp"};
void randomSwap(vector<string>&file)
{
    srand((unsigned)time(NULL));
    for(int i=0;i<30;i++)
    {
         int r=rand()%16;
         int c=rand()%16;
        swap(file[r],file[c]);
    }
}
string filename;
void Flip(SDL_Texture*&tex)
{
     bool isRun=true;
    while(isRun)
    {
    if(SDL_PollEvent(&event)!=0)
    {
        int x=0,y=0;
        switch(event.type)
        {


        case SDL_QUIT: isRun=false;break;
        case SDL_MOUSEBUTTONDOWN:
            x=event.button.x;
            y=event.button.y;
            x/=CARD_SIZE;
            y/=CARD_SIZE;
            tex=loadTexture(file[4*x+y],renderer);
            filename=file[4*x+y];
            x*=CARD_SIZE;
            y*=CARD_SIZE;
            renderTexture(tex,renderer,x,y,CARD_SIZE,CARD_SIZE);
            SDL_RenderPresent(renderer);
            isRun=false;break;
    }
    }
    }
}
void win()
{   SDL_RenderClear(renderer);
    SDL_Texture*win=loadTexture("congratulations.bmp",renderer);
    renderTexture(win,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
    SDL_RenderPresent(renderer);

}
void Play()
{   int count=0;
    string name1,name2;
    current=loadTexture("Board.bmp",renderer);
    renderTexture(current,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
    screenShot(renderer);
    bool isRun=true;
    while(isRun)
    {
        current=loadTexture("screenshot.bmp",renderer);
        renderTexture(current,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        SDL_RenderPresent(renderer);
        Flip(image1);
        name1=filename;
        Flip(image2);
        name2=filename;
        if(name1==name2)    {screenShot(renderer);
                             count++;                       }
        SDL_Delay(100);
        if(count==8) break;
    }
    SDL_Delay(1000);
    win();
}
void start()
{
    background=loadTexture("Start Screen.bmp",renderer);
    renderTexture(background,renderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
    SDL_RenderPresent(renderer);
    bool isRun=true;
    while(isRun)
    {
        if(SDL_PollEvent(&event)!=0)
    {
        switch(event.type)
        {


        case SDL_QUIT: isRun=false;break;
        case SDL_KEYDOWN:
            SDL_Delay(1000);
            Play();
            isRun=false;break;
        }
    }
    }
}
int main(int argc,char * argv [])
{
    randomSwap(file);
    initSDL(window,renderer);
    start();
    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}


