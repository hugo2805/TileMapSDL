#pragma once
#pragma once
#include "Struct.h"

using namespace std;

int initWindow(renderer* rendu)
{
    SDL_Window* win;
    SDL_Renderer* rend;
    rendu->setPWindow(NULL);
    rendu->setPRenderer(NULL);

    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stdout, "�chec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return 0;
    }
    else
    {
        /* Cr�ation de la fen�tre */
        win = SDL_CreateWindow("TILE MAP HUGO EITEL", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            rendu->getWinWidth(),
            rendu->getWinHeight(),
            SDL_WINDOW_SHOWN);
        rendu->setPWindow(win);
        rend = SDL_CreateRenderer(rendu->getPWindow(), -1, 0);
        rendu->setPRenderer(rend);
    }
    return 1;
}