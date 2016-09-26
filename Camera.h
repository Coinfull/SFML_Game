#pragma once

#include "stdafx.h"
#include "Input.h"
#include "Graphics.h"

class Camera 
{
	public:
		Camera();
		Camera(Input *i);

		~Camera();

		void updateView();

		sf::Vector2f getPosition() const { return position; }

		float *screenX;
		float *screenY;

		sf::FloatRect bounds;

		Input *i;

		sf::View initializeView();

		sf::View getView() const { return mainView; }

	private:
		sf::Vector2f position;

		sf::View mainView;

		Graphics *g;
};