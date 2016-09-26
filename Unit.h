#pragma once

#include "GameEntity.h"

class InputComponent;
class RenderComponent;

class Unit : public GameEntity
{
	public:
		Unit(InputComponent *i, RenderComponent *g);
		~Unit();

		void update() override;
		void render() override;
};

