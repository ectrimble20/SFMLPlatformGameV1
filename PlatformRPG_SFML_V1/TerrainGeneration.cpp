#include "TerrainGeneration.h"
#include <cmath>
#include <random>
#include <iostream>

TerrainGeneration::TerrainGeneration(uint width, uint height, float roughness, float displacement)
{
	m_width = width;
	m_height = height;
	m_rougheness = roughness;
	//create our new index height map
	heightMap = new uint[width];
	//init values
	for (uint i = 0; i < (width); i++)
	{
		heightMap[i] = 0; //default value
	}
	//ready to go, launch fractal generation
	generateHeightMap(width, 128 - 30, 128 - 20, 128 - 60, 2);
	printDebugMap(width);
}


TerrainGeneration::~TerrainGeneration()
{
	delete[] heightMap;
}

void TerrainGeneration::generateHeightMap(uint size, uint startingHeight, uint maxHeight, uint minHeight, uint variance)
{
	int nVariance = variance * -1;
	uint h = startingHeight; //need something we can adjust
	int lastMovement = 0;
	for (uint i = 0; i < size; i++)
	{
		if (h >= maxHeight)
		{
			heightMap[i] = maxHeight - 1;
			h -= 1;
		}
		else if (h <= minHeight)
		{
			heightMap[i] = minHeight + 1;
			h += 1; //force it upwards
		}
		else
		{
			int movementGradient = Random::get().intInRange(nVariance, variance);
			h += movementGradient;
			heightMap[i] = h;
		}
	}
}

void TerrainGeneration::printDebugMap(uint width)
{
	for (uint i = 0; i < width; i++)
	{
		uint s = heightMap[i];
		for (uint x = 0; x < s; x++)
		{
			std::cout << "#";
		}
		std::cout << std::endl;
	}
}