#include "Game.h"
#include "GameStateMainMenu.h"


Game::Game()
{
	//for now, we'll hard code this
	window.create(sf::VideoMode(800, 600), "RPG");
	window.setFramerateLimit(60);
	pushState(new GameStateMainMenu(this));
}


Game::~Game()
{
	//clean up any states
	while (!states.empty())
	{
		popState();
	}
}


void Game::pushState(GameState * state)
{
	states.push(state);
}

void Game::popState()
{
	delete states.top();
	states.pop();
	return;
}

void Game::changeState(GameState * state)
{
	if (!states.empty())
	{
		popState();
	}
	pushState(state);
}

GameState * Game::peekState()
{
	if (states.empty()) {
		return nullptr;
	}
	return states.top();
}

void Game::Run()
{
	//start game clock
	sf::Clock clock;
	//setup game window
	//setup initial gameState - the starting state, loads in everything the other states will need
	//start state is complete at this point, move on to mainMenuState
	//main menu runs until an option is selected
	//loadState, optionsState, creditsState, etc
	//will be launched from the main menu.

	//main game loop
	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float deltaTime = elapsed.asSeconds();
		if (peekState() == nullptr) continue; //no state active.....
		peekState()->handleInput();
		peekState()->update(deltaTime);
		window.clear(sf::Color::Black); //clear the buffer
		peekState()->draw(deltaTime); //I don't know that I actually need.. wait yeah I do, need delta for animations durr
		window.display(); //draw zee screen.
	}
}
