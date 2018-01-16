#pragma once
#include "Region.h"
#include <string>
#include <map>
#include <utility>

class World
{
public:
	World();
	~World();
	void CreateNewRegion(std::string regionName);
private:
	std::map<std::string, Region> regions;
};

