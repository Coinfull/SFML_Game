#include "Unit.h"

#include "InputComponent.h"
#include "RenderComponent.h"

Unit::Unit(InputComponent *i, RenderComponent *g)
{
	texture.loadFromFile("gfx/player.png");

	inputComponent = i;
	renderComponent = g;

	renderStates.texture = &texture;
}

void Unit::update()
{
	if (inputComponent != nullptr)
	{
		inputComponent->update(this);

		//Update where the texture should be applied
		textureBounds[0].position = sf::Vector2f(x, y);
		textureBounds[1].position = sf::Vector2f((x + width), y);
		textureBounds[2].position = sf::Vector2f((x + width), (y + height));
		textureBounds[3].position = sf::Vector2f(x, (y + height));
	}
}

void Unit::render()
{
	if (renderComponent != nullptr)
		renderComponent->update(this);
}


Unit::~Unit()
{

}
