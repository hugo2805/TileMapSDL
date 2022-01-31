#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Window.h"
#include "Struct.h"
#include "TileManager.h"

using namespace std;

void handleEvents(bool* close);

 const char* map[] = {
	"000000000000000",
	"000000000000000",
	"000000000000000",
	"000000000000000",
	"100000000111110",
	"000000000000000",
	"000000000000000",
	"000000000000000",
	"003400022220022",
	"005600000000000",
	"005600000000000",
	"005600000000000",
	"777777777777777"};

int main(int argc, char** argv)
{
	renderer rendu;
	bool close = false;
	SDL_Surface* tileset = nullptr;;
	SDL_Surface Window;
	TileManager Obj_Tile;



	initWindow(&rendu);

	if (rendu.getPWindow())
	{
		tileset = IMG_Load("../Asset/tileset.png");

		while (!close)
		{
			//Appel de la fonction de vérification des evenements
			handleEvents(&close);

			if (tileset)
			{
			//Effacement du rendu précédent
			SDL_RenderClear(rendu.getPRenderer());

			Obj_Tile.AfficheTile(map, tileset, &Window);

			//Mise à jour du rendu
			SDL_RenderPresent(rendu.getPRenderer());
			//Délai pour obtenir un taux de rafraichissement de 60FPS
			SDL_Delay(1000 / 60);
			}
			else
			{
				printf("Tileset n'as pas pu se charger !");
				SDL_Quit();
				system("pause");
				exit(-1);
			}


			

		}
	}
		//Destruction du rendu
		SDL_DestroyRenderer(rendu.getPRenderer());
		//Destruction de la surface
		SDL_FreeSurface(tileset);
		SDL_Quit();

	return 0;
}


void handleEvents(bool* close)
{
	//Detection de l'input de sortie du programme
    SDL_Event events;

    while (SDL_PollEvent(&events)) {

        switch (events.type) {
        case SDL_QUIT:
            *close = true;
            break;
        }
    }
}