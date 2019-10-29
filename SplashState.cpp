#include <sstream>
#include <iostream>
#include "SplashState.h"

namespace lecture
{
	SplashState::SplashState(GameDataRef data)
		: mData(data)
	{
	}

	void SplashState::Init()
	{
		mData->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
		mBackground.setTexture(mData->assets.GetTexture("Splash State Background"));
	}

	void SplashState::HandleInput()
	{
		sf::Event event;

		while (mData->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				mData->window.close();
			}
		}
	}

	void SplashState::Update(float dt)
	{
		if (mClock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			// Switch to the Main Menu
			mData->machine.AddState(IStateRef(new MainMenuState(mData)), true);
		}
	}

	void SplashState::Draw(float dt)
	{
		mData->window.clear(sf::Color::Red);

		mData->window.draw(mBackground);

		mData->window.display();
	}
}