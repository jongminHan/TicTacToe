#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "IState.h"
#include "Game.h"

namespace lecture
{
	class GameState : public IState
	{
	public:
		GameState(GameDataRef data);
		virtual ~GameState() = default;
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	private:
		GameDataRef mData;
		sf::Sprite mBackground;
		sf::Sprite mPauseButton;
		
		int mTurn;
		int mGameState;
	};
}