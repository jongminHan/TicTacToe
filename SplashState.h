#pragma once
#include "Game.h"
#include "MainMenuState.h"

namespace lecture
{
	class SplashState : public IState
	{
	public:
		SplashState(GameDataRef data);
		virtual ~SplashState() = default;
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef mData;
		sf::Clock mClock;
		sf::Sprite mBackground;
	};
}