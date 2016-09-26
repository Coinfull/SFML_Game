#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class Component;
class InputComponent;
class RenderComponent;

class GameEntity
{
	public:
		GameEntity();
		virtual ~GameEntity();

		virtual void update() = 0;
		virtual void render() = 0;

		sf::FloatRect getBounds() const;

		float getX() const { return x; }
		float getY() const { return y; }
		float getWidth() const { return width; }
		float getHeight() const { return height; }

		void addComponent(Component *c);

		enum Direction { UP, DOWN, LEFT, RIGHT };

		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();

		sf::RenderStates getRenderStates() const { return renderStates; }
		sf::VertexArray getTextureBounds() const { return textureBounds; }
	protected:
		std::vector<Component *> components;

		sf::Texture texture;
		sf::FloatRect bounds;

		float x, y, width, height;
		float moveSpeed;

		sf::VertexArray textureBounds;

		int direction;

		sf::RenderStates renderStates;

		InputComponent *inputComponent;
		RenderComponent *renderComponent;
};

