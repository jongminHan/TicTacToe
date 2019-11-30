#include "GameState.h"

namespace lecture
{
	GameState::GameState(GameDataRef data)
		: mData(data)
	{
	}

	void GameState::Init()
	{
		mGameState = STATE_PLAYING;
		mTurn = PLAYER_PIECE;

		mData->assets.LoadTexture("Pause Button", PAUSE_BUTTON);

		mBackground.setTexture(mData->assets.GetTexture("Background"));
		mPauseButton.setTexture(mData->assets.GetTexture("Pause Button"));

		mPauseButton.setPosition(mData->window.getSize().x - mPauseButton.getLocalBounds().width, mPauseButton.getPosition().y);
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
				std::cout << "Pause the Game" << std::endl;
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

		mData->window.display();
	}
}