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
		mData->assets.LoadFont("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
		mBackground.setTexture();
	}
}