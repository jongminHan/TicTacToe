#include "GameState.h"
#include "PauseState.h"
#include "GameOverState.h"

namespace lecture
{
	GameState::GameState(GameDataRef data)
		: mData(data)
		, mGameState(STATE_PLAYING)
		, mTurn(PLAYER_PIECE)
		, mGridArray{ EMPTY_PIECE }
	{
	}

	void GameState::Init()
	{
		mData->assets.LoadTexture("Pause Button", PAUSE_BUTTON);
		mData->assets.LoadTexture("Grid Sprite", GRID_SPRITE_FILEPATH);
		mData->assets.LoadTexture("X Piece", X_PIECE_FILEPATH);
		mData->assets.LoadTexture("O Piece", O_PIECE_FILEPATH);

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
				mGridPieces[x][y].setColor(sf::Color(255, 255, 255, 255));
			}
		}
	}
}