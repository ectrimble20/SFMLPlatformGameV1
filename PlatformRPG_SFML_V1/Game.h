#pragma once
#include "SFML\Graphics.hpp"

#include <stack>
#include "ResourceHolder.h"

//forward declare states we need to start up
class GameState;


class Game
{
public:
	Game();
	~Game();
	sf::RenderWindow window;
	//NEED resource manager
	void pushState(GameState * state);
	void popState();
	void changeState(GameState * state);
	GameState * peekState();
	void Run();
private:
	std::stack<GameState *> states;
};


//abstract gameState class
class GameState {
public:
	Game * game;
	virtual void draw(const float deltaTime) = 0;
	virtual void update(const float deltaTime) = 0;
	virtual void handleInput() = 0;
};