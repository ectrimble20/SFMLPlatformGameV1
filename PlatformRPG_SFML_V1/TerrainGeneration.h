#pragma once
#define uint unsigned int
#include "Random.h"

class TerrainGeneration
{
public:
	TerrainGeneration() = delete;
	TerrainGeneration(uint width, uint height, float roughness = 0.55f, float displacement = 50.0f);
	~TerrainGeneration();
	void printDebugMap(uint width);
private:
	uint * heightMap;
	uint m_width;
	uint m_height;
	float m_rougheness;
	uint m_initialDisplacement;
	void generateHeightMap(uint size, uint startingHeight, uint maxHeight, uint minHeight, uint variance);
};

