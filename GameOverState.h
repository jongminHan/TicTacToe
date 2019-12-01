#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "IState.h"
#include "Game.h"

namespace lecture
{
	class GameOverState : public IState
	{
	public:
		GameOverState(GameDataRef data);
		virtual ~GameOverState() = default;
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	private:
		GameDataRef mData;
		sf::Sprite mRetryButton;
		sf::Sprite mHomeButton;
	};
}