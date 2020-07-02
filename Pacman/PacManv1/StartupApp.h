#pragma once

#include "raymath.h"
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

	int m_screenWidth = 1080;
	int m_screenHeight = 720;
};

