#include "GameState.h"
#include "PauseState.h"
#include "GameOverState.h"

namespace lecture
{
	GameState::GameState(GameDataRef data)
		: mData(data)
		, mGameState(STATE_PLAYING)
		, mTurn(PLAYER_PIECE)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				mGridArray[i][j] = EMPTY_PIECE;
			}
		}
	}

	void GameState::Init()
	{
		mData->assets.LoadTexture("Pause Button", PAUSE_BUTTON);
		mData->assets.LoadTexture("Grid Sprite", GRID_SPRITE_FILEPATH);
		mData->assets.LoadTexture("X Piece", X_PIECE_FILEPATH);
		mData->assets.LoadTexture("O Piece", O_PIECE_FILEPATH);
		mData->assets.LoadTexture("X Winning Piece", X_WINNING_PIECE_FILEPATH);
		mData->assets.LoadTexture("O Winning Piece", O_WINNING_PIECE_FILEPATH);

		mBackground.setTexture(mData->assets.GetTexture("Background"));
		mPauseButton.setTexture(mData->assets.GetTexture("Pause Button"));
		mGridSprite.setTexture(mData->assets.GetTexture("Grid Sprite"));

		mPauseButton.setPosition(mData->window.getSize().x - mPauseButton.getLocalBounds().width, mPauseButton.getPosition().y);
		mGridSprite.setPosition(SCRREN_WIDTH / 2 - mGridSprite.getGlobalBounds().width / 2
			, SCREEN_HEIGHT / 2 - mGridSprite.getGlobalBounds().height / 2);

		initGridPieces();
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (mData->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				mData->window.close();
			}

			if (mData->input.IsSpriteClicked(mPauseButton, sf::Mouse::Left, mData->window))
			{
				mData->machine.AddState(IStateRef(new PauseState(mData)), false);
			}
			else if (mData->input.IsSpriteClicked(mGridSprite, sf::Mouse::Left, mData->window))
			{
				if (mGameState == STATE_PLAYING)
				{
					checkAndPlacePiece();
				}
			}
		}
	}

	void GameState::Update(float dt)
	{
		// empty on purpose
	}

	void GameState::Draw(float dt)
	{
		mData->window.clear();

		mData->window.draw(mBackground);
		mData->window.draw(mPauseButton);
		mData->window.draw(mGridSprite);

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				mData->window.draw(mGridPieces[x][y]);
			}
		}

		mData->window.display();
	}

	void GameState::initGridPieces()
	{
		sf::Vector2u tempSpriteSize = mData->assets.GetTexture("X Piece").getSize();

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				mGridPieces[x][y].setTexture(mData->assets.GetTexture("X Piece"));
				mGridPieces[x][y].setPosition(mGridSprite.getPosition().x + x * tempSpriteSize.x - 7, mGridSprite.getPosition().y + y * tempSpriteSize.y - 7);
				mGridPieces[x][y].setColor(sf::Color(255, 255, 255, 0));
			}
		}
	}

	void GameState::checkAndPlacePiece()
	{
		sf::Vector2i touchPoint = mData->input.GetMousePosition(mData->window);
		sf::FloatRect gridSize = mGridSprite.getGlobalBounds();
		sf::Vector2f gapOutsideOfGrid = sf::Vector2f((SCRREN_WIDTH - gridSize.width) / 2, (SCREEN_HEIGHT - gridSize.height) / 2);
		sf::Vector2f gridLocalTouchPos = sf::Vector2f(touchPoint.x - gapOutsideOfGrid.x, touchPoint.y - gapOutsideOfGrid.y);
		sf::Vector2f gridSectionSize = sf::Vector2f(gridSize.width / 3, gridSize.height / 3);

		int column = 1;
		int row = 1;

		if (gridLocalTouchPos.x < gridSectionSize.x)
		{
			column = 1;
		}
		else if (gridLocalTouchPos.x < 2 * gridSectionSize.x)
		{
			column = 2;
		}
		else if (gridLocalTouchPos.x < gridSize.width)
		{
			column = 3;
		}

		if (gridLocalTouchPos.y < gridSectionSize.y)
		{
			row = 1;
		}
		else if (gridLocalTouchPos.y < 2 * gridSectionSize.y)
		{
			row = 2;
		}
		else if (gridLocalTouchPos.y < gridSize.height)
		{
			row = 3;
		}

		if (mGridArray[column - 1][row - 1] == EMPTY_PIECE)
		{
			mGridArray[column - 1][row - 1] = mTurn;

			if (mTurn == PLAYER_PIECE)
			{
				mGridPieces[column - 1][row - 1].setTexture(mData->assets.GetTexture("X Piece"));
				checkPlayerHasWon(mTurn);
				mTurn = AI_PIECE;
			}
			else if (mTurn == AI_PIECE)
			{
				mGridPieces[column - 1][row - 1].setTexture(mData->assets.GetTexture("O Piece"));
				checkPlayerHasWon(mTurn);
				mTurn = PLAYER_PIECE;
			}

			mGridPieces[column - 1][row - 1].setColor(sf::Color(255, 255, 255, 255));
		}
	}

	void GameState::checkPlayerHasWon(int player)
	{
		checkThreePiecesForMatch(0, 0, 1, 0, 2, 0, player);
		checkThreePiecesForMatch(0, 1, 1, 1, 2, 1, player);
		checkThreePiecesForMatch(0, 2, 1, 2, 2, 2, player);
		checkThreePiecesForMatch(0, 0, 0, 1, 0, 2, player);

		checkThreePiecesForMatch(1, 0, 1, 1, 1, 2, player);
		checkThreePiecesForMatch(2, 0, 2, 1, 2, 2, player);
		checkThreePiecesForMatch(0, 0, 1, 1, 2, 2, player);
		checkThreePiecesForMatch(0, 2, 1, 1, 2, 0, player);

		int emptyNum = 9;

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (mGridArray[x][y] != EMPTY_PIECE)
				{
					emptyNum--;
				}
			}
		}

		if (emptyNum == 0 && (mGameState != STATE_WON) && (mGameState != STATE_LOSE))
		{
			mGameState = STATE_DRAW;
		}

		if (mGameState == STATE_DRAW || mGameState == STATE_LOSE || mGameState == STATE_WON)
		{
			// show game over
		}

		std::cout << mGameState << std::endl;
	}

	void GameState::checkThreePiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck)
	{
		if (pieceToCheck == mGridArray[x1][y1] && pieceToCheck == mGridArray[x2][y2] && pieceToCheck == mGridArray[x3][y3])
		{
			std::string winningPieceStr;

			if (pieceToCheck == O_PIECE)
			{
				winningPieceStr = "O Winning Piece";
			}
			else
			{
				winningPieceStr = "X Winning Piece";
			}

			mGridPieces[x1][y1].setTexture(mData->assets.GetTexture(winningPieceStr));
			mGridPieces[x2][y2].setTexture(mData->assets.GetTexture(winningPieceStr));
			mGridPieces[x3][y3].setTexture(mData->assets.GetTexture(winningPieceStr));

			if (pieceToCheck == PLAYER_PIECE)
			{
				mGameState = STATE_WON;
			}
			else
			{
				mGameState = STATE_LOSE;
			}
		}
	}
}