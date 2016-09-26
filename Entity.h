#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"

class Entity 
{
	protected:
		int dV;

		int x, y;
		int w, h;

		sf::Texture texture;
		sf::Transform transform;
		sf::RenderStates renderStates;
		sf::Rect<int> collisionRect;

		bool toBePurged;

		int direction;

	public:
		Entity();
		virtual ~Entity();

		virtual void update(sf::Time deltaT) = 0;
		virtual void draw() = 0;

		virtual bool getPurge(){return toBePurged;}

		sf::VertexArray bounds;

		//sf::Vector2f getVelocity() const {return dV;}
		sf::RenderStates getRenderStates() const { return renderStates; }
		sf::Rect<int> getCollisionRect() const { return collisionRect; }

		int getX() const { return x; }
		int getY() const { return y; }

		int getDirection() const { return direction; }
		void setDirection(int d) { direction = d; }

		enum Direction { UP, DOWN, LEFT, RIGHT };

		//Temporary for collisions
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
	private:
};