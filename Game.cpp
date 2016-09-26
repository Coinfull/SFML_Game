#include "Game.h"

//Graphics *Game::g = Graphics::getInstance();

Game::Game() 
{
	g = Graphics::getInstance();
	i = Input(g->getWindow());

	p = std::make_shared<Player>();	//Player needs an Input object to know keypresses, at least currently
	camera = Camera(&i);

	running = true;

	timeSinceLastUpdate = sf::Time::Zero;
}

void Game::work()
{
	World world("data/cheatMapv2.tmx");
	//World world("data/test16Map.tmx", "gfx/test16sheet.png");

	//world.setPlayer(p);

	std::shared_ptr<GameEntity> e = std::make_shared<Unit>(new InputComponent(&i), new RenderComponent());

	//e->addComponent();

	world.addEntity(e);

	while(running)
	{
		sf::Time elapsedTime = clock.restart();

		timeSinceLastUpdate += elapsedTime;

		while (timeSinceLastUpdate > timePerFrame) 
		{
			timeSinceLastUpdate -= timePerFrame;

			camera.updateView(); //Updates the view based on the Camera shift

			world.Update(timePerFrame);
			//mm.update(timePerFrame); //Animates Tiles
		}

		g->clearWindow(); //Clear the buffer

		world.Render(camera);

		g->updateWindow(); //Show the screen
	}
}

Game::~Game()
{

}