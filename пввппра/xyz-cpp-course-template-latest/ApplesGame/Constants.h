#pragma once
#include <string>

namespace ApplesGame
{
	const std::string RESOURCES_PATH = "Resources/";
	const std::string RESOURCES_PATH2 = "Resources/Fonts/";
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	const float INITIAL_SPEED = 100.f; // Pixels per second
	const float PLAYER_SIZE = 20.f;
	const float ACCELERATION = 20.f; // Pixels per second

	//const int NUM_APPLES = 20;
	constexpr int MODE_50_APPLES = 1 << 0;   // 0001
	constexpr int MODE_FAST = 1 << 1;   // 0010
	constexpr int MODE_FINITY = 1 << 2;   // 0100

	const float APPLE_SIZE = 20.f;
	const float PAUSE_LENGTH = 3.f;
	const int NUM_ROCKS = 10;
	const float ROCK_SIZE = 20.f;
}