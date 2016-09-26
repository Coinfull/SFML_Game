#include "Camera.h"

Camera::Camera()
{
}

Camera::Camera(Input *i)
{
	this->screenX = screenX;
	this->screenY = screenY;

	g = Graphics::getInstance();

	screenX = &g->viewW;
	screenY = &g->viewH;

	g->setView(initializeView());

	position = sf::Vector2f(*screenX, *screenY);

	bounds.left = position.x;
	bounds.top = position.y;
	bounds.width = *screenX;
	bounds.height = *screenY;

	this->i = i;
}

void Camera::updateView() 
{
	if (i->keyPressed("W"))
		position.y -= 10;    //There should probably be a deltaT in there somewhere
	if (i->keyPressed("S"))
		position.y += 10;
	if (i->keyPressed("A"))
		position.x -= 10;
	if (i->keyPressed("D"))
		position.x += 10;

	bounds.left = position.x;
	bounds.top = position.y;
	bounds.width = *screenX;
	bounds.height = *screenY;

	mainView.reset(sf::FloatRect(150, 200, *screenX, *screenY));
	g->setView(mainView);
}

sf::View Camera::initializeView() 
{
	mainView.reset(sf::FloatRect(0, 0, *screenX, *screenY));
	mainView.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

	return mainView;
}

Camera::~Camera() 
{

}
