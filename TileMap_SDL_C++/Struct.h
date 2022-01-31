#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

using namespace std;

//Ressources pour rendu
class renderer {
private:
    SDL_Window* pWindow;
    SDL_Renderer* pRenderer;
    int winWidth = 960;
    int winHeight = 320;

public:
    //Constructeur
    renderer();//SDL_Window* pWindow, SDL_Renderer* pRenderer);

    //constructeur de copie
    renderer(renderer& rend1);

    //destructeur
    ~renderer();

    //Accesseurs
    SDL_Window* getPWindow();
    SDL_Renderer* getPRenderer();
    int getWinWidth();
    int getWinHeight();

    //Mutateurs
    void setPWindow(SDL_Window* pWindow);
    void setPRenderer(SDL_Renderer* pRenderer);

};


//Ressources pour les objets (assets) a afficher dans le rendu
class rendererObject {

private:
    SDL_Surface* pSurface;
    SDL_Texture* pTexture;

public:
    //Constructeur
    rendererObject();

    //constructeur de copie
    rendererObject(rendererObject& rendObj1);

    //destructeur
    ~rendererObject();

    //Accesseurs
    SDL_Surface* getPSureface();
    SDL_Texture* getPTexture();

    //Mutateurs
    void setPSurface(SDL_Surface* pSurface);
    void setPTexture(SDL_Texture* pTexture);

};

