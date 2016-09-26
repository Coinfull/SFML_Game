#include "World.h"

World::World(const char *worldFile)
{
	g = Graphics::getInstance();

	MapLoader loader;

	map = loader.loadMap(worldFile);

	collisionObjects = map->getCollisionObjects();
}

void World::Update(sf::Time deltaT)
{
	UpdateEntities(deltaT);
}

void World::UpdateEntities(sf::Time deltaT)
{
	for (auto i = entities.size() - 1; i != (std::vector<int>::size_type) - 1; --i)
	{
		entities[i]->update();

		//Loop through objects
		for (int j = 0; j < collisionObjects.size(); ++j) {
			//Check if an entity is inside the object
			if (entities[i]->getBounds().intersects(collisionObjects[j])) {
				//Move the entity back based on which way it came
				/*switch (entities[i]->getDirection()) {
					case 0:
						entities[i]->moveDown();
						break;
					case 1:
						entities[i]->moveUp();
						break;
					case 2:
						entities[i]->moveRight();
						break;
					case 3:
						entities[i]->moveLeft();
						break;
					default:
						break;
				}*/
			}
		}
	}
}

//TODO: Fix camera dependencies
void World::Render(Camera c)
{
	states.texture = map->getTilesetTexture();

	//Draw layers 1 and 2

	if (c.bounds.intersects(map->getVA1().getBounds()))
		g->draw(map->getVA1(), states);
	else
		std::cout << "Not drawn" << std::endl;

	g->draw(map->getVA2(), states);
	
	RenderEntities(c);

	//Render Quads
	#if DEBUG_RENDER
		sf::RectangleShape recta;

		recta.setPosition(sf::Vector2f(p->getCollisionRect().left, p->getCollisionRect().top));
		recta.setSize(sf::Vector2f(64, 64));

		recta.setFillColor(sf::Color(100, 250, 50));

		g->draw(recta);

		for (auto i =  collisionObjects.size() - 1; i != (std::vector<int>::size_type) - 1; --i) {
			sf::RectangleShape rect2;

			rect2.setPosition(sf::Vector2f(collisionObjects[i].left, collisionObjects[i].top));
			rect2.setSize(sf::Vector2f(collisionObjects[i].width, collisionObjects[i].height));

			g->draw(rect2);
		}
	#endif

	//Draw layer 3
	g->draw(map->getVA3(), states);
}

void World::RenderEntities(Camera c)
{
	for (auto i = entities.size() - 1; i != (std::vector<int>::size_type) - 1; --i)
	{
		//if (entities[i]->getBounds().intersects(c.bounds)) {
			entities[i]->render();
		//}
	}
}

void World::addEntity(std::shared_ptr<GameEntity> entity)
{
	entities.push_back(entity);
}

World::~World()
{

}