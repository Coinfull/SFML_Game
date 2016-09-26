#pragma once

#include "Input.h"
#include "World.h"
#include "Player.h"
#include "Camera.h"
#include "Unit.h"
#include "InputComponent.h"
#include "RenderComponent.h"

//Main class and will serve as a mediator between things

class Game
{
	public:
		Game();
		~Game();

		void work();
	private:
		Input i;
		Graphics *g;
		Camera camera;

		std::shared_ptr<Player> p;

		sf::Clock clock;
		sf::Time timeSinceLastUpdate;

		float time;
		sf::Time deltaTime;
		float currentTime;

		bool running;
};