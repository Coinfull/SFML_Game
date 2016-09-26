#pragma once

#include "Civilization.h"
#include "Entity.h"

class Player : public Entity 
{
	public:
		Player();
		~Player();

		void update(sf::Time deltaT) override;
		void draw() override;
	private:
		void takeTurn();
};