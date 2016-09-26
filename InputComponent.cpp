#include "InputComponent.h"

#include "GameEntity.h"

InputComponent::InputComponent(Input *i)
{
	this->i = i;
}

void InputComponent::update(GameEntity *e)
{
	Command *c = i->processInput();

	if(c != nullptr)
		c->execute(e);

	delete c;
	c = nullptr;
}

InputComponent::~InputComponent()
{

}
