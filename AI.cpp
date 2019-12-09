#include "AI.h"

namespace lecture
{
	AI::AI(int playerPiece, GameDataRef data)
		: mPlayerPiece(playerPiece)
		, mData(data)
	{
		if (playerPiece == O_PIECE)
		{
			mAiPiece = X_PIECE;
		}
		else
		{
			mAiPiece = O_PIECE;
		}

		mCheckMatchVector.push_back({ 0, 2, 1, 2, 2, 2 });
		mCheckMatchVector.push_back({ 0, 2, 0, 1, 0, 0 });
		mCheckMatchVector.push_back({ 0, 2, 1, 1, 2, 0 });
		mCheckMatchVector.push_back({ 2, 2, 1, 2, 0, 2 });
		mCheckMatchVector.push_back({ 2, 2, 2, 1, 2, 0 });
		mCheckMatchVector.push_back({ 2, 2, 1, 1, 0, 0 });
		mCheckMatchVector.push_back({ 0, 0, 0, 1, 0, 2 });
		mCheckMatchVector.push_back({ 0, 0, 1, 0, 2, 0 });
		mCheckMatchVector.push_back({ 0, 0, 1, 1, 2, 2 });
		mCheckMatchVector.push_back({ 2, 0, 2, 1, 2, 2 });
		mCheckMatchVector.push_back({ 2, 0, 1, 0, 0, 0 });
		mCheckMatchVector.push_back({ 2, 0, 1, 1, 0, 2 });
		mCheckMatchVector.push_back({ 0, 1, 1, 1, 2, 1 });
		mCheckMatchVector.push_back({ 1, 2, 1, 1, 1, 0 });
		mCheckMatchVector.push_back({ 2, 1, 1, 1, 0, 1 });
		mCheckMatchVector.push_back({ 1, 0, 1, 1, 1, 2 });
		mCheckMatchVector.push_back({ 0, 1, 2, 1, 1, 1 });
		mCheckMatchVector.push_back({ 1, 2, 1, 0, 1, 1 });
		mCheckMatchVector.push_back({ 0, 2, 2, 0, 1, 1 });
		mCheckMatchVector.push_back({ 2, 2, 0, 0, 1, 1 });
		mCheckMatchVector.push_back({ 0, 2, 2, 2, 1, 2 });
		mCheckMatchVector.push_back({ 0, 0, 2, 0, 1, 0 });
		mCheckMatchVector.push_back({ 0, 2, 0, 0, 0, 1 });
		mCheckMatchVector.push_back({ 2, 2, 2, 0, 2, 1 });
	}

	void AI::PlacePiece(int(*gridArray)[3][3], sf::Sprite gridPieces[3][3], int* gameState)
	{
		try
		{
			for (int i = 0; i < mCheckMatchVector.size(); i++)
			{
				checkSection(mCheckMatchVector[i][0], mCheckMatchVector[i][1], mCheckMatchVector[i][2], mCheckMatchVector[i][3], mCheckMatchVector[i][4], mCheckMatchVector[i][5],
					AI_PIECE, gridArray, gridPieces);
			}

			for (int i = 0; i < mCheckMatchVector.size(); i++)
			{
				checkSection(mCheckMatchVector[i][0], mCheckMatchVector[i][1], mCheckMatchVector[i][2], mCheckMatchVector[i][3], mCheckMatchVector[i][4], mCheckMatchVector[i][5],
					PLAYER_PIECE, gridArray, gridPieces);
			}

			checkIfPieceIsEmpty(1, 1, gridArray, gridPieces);

			checkIfPieceIsEmpty(0, 2, gridArray, gridPieces);
			checkIfPieceIsEmpty(2, 2, gridArray, gridPieces);
			checkIfPieceIsEmpty(0, 0, gridArray, gridPieces);
			checkIfPieceIsEmpty(2, 0, gridArray, gridPieces);

			checkIfPieceIsEmpty(1, 2, gridArray, gridPieces);
			checkIfPieceIsEmpty(0, 1, gridArray, gridPieces);
			checkIfPieceIsEmpty(2, 1, gridArray, gridPieces);
			checkIfPieceIsEmpty(1, 0, gridArray, gridPieces);

			
		}
		catch (int error)
		{

		}

		*gameState = STATE_PLAYING;
	}

	void AI::checkSection(int x1, int y1, int x2, int y2, int X, int Y, int pieceToCheck, int(*gridArray)[3][3], sf::Sprite gridPieces[3][3])
	{
		if ((*gridArray)[x1][y1] == pieceToCheck && (*gridArray)[x2][y2] == pieceToCheck)
		{
			if ((*gridArray[X][Y]) == EMPTY_PIECE)
			{
				(*gridArray)[X][Y] = AI_PIECE;
				gridPieces[X][Y].setTexture(mData->assets.GetTexture("O Piece"));
				gridPieces[X][Y].setColor(sf::Color(255, 255, 255, 255));

				throw -1;
			}
		}
	}

	void AI::checkIfPieceIsEmpty(int X, int Y, int(*gridArray)[3][3], sf::Sprite gridPieces[3][3])
	{
		if ((*gridArray)[X][Y] == EMPTY_PIECE)
		{
			(*gridArray)[X][Y] = AI_PIECE;
			gridPieces[X][Y].setTexture(mData->assets.GetTexture("O Piece"));
			gridPieces[X][Y].setColor(sf::Color(255, 255, 255, 255));

			throw -2;
		}
	}
}