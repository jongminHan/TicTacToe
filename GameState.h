#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "IState.h"
#include "Game.h"
#include "AI.h"

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
		void checkPlayerHasWon(int turn);
		void checkThreePiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck);

		GameDataRef mData;
		sf::Sprite mBackground;
		sf::Sprite mPauseButton;
		sf::Sprite mGridSprite;
		sf::Sprite mGridPieces[3][3];

		int mGridArray[3][3];
		int mTurn;
		int mGameState;
		AI* mAI;

		sf::Clock mClock;
	};
}