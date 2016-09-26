#include "Input.h"

Input::Input(sf::RenderWindow *window){
	this->window = window;

	keys["Escape"] = false;
}

Command *Input::processInput(){
	while (window->pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window->close();
				break;
			case sf::Event::Resized:
				window->setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height))); //Resize Render region
				break;
			default:
				break;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		return new MoveCommand(GameEntity::UP);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		return new MoveCommand(GameEntity::DOWN);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return new MoveCommand(GameEntity::LEFT);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		return new MoveCommand(GameEntity::RIGHT);

	return nullptr;

	/*while(window->pollEvent(event)){
		switch(event.type){
			case sf::Event::Closed:
				window->close();	
				//run = false;
				break;
			case sf::Event::KeyPressed:
				switch(event.key.code){
					case sf::Keyboard::Escape:
					//	run = false;
						break;
					case sf::Keyboard::W:
						return new MoveCommand(GameEntity::UP);
					case sf::Keyboard::S:
						return new MoveCommand(GameEntity::DOWN);
					case sf::Keyboard::A:
						return new MoveCommand(GameEntity::LEFT);
					case sf::Keyboard::D:
						return new MoveCommand(GameEntity::RIGHT);
					case sf::Keyboard::Delete:
						keys["Delete"] = true;
						break;
					case sf::Keyboard::Up:
						keys["Up"] = true;
						break;
					case sf::Keyboard::Down:
						keys["Down"] = true;
						break;
					case sf::Keyboard::Left:
						keys["Left"] = true;
						break;
					case sf::Keyboard::Right:
						keys["Right"] = true;
						break;
					default:
						break;
				}
				break;
			case sf::Event::Resized:
				window->setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height))); //Resize Render region
				break;
			default:
				break;
		}
	} */
}

bool Input::keyPressed(const char *key){
	itr = keys.find(key);

	if(itr != keys.end()) //Found it
		return itr->second; //Return the Value (true)
	else
		return false; //Key is up
}

bool Input::keyReleased(const char *key){
	itr = keys.find(key);

	if(itr != keys.end()) //Found it
		return !itr->second; //Return the Value (false)
	else
		return true; //Key is down
}


Input::~Input(){
	keys.clear();
}