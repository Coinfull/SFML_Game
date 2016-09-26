#include "Entity.h"


//TODO: Remove this class
Entity::Entity()
{
	bounds = sf::VertexArray(sf::Quads, 4);

	bounds[0].position = sf::Vector2f(x, y);
	bounds[0].texCoords = sf::Vector2f(0, 0);

	bounds[1].position = sf::Vector2f((x + w), y);
	bounds[1].texCoords = sf::Vector2f(64,0);

	bounds[2].position = sf::Vector2f((x + w), (y + h));
	bounds[2].texCoords = sf::Vector2f(64, 64);

	bounds[3].position = sf::Vector2f(x, (y + h));
	bounds[3].texCoords = sf::Vector2f(0, 64);

	toBePurged = false;

	dV = 1;
	
	//int direction = 0;
}

//+ 1 and - 1 To make sure the entity is comepletely out of the object
void Entity::moveUp()
{
	y -= 1;
	collisionRect.top -= 1;
}

void Entity::moveDown()
{
	y += 1;
	collisionRect.top += 1;
}

void Entity::moveLeft()
{
	x -= 1;
	collisionRect.left -= 1;
}

void Entity::moveRight()
{
	x += 1;
	collisionRect.left += 1;
}

Entity::~Entity() 
{

}