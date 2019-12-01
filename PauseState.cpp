#include "PauseState.h"
#include "MainMenuState.h"

namespace lecture
{
	PauseState::PauseState(GameDataRef data)
		: mData(data)
	{
	}

	void PauseState::Init()
	{
		mData->assets.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
		mData->assets.LoadTexture("Resume Button", RESUME_BUTTON);
		mData->assets.LoadTexture("Home Button", HOME_BUTTON);

		mBackground.setTexture(mData->assets.GetTexture("Pause Background"));
		mResumeButton.setTexture(mData->assets.GetTexture("Resume Button"));
		mHomeButton.setTexture(mData->assets.GetTexture("Home Button"));

		mResumeButton.setPosition(mData->window.getSize().x / 2 - mResumeButton.getLocalBounds().width / 2, 
			mData->window.getSize().y / 3 - mResumeButton.getLocalBounds().height / 2);
		mHomeButton.setPosition(mData->window.getSize().x / 2 - mHomeButton.getLocalBounds().width / 2,
			(mData->window.getSize().y / 3) * 2 - mHomeButton.getLocalBounds().height / 2);
	}

	void PauseState::HandleInput()
	{
		sf::Event event;

		while (mData->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				mData->window.close();
			}

			if (mData->input.IsSpriteClicked(mResumeButton, sf::Mouse::Left, mData->window))
			{
				mData->machine.RemoveState();
			}

			if (mData->input.IsSpriteClicked(mHomeButton, sf::Mouse::Left, mData->window))
			{
				mData->machine.RemoveState();
				mData->machine.AddState(IStateRef(new MainMenuState(mData)), true);
			}
		}
	}

	void PauseState::Update(float dt)
	{
		// empty on purpose
	}

	void PauseState::Draw(float dt)
	{
		mData->window.clear();

		mData->window.draw(mBackground);
		mData->window.draw(mResumeButton);
		mData->window.draw(mHomeButton);

		mData->window.display();
	}
}