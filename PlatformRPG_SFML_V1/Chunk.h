#pragma once
//Chunks are defined as 32 tile wide by 128 tile high blocks of terrain and are used to make up a Province

enum class ChunkBiome {
	GRASSLAND, FOREST, SAVANAH, LOW_HILLS, HIGH_HILLS, MOUNTAINS, MARSH, DESERT, WASTELAND
};

enum class TileType {
	AIR, BEDROCK, DIRT, STONE
};

struct Tile
{
	TileType type = TileType::AIR;
	bool blocking = false;
	bool mineable = false;
	float durability = 1.0f;
	float hitpoints = 10.0f;
};


class Chunk
{
public:
	static unsigned int CHUNK_WIDTH;
	static unsigned int CHUNK_HEIGHT;
	Chunk();
	~Chunk();
	Tile & GetTile(unsigned int x, unsigned int y);
	void AddTile(Tile& t, unsigned int x, unsigned int y);
	void UpdateBorderGroundLevels();
	unsigned int GetWestGroundLevel() { return m_westGroundLevel; };
	unsigned int GetEastGroundLevel() { return m_eastGroundLevel; };
private:
	Tile * m_tiles;
	unsigned int getIndex(unsigned int x, unsigned int y);
	//these two variables are used to tell other chunks what height this chunk starts and ends at
	//we need to know this when generating a new chunk so that they can line up.
	unsigned int m_westGroundLevel = 0;
	unsigned int m_eastGroundLevel = 0;

};

