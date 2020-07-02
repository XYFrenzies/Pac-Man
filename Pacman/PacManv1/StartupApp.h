#pragma once

#include "raymath.h"

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

class StartupApp
{

public:
	//Constructor
	StartupApp();
	//Deconstructor
	~StartupApp();
	//Start of program
	void StartUp();
	//Runs the update and draw
	void Run();
	//Closes program
	void ShutDown();

protected:

private:
	//Draws what needs to be in the window
	void Draw();
	//Updates the window
	void Update();

	int m_screenWidth;//Widthscreen
	int m_screenHeight;//Heightscreen

	int m_tileWidth;//The width that the individual sizing of the tile will be
	int m_tileHeight;//The height that the individual sizing of the tile will be

	Vector2 m_pacPos;//The pacmans position
	Vector2 m_pacDir;//The pacmans position


	float m_pacSpeed;//The pacmans speed

	static const int MAP_ROWS = 20;//The amount of rows across

	static const int MAP_COLS = 15;//The amount of coloums long

	KeyboardKey m_leftKey = KEY_LEFT;
	KeyboardKey m_rightKey = KEY_RIGHT;
	KeyboardKey m_upKey = KEY_UP;
	KeyboardKey m_downKey = KEY_DOWN;

	//Security measures to make sure that the player cant go through the diagonal walls
	bool ifPressedUp = false;
	bool ifPressedDown = false;
	bool ifPressedLeft = false;
	bool ifPressedRight = false;



	int m_map[MAP_ROWS][MAP_COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
	{1, 2, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1},
	{1, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2, 1},
	{1, 2, 2, 2, 1, 1, 2, 1, 2, 1, 1, 2, 2, 2, 1},
	{1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 1, 2, 1},
	{1, 2, 1, 2, 2, 1, 2, 1, 1, 1, 2, 2, 2, 2, 1},
	{1, 2, 1, 1, 2, 2, 2, 5, 5, 1, 2, 1, 1, 2, 1},
	{1, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 2, 1},
	{1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 1, 2, 1},
	{1, 2, 1, 1, 2, 1, 2, 1, 1, 2, 1, 2, 2, 2, 1},
	{1, 2, 1, 1, 2, 1, 2, 2, 2, 2, 1, 2, 1, 2, 1},
	{1, 2, 1, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 1},
	{1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 1, 2, 1},
	{1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 2, 1, 1, 2, 1},
	{1, 2, 2, 2, 1, 2, 2, 4, 1, 1, 2, 2, 2, 2, 1},
	{1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1},
	{1, 2, 1, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1},
	{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

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
};

