#include "GameEntity.h"

#include "InputComponent.h"
#include "RenderComponent.h"

GameEntity::GameEntity()
{
	x = 320; y = 240;
	width = 64; height = 64;

	bounds.left = x;
	bounds.top = y;
	bounds.width = width;
	bounds.height = height;

	textureBounds = sf::VertexArray(sf::Quads, 4);

	textureBounds[0].position = sf::Vector2f(x, y);
	textureBounds[0].texCoords = sf::Vector2f(0, 0);

	textureBounds[1].position = sf::Vector2f((x + width), y);
	textureBounds[1].texCoords = sf::Vector2f(64, 0);

	textureBounds[2].position = sf::Vector2f((x + width), (y + height));
	textureBounds[2].texCoords = sf::Vector2f(64, 64);

	textureBounds[3].position = sf::Vector2f(x, (y + height));
	textureBounds[3].texCoords = sf::Vector2f(0, 64);

	moveSpeed = 3;
}

void GameEntity::addComponent(Component *c)
{
	components.push_back(c);
}

sf::FloatRect GameEntity::getBounds() const 
{
	return bounds;
}

void GameEntity::moveUp()
{
	y -= moveSpeed;
	bounds.top -= moveSpeed;
}

void GameEntity::moveDown()
{
	y += moveSpeed;
	bounds.top += moveSpeed;
}

void GameEntity::moveLeft()
{
	x -= moveSpeed;
	bounds.left -= moveSpeed;
}

void GameEntity::moveRight()
{
	x += moveSpeed;
	bounds.left += moveSpeed;
}

GameEntity::~GameEntity()
{

}

