#pragma once
#include <map>
#include <SFML/Graphics.hpp>

namespace lecture
{
	class AssetManager
	{
	public:
		AssetManager() = default;
		virtual ~AssetManager() = default;

		void LoadTexture(std::string name, std::string fileName);
		sf::Texture& GetTexture(std::string name);

		void LoadFont(std::string name, std::string fileName);
		sf::Font& GetFont(std::string name);
	private:
		std::map<std::string, sf::Texture> mTextures;
		std::map<std::string, sf::Font> mFonts;
	};
}