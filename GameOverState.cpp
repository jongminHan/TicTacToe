#include "GameOverState.h"
#include "GameState.h"
#include "MainMenuState.h"

namespace lecture
{
	GameOverState::GameOverState(GameDataRef data)
		: mData(data)
	{
	}

	void GameOverState::Init()
	{
		mData->assets.LoadTexture("Retry Button", RETRY_BUTTON);
		mData->assets.LoadTexture("Home Button", HOME_BUTTON);

		mRetryButton.setTexture(mData->assets.GetTexture("Retry Button"));
		mHomeButton.setTexture(mData->assets.GetTexture("Home Button"));

		mRetryButton.setPosition(mData->window.getSize().x / 2 - mRetryButton.getLocalBounds().width / 2,
			mData->window.getSize().y / 3 - mRetryButton.getLocalBounds().height / 2);
		mHomeButton.setPosition(mData->window.getSize().x / 2 - mHomeButton.getLocalBounds().width / 2,
			(mData->window.getSize().y / 3) * 2 - mHomeButton.getLocalBounds().height / 2);
	}

	void GameOverState::HandleInput()
	{
		sf::Event event;

		while (mData->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				mData->window.close();
			}

			if (mData->input.IsSpriteClicked(mRetryButton, sf::Mouse::Left, mData->window))
			{
				mData->machine.AddState(IStateRef(new GameState(mData)), true);
			}

			if (mData->input.IsSpriteClicked(mHomeButton, sf::Mouse::Left, mData->window))
			{
				mData->machine.RemoveState();
				mData->machine.AddState(IStateRef(new MainMenuState(mData)), true);
			}
		}
	}

	void GameOverState::Update(float dt)
	{
		// empty on purpose
	}

	void GameOverState::Draw(float dt)
	{
		mData->window.clear(sf::Color::Red);

		mData->window.draw(mRetryButton);
		mData->window.draw(mHomeButton);

		mData->window.display();
	}
}