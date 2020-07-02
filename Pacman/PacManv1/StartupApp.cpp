#include "StartupApp.h"
#include "raylib.h"
StartupApp::StartupApp()
{
}

StartupApp::~StartupApp()
{
}

void StartupApp::StartUp()
{
	InitWindow(m_screenWidth, m_screenHeight, "Hello World");
	SetTargetFPS(60);
}

void StartupApp::Run()
{
	while (!WindowShouldClose())
	{
		Update();
		Draw();
	}

}

void StartupApp::Update()
{
}

void StartupApp::Draw()
{
}

void StartupApp::ShutDown()
{
	CloseWindow();
}
