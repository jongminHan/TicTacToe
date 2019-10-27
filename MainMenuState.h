#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "IState.h"
#include "Game.h"

namespace lecture
{
	class MainMenuState : public IState
	{
	public:
		MainMenuState(GameDataRef data);
		virtual ~MainMenuState() = default;
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	private:
		GameDataRef mData;
		sf::Sprite mBackground;
		sf::Sprite mPlayButton;
		sf::Sprite mPlayButtonOuter;
		sf::Sprite mTitle;
	};
}