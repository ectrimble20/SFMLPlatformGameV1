#pragma once
/*
This is a slightly modified (and name-spaced) resource manager for SFML like objects that I pulled from a YouTuber while trying
to resolve my Font class woes.  I don't know if this is going to work how I'd like it to, but, it's a start.

Credit for this design goes to Hopson97, https://github.com/Hopson97
Specifically his SFML-Engine-2 project.
*/
#include <unordered_map>
#include <string>
#include <iostream>
template<typename Resource>
class ResourceManager
{
public:
	ResourceManager(const std::string& directory, const std::string& extension)
		: m_directory("Resources/" + directory + "/"),
		m_extension("." + extension)
	{};

	const Resource& get(const std::string& name)
	{
		if (!exists(name))
		{
			add(name);
		}
		return m_resources.at(name);
	}
	bool exists(const std::string& name) const
	{
		return m_resources.find(name) != m_resources.end();
	}
			
private:
	//adds a new resource, does not handle failures
	void add(const std::string& name)
	{
		auto pathString = getFilePath(name);
		Resource r;
		if (!r.loadFromFile(pathString)) {
			//just so I know this failed
			std::cout << "ERROR:  Failed to load " << pathString << std::endl;
		}
		else {
			std::cout << "Loaded " << pathString << std::endl; //so I know what loaded
		}
		m_resources.emplace(name, r);
	}
	//builds a file path around the name of a file, if your files name is "myfile", this will return
	//whatever you defined as directory and extension as: Resources/path/to/myfile.extension
	std::string getFilePath(const std::string& name)
	{
		return m_directory + name + m_extension;
	}
	const std::string m_directory;
	const std::string m_extension;
	std::unordered_map<std::string, Resource> m_resources;

};
