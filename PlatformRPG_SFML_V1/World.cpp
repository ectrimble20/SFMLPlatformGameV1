#include "World.h"



World::World()
{
}


World::~World()
{
}

void World::CreateNewRegion(std::string regionName)
{
	Region r(regionName);
	regions.insert(std::make_pair(regionName, r));
}
