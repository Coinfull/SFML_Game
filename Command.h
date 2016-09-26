#pragma once

#include "GameEntity.h"

class Command
{
	public:
		Command(){}
		virtual ~Command(){}

		virtual void execute(GameEntity *e) = 0;
};

class MoveCommand : public Command
{
	public:
		explicit MoveCommand(GameEntity::Direction d) { this->d = d; }
		~MoveCommand(){}

		void execute(GameEntity *e) override 
		{
			switch(d){
				case GameEntity::UP:
					e->moveUp();
					break;
				case GameEntity::DOWN:
					e->moveDown();
					break;
				case GameEntity::LEFT:
					e->moveLeft();
					break;
				case GameEntity::RIGHT:
					e->moveRight();
					break;
				default:
					//uhhh
					break;
			}
		}

	private:
		GameEntity::Direction d;
};

