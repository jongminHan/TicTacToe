#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <array>
#include "Game.h"
#include "DEFINITIONS.h"
#include <iostream>

namespace lecture
{
	class AI
	{
	public:
		AI(int playerPiece, GameDataRef data);
		void PlacePiece(int(*gridArray)[3][3], sf::Sprite gridPieces[3][3], int* gameState);

	private:
		void checkSection(int x1, int y1, int x2, int y2, int X, int Y, int pieceToCheck, int(*gridArray)[3][3], sf::Sprite gridPieces[3][3]);
		void checkIfPieceIsEmpty(int X, int Y, int(*gridArray)[3][3], sf::Sprite gridPieces[3][3]);

		int mAiPiece;
		int mPlayerPiece;

		std::vector<std::array<int, 6>> mCheckMatchVector;
		GameDataRef mData;
	};
}