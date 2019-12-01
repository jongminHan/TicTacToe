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
	}

	void GameState::Init()
	{
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
				//mData->machine.AddState(IStateRef(new PauseState(mData)), false);
				mData->machine.AddState(IStateRef(new GameOverState(mData)), true);
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