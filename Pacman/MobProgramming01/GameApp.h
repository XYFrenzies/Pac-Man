#pragma once

#include "raymath.h"
#include <vector>

enum MAP_ITEMS
{
	EMPTY = 0,
	WALL = 1,
	FOOD = 2,
	POWERUP = 3,
	START = 4,
	GHOST = 5
};

enum Directions
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

struct Ghost
{
	Vector2 pos;
	Vector2 dir;
	Color col;
	float speed;


};

class GameApp
{
public:

	GameApp();
	~GameApp();

	void Startup();
	void Shutdown();

	void Run();

	void Update();
	void Draw();

	void UpdateGhost(Ghost* ghost);
	void DrawGhost(Ghost* ghost);

private:

	int m_screenWidth;
	int m_screenHeight;

	int m_tileWidth;
	int m_tileHeight;

	Vector2 m_pacPos;
	Vector2 m_pacDir;

	float m_pacSpeed;

	std::vector<Ghost*> m_ghosts;

	static const int MAP_ROWS = 20;
	static const int MAP_COLS = 15;

	int m_map[MAP_ROWS][MAP_COLS] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} ,
		{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
		{1, 2, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 2, 1},
		{1, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1},
		{1, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1},
		{1, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1},
		{1, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1},
		{1, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1},
		{1, 2, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 2, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
		{1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
		{1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
		{1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1},
		{1, 2, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 2, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

};


// Programming ideas
/*

	- bullet hell
	- tank game
	- liquid simulation
	- tetris
	- pong (in scope)
	- pacman (in scope)
	- - map
	- - - empty     0
	- - - walls		1
	- - - food		2
	- - - powerup	3

	[

		[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
		[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
		[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
		[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
		[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
		[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
		[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
		[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
		[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
		[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
		[1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
		[1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1],
		[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
		[1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1],
		[1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1],
		[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
		[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],

	]


	- - player
	- - 
	- space invaders (maybe in scope)
	- render a 3d cube (); maybe in scope wiht build in raylib
	- fps (not in scope)
	- wackamol (maybe in scope)
	- snake (in scope)
	- frogger (maybe in scope)
	- duck hunt (in scope)
	- bad particle system (maybe in scope)
	- breakout (in scope)

*/




