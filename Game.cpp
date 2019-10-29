#include "Game.h"
#include "SplashState.h"

namespace lecture
{
	Game::Game(int width, int height, std::string title)
	{
		mData->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		mData->machine.AddState(IStateRef(new SplashState(mData)));
		Run();
	}

	void Game::Run()
	{
		float newTime;
		float frameTime;
		float interpolation;

		float currentTime = mClock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (mData->window.isOpen())
		{
			mData->machine.ProcessStateChanges();
			newTime = mClock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				mData->machine.GetActiveState()->HandleInput();
				mData->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			mData->machine.GetActiveState()->Draw(interpolation);
		}
	}
}
