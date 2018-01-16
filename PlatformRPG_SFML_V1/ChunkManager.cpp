#include "ChunkManager.h"



ChunkManager::ChunkManager()
{
}


ChunkManager::~ChunkManager()
{
}

Chunk ChunkManager::generateFlatChunk()
{
	Chunk c; //create a new empty chunk
	for (unsigned int y = 0; y < Chunk::CHUNK_HEIGHT; ++y)
	{
		for (unsigned int x = 0; x < Chunk::CHUNK_WIDTH; ++x)
		{
			Tile t;
			
			if (y < 20) {
				t.blocking = false;
				t.durability = 0.0f;
				t.hitpoints = 0.0f;
				t.mineable = false;
				t.type = TileType::AIR;
			}
			else if (y > 123)
			{
				t.blocking = true;
				t.durability = 10000.0f;
				t.hitpoints = 10000.0f;
				t.mineable = false;
				t.type = TileType::BEDROCK;
			}
			//put a single layer of dirt
			else if (y == 20) {
				t.blocking = true;
				t.durability = 1.0f;
				t.hitpoints = 5.0f;
				t.mineable = true;
				t.type = TileType::DIRT;
			}
			else {
				t.blocking = true;
				t.durability = 10.0f;
				t.hitpoints = 20.0f;
				t.mineable = true;
				t.type = TileType::STONE;
			}
			c.AddTile(t, x, y);
		}
	}
	c.UpdateBorderGroundLevels(); //should just be 20 but we'll let the chunk do it's thing.
	return c;
}

Chunk ChunkManager::generateEastNeighborChunk(Chunk & neighbor, ChunkBiomeSettings& chunkSettings)
{
	//we're going to assume we're starting with a flat "plain chunk".
	//so what we need/want to accomplish is determine how high or low we can the chunk to progress based on the neighbor
	//and the biome type.  Biomes like deserts and grassland are generally flat, so their variance rating is quite low, like 3-5
	//the variance rating for a specific biome determines how much the grounds level is allowed to vary from it's start to it's
	//finish.
	Chunk c = generateFlatChunk();
	unsigned int c_westHeight = c.GetWestGroundLevel();
	unsigned int c_eastHeight = c.GetEastGroundLevel();
	unsigned int n_westHeight = neighbor.GetWestGroundLevel();
	unsigned int n_eastHeight = neighbor.GetEastGroundLevel();

	return Chunk();
}
