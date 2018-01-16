#pragma once
#include "Chunk.h"

/*
Utility class designed to allow for chunks to be built/loaded/modifed without having any knowledge of how the
inner workings of a chunk actually work.

So here's the think about chunks/provinces/world and how they relate.

The higherarchy is:
World -has-> Provinces -made-of-> Chunks -made-of->Tiles

Worlds are stored in the Resources/Data/Worlds directory.

A world is made up of files for the regions.  Each province is in a file called "ProvinceName.prv"

Province files are flat text files, there's no real point in trying to obsfucate the data, and it just complicates things so we'll worry about that at some other point in time.

So each province file contains a set of Chunk data.  Chunks, and provinces are designed to be linear, meaning going from one province to another should be similar from going one
chunk to another.

Chunks are built based upon a provinces Biome type.  For instance, a Forest biome will have a lot of grass, some water, and lots of trees.

Biomes only effect the surface, once you're about 5-10 tiles deep in the world, the biome controls no longer matter and underground generation for resources and what not
takes effect.

All chunks have the same "height" rules applied to them.

Max height is 128, the width is 32.

The top 20 levels are ALWAYS air.
The bottom 5 levels are ALWAYS unbreakable bedrock.
The base ground level is at 80, so on a completely flat chunk, it will be air from 0 (top) to 40, then ground, then underground down to 123, then 5 levels of bedrock

*/
struct ChunkBiomeSettings
{
	//Allowed range from 0->variance that the height of a chunk can vary compared to it's neighbor
	unsigned int heightVariance;
	//thickness (average) of the top layer (dirt/sand/etc) of ground for a biome before we start reaching stone/ore/etc
	unsigned int averageGroundThickness;
	//eventually we'll have settings for ore spawns, trees, etc
};


class ChunkManager
{
public:
	ChunkManager();
	~ChunkManager();
private:
	Chunk generateFlatChunk();
	Chunk generateEastNeighborChunk(Chunk &neighbor, ChunkBiomeSettings& chunkSettings);
};

