#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "TileManager.h"

//Taille de la Tile
#define TileWidth 24
#define TileHeight 16

//Nombre de Tile par ligne et colone
#define NbWidth 15
#define NbHeight 13

//Nombre de tile dans le tile set
#define nbTileX 8
#define nbTileY 1

//Constructeur
TileManager::TileManager()
{
	this->tile = tile;
	this->R_dest = R_dest;
	this->R_source = R_source;
}

//Constructeur de copie
TileManager::TileManager(TileManager& T1)
{
	this->tile = T1.tile;
	this->R_dest = T1.R_dest;
	this->R_source = T1.R_source;
}

//Destructeur
TileManager::~TileManager()
{

}

//Accesseurs
rendererObject TileManager::getTile()
{
	return tile;
}

SDL_Rect TileManager::getR_dest()
{
	return R_dest;
}

SDL_Rect TileManager::getR_source()
{
	return R_source;
}

void TileManager::setTile(rendererObject tile)
{
	this->tile = tile;
}

void TileManager::setR_dest(SDL_Rect R_dest)
{
	this->R_dest = R_dest;
}

void TileManager::setR_source(SDL_Rect R_source)
{
	this->R_source = R_source;
}

void TileManager::AfficheTile(const char* map[], SDL_Surface* tileset, SDL_Surface* Window)
{
	int i, j;
	R_source.w = TileWidth;
	R_source.h = TileHeight;
	for (i = 0; i < NbWidth; i++)
	{
		for (j = 0; j < NbHeight; j++)
		{
			R_dest.x = i * TileWidth;
			R_dest.y = i * TileHeight;
			R_source.x = (map[j][i] - '0') * TileWidth;
			R_source.y = 0;
			SDL_BlitSurface(tileset, &R_source, Window, &R_dest);
		}
	}
}

void TileManager::ChargerMap_tileset(SDL_Surface* tileset, TileManager* Tile)
{
	int numtile, i, j;
	//char buf[CACHE_SIZE];  // un buffer, petite mémoire cache
	//char buf2[CACHE_SIZE];  // un buffer, petite mémoire cache
	//fscanf(F, "%s", buf); // nom du fichier
	//m->tileset = LoadImage32(buf);
	//fscanf(F, "%d %d", &m->nbtilesX, &m->nbtilesY);
	//TileWidth = 192 /nbTileX;
	//TileHeight = 16 / nbTileY;
	//m->props = malloc(m->nbtilesX * m->nbtilesY * sizeof(TileProp));
	for (j = 0, numtile = 0; j < nbTileY; j++)
	{
		for (i = 0; i < nbTileX; i++, numtile++)
		{
			Tile->R_source.w = TileWidth;
			Tile->R_source.h = TileHeight;
			Tile->R_source.x = i * TileWidth;
			Tile->R_source.y = j * TileHeight;
			//fscanf(F, "%s %s", buf, buf2);
			//m->props[numtile].plein = 0;
			//if (strcmp(buf2, "plein") == 0)
				//m->props[numtile].plein = 1;
		}
	}
}


