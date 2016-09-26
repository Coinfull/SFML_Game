#pragma once

#include "Input.h"
#include "Component.h"

class GameEntity;

class InputComponent : public Component
{
	public:
		InputComponent(Input *i);
		~InputComponent();

		void update(GameEntity *e) override;

	private:
		Input *i;
};

