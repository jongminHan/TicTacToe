#include "MainMenuState.h"

namespace lecture
{
	MainMenuState::MainMenuState(GameDataRef data)
		: mData(data)
	{
	}

	void MainMenuState::Init()
	{
		mData->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		mData->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
		mData->assets.LoadTexture("Play Button Outer", MAIN_MENU_PLAY_BUTTON_OUTER);
		mData->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_PATH);

		mBackground.setTexture(mData->assets.GetTexture("Background"));
		mPlayButton.setTexture(mData->assets.GetTexture("Play Button"));
		mPlayButtonOuter.setTexture(mData->assets.GetTexture("Play Button Outer"));
		mTitle.setTexture(mData->assets.GetTexture("Game Title"));

		mPlayButton.setPosition((SCRREN_WIDTH / 2) - (mPlayButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (mPlayButton.getGlobalBounds().height / 2));
		mPlayButtonOuter.setPosition((SCRREN_WIDTH / 2) - (mPlayButtonOuter.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (mPlayButtonOuter.getGlobalBounds().height / 2));
		mTitle.setPosition((SCRREN_WIDTH / 2) - (mTitle.getGlobalBounds().width / 2), mTitle.getGlobalBounds().height * 0.1);
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (mData->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				mData->window.close();
			}

			if (mData->input.IsSpriteClicked(mPlayButton, sf::Mouse::Left, mData->window))
			{
				std::cout << "Go to Game Screen" << std::endl;
			}
		}
	}

	void MainMenuState::Update(float dt)
	{
		// empty on purpose
	}

	void MainMenuState::Draw(float dt)
	{
		mData->window.clear();

		mData->window.draw(mBackground);
		mData->window.draw(mPlayButton);
		mData->window.draw(mPlayButtonOuter);
		mData->window.draw(mTitle);

		mData->window.display();
	}
}