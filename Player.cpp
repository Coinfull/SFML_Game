#include "Player.h"

Player::Player()
{
	x = 320; w = 64;
	y = 240; h = 64;

	dV = 120;

	texture.loadFromFile("gfx/player.png");

	toBePurged = false;

	bounds[0].color = sf::Color::Red;
	bounds[1].color = sf::Color::Blue;
	bounds[2].color = sf::Color::Green;
	bounds[3].color = sf::Color::Cyan;

	collisionRect = sf::Rect<int>(x, y, w, h);

	direction = 0;
}

void Player::update(sf::Time deltaT)
{
	//Only allowed to move in one direction at a time. No Diagonals
	/*if(in->keyPressed("Up")){
		y -= (dV * deltaT.asSeconds());
		direction = UP;
		collisionRect.top -= (dV * deltaT.asSeconds());
	}else if(in->keyPressed("Down")){
		y += (dV * deltaT.asSeconds());
		direction = DOWN;
		collisionRect.top += (dV * deltaT.asSeconds());
	}else if(in->keyPressed("Left")){
		x -= (dV * deltaT.asSeconds());
		direction = LEFT;
		collisionRect.left -= (dV * deltaT.asSeconds());
	}else if(in->keyPressed("Right")){
		x += (dV * deltaT.asSeconds());
		direction = RIGHT;
		collisionRect.left += (dV * deltaT.asSeconds());
	}
	*/

	//Update all vertex positions
	bounds[0].position = sf::Vector2f(x, y);
	bounds[1].position = sf::Vector2f((x + w), y);
	bounds[2].position = sf::Vector2f((x + w), (y + h));
	bounds[3].position = sf::Vector2f(x, (y + h));

	renderStates.texture = &texture;
}

//Deprecated
void Player::draw()
{
	
}

void Player::takeTurn()
{
	//System will pass priority

	//Process Action que
}

Player::~Player()
{

}