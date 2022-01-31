#pragma once
#include "Struct.h"

using namespace std;

class TileManager
{
private :
	rendererObject tile;
	SDL_Rect R_dest{};
	SDL_Rect R_source{};


public :

	//Constructeur
	TileManager();

	//constructeur de copie
	TileManager(TileManager& T1);

	//destructeur
	~TileManager();

	//Accesseurs
	rendererObject getTile();
	SDL_Rect getR_dest();
	SDL_Rect getR_source();

	//Mutateurs
	void setTile(rendererObject tile);
	void setR_dest(SDL_Rect R_dest);
	void setR_source(SDL_Rect R_source);

	void AfficheTile(const char* map[], SDL_Surface* tileset, SDL_Surface* Window);

	void ChargerMap_tileset(SDL_Surface* tileset, TileManager* Tile)

};