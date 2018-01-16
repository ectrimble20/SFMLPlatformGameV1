#include "Chunk.h"

unsigned int Chunk::CHUNK_WIDTH = 32;
unsigned int Chunk::CHUNK_HEIGHT = 128;

Chunk::Chunk()
{
	m_tiles = new Tile[Chunk::CHUNK_WIDTH * Chunk::CHUNK_HEIGHT];
}


Chunk::~Chunk()
{
	delete[] m_tiles;
}

Tile & Chunk::GetTile(unsigned int x, unsigned int y)
{
	unsigned int idx = getIndex(x, y);
	return m_tiles[idx];
}

void Chunk::AddTile(Tile & t, unsigned int x, unsigned int y)
{
	unsigned int idx = getIndex(x, y);
	m_tiles[idx] = t;
}

void Chunk::UpdateBorderGroundLevels()
{
	//for X = 0 and X = 31, we need to walk the Y axis from 20+ until we find something that isn't air.
	bool westFound = false;
	bool eastFound = false;
	for (unsigned int y = 0; y < Chunk::CHUNK_WIDTH; y++)
	{
		//we're finished
		if (westFound && eastFound) {
			break;
		}
		if (!westFound) {
			Tile tmp = GetTile(0, y);
			if (tmp.type != TileType::AIR) {
				m_westGroundLevel = y;
				westFound = true;
			}
		}
		if (!eastFound) {
			Tile tmp = GetTile(31, y);
			if (tmp.type != TileType::AIR) {
				m_eastGroundLevel = y;
				eastFound = true;
			}
		}
	}
}

unsigned int Chunk::getIndex(unsigned int x, unsigned int y)
{
	return ((Chunk::CHUNK_WIDTH * y) + x);
}
