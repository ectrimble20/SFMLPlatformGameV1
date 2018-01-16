#include "Region.h"



Region::Region(std::string regionName)
{
	m_region_name = regionName;
}


Region::~Region()
{
}

void Region::BindProvince(std::string provinceName, Province p)
{
	m_provinces.insert(std::make_pair(provinceName, p));
}

void Region::UnbindProvince(std::string provinceName)
{
	m_provinces.erase(provinceName);
}

bool Region::HasProvince(std::string provinceName)
{
	if (m_provinces.count(provinceName) == 1)
	{
		return true;
	}
	return false;
}

Province Region::GetProvince(std::string provinceName)
{
	return m_provinces.at(provinceName);
}

std::map<std::string, Province> Region::GetAllProvinces()
{
	return m_provinces;
}

unsigned int Region::GetNumberOfProvinces()
{
	return m_provinces.size();
}
