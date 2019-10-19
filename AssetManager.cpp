#include "AssetManager.h"
#include <cassert>

namespace lecture
{
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;
		bool bIsLoaded = tex.loadFromFile(fileName);
		assert(("Texture isn't loaded.", bIsLoaded));
		if (bIsLoaded)
		{
			mTextures[name] = tex;
		}
	}

	sf::Texture& AssetManager::GetTexture(std::string name)
	{
		return mTextures.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;

		if (font.loadFromFile(fileName))
		{
			mFonts[name] = font;
		}
	}
	
	sf::Font& AssetManager::GetFont(std::string name)
	{
		return mFonts.at(name);
	}
}