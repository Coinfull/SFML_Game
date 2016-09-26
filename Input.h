#pragma once

#include "stdafx.h"
#include "Command.h"

class Input 
{
	public:
		Input(){}
		Input(sf::RenderWindow *window);
		~Input();

		Command *processInput();

		bool keyPressed(const char *key);
		bool keyReleased(const char *key);

	private:
		sf::RenderWindow *window;
		sf::Event event;

		Command *moveLeft;

		std::map<const char*, bool> keys;
		std::map<const char*, bool>::iterator itr;
};