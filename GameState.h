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
		void initGridPieces();

		void checkAndPlacePiece();

		GameDataRef mData;
		sf::Sprite mBackground;
		sf::Sprite mPauseButton;
		sf::Sprite mGridSprite;
		sf::Sprite mGridPieces[3][3];

		int mGridArray[3][3];
		int mTurn;
		int mGameState;
	};
}