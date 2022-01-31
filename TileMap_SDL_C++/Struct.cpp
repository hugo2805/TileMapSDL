#pragma once
#include "Struct.h"

using namespace std;

//Constructeur 
renderer::renderer()
{
	this->pWindow = NULL;
	this->pRenderer = NULL;
}

//constructeur de copie
renderer::renderer(renderer& rend1)
{
	this->pWindow = rend1.pWindow;
	this->pRenderer = rend1.pRenderer;
}

//destructeur
renderer::~renderer()
{
}

//Accesseur
SDL_Window* renderer::getPWindow()
{
	return this->pWindow;
}

SDL_Renderer* renderer::getPRenderer()
{
	return this->pRenderer;
}

int renderer::getWinWidth()
{
	return winWidth;
}

int renderer::getWinHeight()
{
	return winHeight;
}

void renderer::setPWindow(SDL_Window* pWindow)
{
	this->pWindow = pWindow;
}

void renderer::setPRenderer(SDL_Renderer* pRenderer)
{
	this->pRenderer = pRenderer;
}

//Constructeur
rendererObject::rendererObject()
{
	this->pSurface = pSurface;
	this->pTexture = pTexture;
}

//Constructeur de copie
rendererObject::rendererObject(rendererObject& rendObj1)
{
	this->pSurface = rendObj1.pSurface;
	this->pTexture = rendObj1.pTexture;
}

//Destructeur
rendererObject::~rendererObject()
{
}
//Accesseurs
SDL_Surface* rendererObject::getPSureface()
{
	return pSurface;
}

SDL_Texture* rendererObject::getPTexture()
{
	return pTexture;
}

//Mutateurs
void rendererObject::setPSurface(SDL_Surface* pSurface)
{
	this->pSurface = pSurface;
}

void rendererObject::setPTexture(SDL_Texture* pTexture)
{
	this->pTexture = pTexture;
}
