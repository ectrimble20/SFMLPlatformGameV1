#include "Province.h"



Province::Province(unsigned int width, unsigned int height)
{
	tileMap = new Tile[width * height];
}


Province::~Province()
{
}

Tile Province::GetTile(unsigned int x, unsigned int y)
{
	return Tile();
}

Tile * Province::GetNeighboringTiles(unsigned int x, unsigned int y)
{
	return nullptr;
}

Tile * Province::GetTilesUnderneith(unsigned int x, unsigned int y)
{
	return nullptr;
}
