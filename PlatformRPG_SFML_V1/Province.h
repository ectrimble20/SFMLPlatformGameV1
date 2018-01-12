#pragma once
#include "Tile.h"

/*
TODO's for this class:

We need a "generation" function, though!!! this might be done outside of the provence.

This really should just be a data container, not really handle any logic.

*/

class Province
{
public:
	Province(unsigned int width, unsigned int height);
	~Province();
	Tile GetTile(unsigned int x, unsigned int y);
	//I'm not sure about these two, I'm never going to really need to know all adjacent tiles.
	//Reality is I'm only really ever going to need to know tiles under a certain collider.
	//So if my "player" is 32x32 I need to know what tiles he's on, and what tiles he's behind or colliding with in front/behind.
	Tile * GetNeighboringTiles(unsigned int x, unsigned int y);
	Tile * GetTilesUnderneith(unsigned int x, unsigned int y);
private:
	//these are just for reference when something is asking for size parameters
	unsigned int m_width;
	unsigned int m_height;
	Tile * tileMap;
};

