#pragma once
#include <utility>

class Tile
{
public:
	enum TileType
	{
		AIR, GRASS, DIRT, STONE, WATER, SAND, SNOW, CLAY
	};
	Tile();
	Tile(unsigned int x, unsigned int y);
	Tile(unsigned int x, unsigned int y, TileType t);
	~Tile();
	TileType GetType() { return m_type; };
	std::pair<unsigned int, unsigned int> GetProvenceLocation();
	void SetType(TileType t) { m_type = t; };
	void SetProvencePosition(unsigned int x, unsigned int y);
private:
	TileType m_type;
	unsigned int m_province_x;
	unsigned int m_province_y;
};

