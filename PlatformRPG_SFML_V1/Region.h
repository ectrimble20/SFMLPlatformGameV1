#pragma once
#include <map>
#include <string>
#include "Province.h"

class Region
{
public:
	Region() = delete;
	Region(std::string regionName);
	~Region();
	void BindProvince(std::string provinceName, Province p);
	void UnbindProvince(std::string provinceName);
	bool HasProvince(std::string provinceName);
	Province GetProvince(std::string provinceName);
	std::map<std::string, Province> GetAllProvinces();
	unsigned int GetNumberOfProvinces();
private:
	std::map<std::string, Province> m_provinces;
	unsigned int m_world_coord_x;
	unsigned int m_world_coord_y;
	std::string m_region_name;
};

