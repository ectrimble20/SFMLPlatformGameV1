#include "ResourceHolder.h"
#include "ResourceManager.h"
/*
This is a slightly modified (and name-spaced) resource manager for SFML like objects that I pulled from a YouTuber while trying
to resolve my Font class woes.  I don't know if this is going to work how I'd like it to, but, it's a start.

Credit for this design goes to Hopson97, https://github.com/Hopson97
Specifically his SFML-Engine-2 project.
*/
ResourceHolder& ResourceHolder::get()
{
	static ResourceHolder holder;
	return holder;
}

ResourceHolder::ResourceHolder() noexcept
	: fonts("Fonts", "ttf"),
	textures("Images", "png"),
	soundBuffers("Audio","ogg")
{

}

const sf::Texture& ResourceHolder::getTexture(const std::string& name)
{
	return get().textures.get(name);
}

const sf::Font& ResourceHolder::getFont(const std::string& name)
{
	return get().fonts.get(name);
}

const sf::SoundBuffer& ResourceHolder::getSoundBuffer(const std::string& name)
{
	return get().soundBuffers.get(name);
}

void ResourceHolder::setTextureRepeat(const std::string & name, bool value)
{
	sf::Texture tmp = get().textures.get(name);
	tmp.setRepeated(value);
}

void ResourceHolder::setTextureSmooth(const std::string & name, bool value)
{
	sf::Texture tmp = get().textures.get(name);
	tmp.setSmooth(value);
}
