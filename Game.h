#pragma once
#include <string>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

namespace lecture
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};


	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(int width, int height, std::string title);
		virtual ~Game() = default;
		void Run();

	private:
		const float dt = 1.0f / 60.0f;	// Framerate
		sf::Clock mClock;
		GameDataRef mData = std::make_shared<GameData>();
	};
}
