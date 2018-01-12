#include "Tile.h"

Tile::Tile()
{
	Tile(0, 0);
}

Tile::Tile(unsigned int x, unsigned int y)
{
	Tile(x, y, TileType::AIR);
}

Tile::Tile(unsigned int x, unsigned int y, TileType t)
{
	SetProvencePosition(x, y);
	SetType(t);
}


Tile::~Tile()
{
}

std::pair<unsigned int, unsigned int> Tile::GetProvenceLocation()
{
	//think this works, not sure if I need to use std::make_pair or not for this
	return std::pair<unsigned int, unsigned int>(m_province_x, m_province_x);
}

void Tile::SetProvencePosition(unsigned int x, unsigned int y)
{
	m_province_x = x;
	m_province_x = y;
}
