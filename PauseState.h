#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "IState.h"
#include "Game.h"

namespace lecture
{
	class PauseState : public IState
	{
	public:
		PauseState(GameDataRef data);
		virtual ~PauseState() = default;
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	private:
		GameDataRef mData;
		sf::Sprite mBackground;
		sf::Sprite mResumeButton;
		sf::Sprite mHomeButton;
	};
}