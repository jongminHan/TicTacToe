#pragma once
#include <SFML/Graphics.hpp>

namespace lecture
{
	class InputManager
	{
	public:
		InputManager();
		virtual ~InputManager();
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
		sf::Vector2i GetMousePosition(sf::RenderWindow& window);
	};
}
