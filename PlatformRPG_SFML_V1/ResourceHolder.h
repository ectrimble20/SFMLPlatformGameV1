#pragma once
#include <string>
#include "ResourceManager.h"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
/*
This is a slightly modified (and name-spaced) resource manager for SFML like objects that I pulled from a YouTuber while trying
to resolve my Font class woes.  I don't know if this is going to work how I'd like it to, but, it's a start.

Credit for this design goes to Hopson97, https://github.com/Hopson97
Specifically his SFML-Engine-2 project.
*/
class ResourceHolder
{
public:
	static ResourceHolder& get();
	static const sf::Texture& getTexture(const std::string& name);
	static const sf::Font& getFont(const std::string& name);
	static const sf::SoundBuffer& getSoundBuffer(const std::string& name);

	static void setTextureRepeat(const std::string& name, bool value);
	static void setTextureSmooth(const std::string& name, bool value);

	ResourceHolder(const ResourceHolder& other) = delete;
	ResourceHolder(ResourceHolder&& other) = delete;
	ResourceHolder& operator=(const ResourceHolder& other) = delete;
	ResourceHolder& operator=(ResourceHolder&& other) = delete;

	ResourceManager<sf::Font> fonts;
	ResourceManager<sf::Texture> textures;
	ResourceManager<sf::SoundBuffer> soundBuffers;
private:
	ResourceHolder() noexcept;
};
