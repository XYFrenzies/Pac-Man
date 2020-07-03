#include "StartupApp.h"
#include "raylib.h"
StartupApp::StartupApp() : m_pacDir(), m_pacPos(), m_screenWidth(), m_screenHeight(), m_tileWidth(), m_tileHeight(), m_pacSpeed()
{
}

StartupApp::~StartupApp()
{
}

void StartupApp::StartUp()
{
	m_screenWidth = MAP_COLS * 30;
	m_screenHeight = MAP_ROWS * 30;


	InitWindow(m_screenWidth, m_screenHeight, "Hello World");
	SetTargetFPS(60);

	m_pacPos.x = 0;
	m_pacPos.y = 0;
	m_pacDir.x = 0;
	m_pacDir.y = 0;


	m_tileWidth = m_screenWidth / MAP_COLS;
	m_tileHeight = m_screenHeight / MAP_ROWS;

	m_pacSpeed = 2;

	for (int y = 0; y < MAP_ROWS; y++)
	{
		for (int x = 0; x < MAP_COLS; x++)
		{
			if (m_map[y][x] == START)
			{
				m_pacPos.x = x * m_tileWidth;
				m_pacPos.y = y * m_tileHeight;
			}
		}
	}
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
	// what tile index is pacman on?
	int currentIndexX = (m_pacPos.x + m_tileWidth * 0.5f) / m_tileWidth;
	int currentIndexY = (m_pacPos.y + m_tileHeight * 0.5f) / m_tileHeight;


	// what tile index is packman on next tile?
	int nextIndexX = currentIndexX + m_pacDir.x;
	int nextIndexY = currentIndexY + m_pacDir.y;

	//If the upkey is pressed but hasnt been pressed before
	if (IsKeyPressed(m_upKey) && ifPressedUp == false)
	{
		ifPressedUp = true;//The player is moving up
		ifPressedDown = false;
		ifPressedLeft = false;
		ifPressedRight = false;
		//If either other direction is being pressed atm.
		if ((ifPressedDown == true || ifPressedLeft == true || ifPressedRight == true) && m_map[nextIndexY][nextIndexX] == WALL)
		{
			m_pacDir.y = 0;
			m_pacDir.x = 0;
			while (m_pacPos.y != currentIndexY * m_tileHeight)
			{
				m_pacDir.y = 0;
				m_pacDir.x = 0;
				if(m_pacPos.y > currentIndexY * m_tileHeight)
					m_pacPos.y -= 1;
				if (m_pacPos.y < currentIndexY* m_tileHeight)
					m_pacPos.y += 1;
				Draw();
			}

			return;
		}
		//If the movement is going to collid with a wall.
		if (m_map[nextIndexY][nextIndexX] == WALL)
		{
			while (m_pacPos.y != currentIndexY * m_tileHeight)
			{
				m_pacDir.y = 0;
				m_pacDir.x = 0;
				if (m_pacPos.y > currentIndexY* m_tileHeight)
					m_pacPos.y -= 1;
				if (m_pacPos.y < currentIndexY * m_tileHeight)
					m_pacPos.y += 1;
				Draw();
			}
			m_pacDir.y = 0;
			m_pacDir.x = 0;
			return;
		}
		//Increases the direction
		m_pacDir = {0, -1};

	}
	//If the downkey is pressed but has not been pressed before.
	else if (IsKeyPressed(m_downKey) && ifPressedDown == false)
	{
		ifPressedUp = false;
		ifPressedDown = true;//The player is moving down
		ifPressedLeft = false;
		ifPressedRight = false;
		//If any of the other keys have not been pressed.
		if ((ifPressedUp == true || ifPressedLeft == true || ifPressedRight == true) && m_map[nextIndexY][nextIndexX] == WALL)
		{
			m_pacDir.y = 0;
			m_pacDir.x = 0;
			while (m_pacPos.y != currentIndexY * m_tileHeight)
			{
				m_pacDir.y = 0;
				m_pacDir.x = 0;
				if (m_pacPos.y > currentIndexY* m_tileHeight)
					m_pacPos.y -= 1;
				if (m_pacPos.y < currentIndexY * m_tileHeight)
					m_pacPos.y += 1;
				Draw();
			}

			return;
		}
		//If the direction is going to collid with a wall.
		if (m_map[nextIndexY][nextIndexX ] == WALL)
		{
			while (m_pacPos.y != currentIndexY * m_tileHeight)
			{
				m_pacDir.y = 0;
				m_pacDir.x = 0;
				if (m_pacPos.y > currentIndexY* m_tileHeight)
					m_pacPos.y -= 1;
				if (m_pacPos.y < currentIndexY * m_tileHeight)
					m_pacPos.y += 1;
				Draw();
			}
			m_pacDir.y = 0;
			m_pacDir.x = 0;
			return;
		}
		//Moves in the direction
		m_pacDir = { 0, 1 };

	}
	//If the leftkey is pressed but has not been pressed before.
	else if (IsKeyPressed(m_leftKey) && ifPressedLeft == false)
	{
		ifPressedUp = false;
		ifPressedDown = false;
		ifPressedLeft = true;//The player is moving left
		ifPressedRight = false;
		//If any of the other keys have not been pressed.
		if ((ifPressedDown == true || ifPressedRight == true || ifPressedUp == true) && m_map[nextIndexY][nextIndexX] == WALL)
		{
			m_pacDir.y = 0;
			m_pacDir.x = 0;
			while (m_pacPos.x != currentIndexX * m_tileWidth)
			{
				m_pacDir.y = 0;
				m_pacDir.x = 0;
				if (m_pacPos.x > currentIndexX* m_tileWidth)
					m_pacPos.x -= 1;
				if (m_pacPos.x < currentIndexX * m_tileWidth)
					m_pacPos.x += 1;
				Draw();
			}

			return;
		}
		//If the direction is going to collid with a wall.
		if (m_map[nextIndexY][nextIndexX] == WALL)
		{
			while (m_pacPos.x != currentIndexX * m_tileWidth)
			{
				m_pacDir.y = 0;
				m_pacDir.x = 0;
				if (m_pacPos.x > currentIndexX* m_tileWidth)
					m_pacPos.x -= 1;
				if (m_pacPos.x < currentIndexX * m_tileWidth)
					m_pacPos.x += 1;
				Draw();
			}
			m_pacDir.y = 0;
			m_pacDir.x = 0;
			return;
		}
		//Moves in the direction
		m_pacDir = { -1, 0 };

	}	
	//If the rightkey is pressed but has not been pressed before.
	else if (IsKeyPressed(m_rightKey) && ifPressedRight == false)
	{
		ifPressedUp = false;
		ifPressedDown = false;
		ifPressedLeft = false;
		ifPressedRight = true;//The player is moving right
		//If any of the other keys have not been pressed.
		if ((ifPressedDown == true || ifPressedLeft == true || ifPressedUp == true) && m_map[nextIndexY][nextIndexX] == WALL)
		{
			m_pacDir.y = 0;
			m_pacDir.x = 0;
			while (m_pacPos.x != currentIndexX * m_tileWidth)
			{
				m_pacDir.y = 0;
				m_pacDir.x = 0;
				if (m_pacPos.x > currentIndexX* m_tileWidth)
					m_pacPos.x -= 1;
				if (m_pacPos.x < currentIndexX * m_tileWidth)
					m_pacPos.x += 1;
				Draw();
			}

			return;
		}
		//If the direction is going to collid with a wall.
		if (m_map[nextIndexY][nextIndexX] == WALL)
		{
			while (m_pacPos.x != currentIndexX * m_tileWidth)
			{
				m_pacDir.y = 0;
				m_pacDir.x = 0;
				if (m_pacPos.x > currentIndexX* m_tileWidth)
					m_pacPos.x -= 1;
				if (m_pacPos.x < currentIndexX * m_tileWidth)
					m_pacPos.x += 1;
				Draw();
			}
			m_pacDir.y = 0;
			m_pacDir.x = 0;
			return;
		}
		//Moves in the direction
		m_pacDir = { 1, 0 };

	}

	m_pacPos.x += m_pacDir.x * m_pacSpeed;
	m_pacPos.y += m_pacDir.y * m_pacSpeed;


	//Checks if the food exists
	if (m_map[currentIndexY][currentIndexX] == FOOD)
	{
		m_map[currentIndexY][currentIndexX] = EMPTY;
		score += 100;
	}
	//Checks if its near a way.
	if (m_map[nextIndexY][nextIndexX] == WALL)
	{
		m_pacDir.x = 0;
		m_pacDir.y = 0;
		m_pacPos.x = currentIndexX * m_tileWidth;
		m_pacPos.y = currentIndexY * m_tileHeight;
	}

}

void StartupApp::Draw()
{
	BeginDrawing();

	ClearBackground(BLACK);

	int tw = m_tileWidth;//TileWidth
	int th = m_tileHeight;//TileHeight
	int hw = tw / 2; //HalfWidth
	int hh = th / 2; //HalfHeight





	for (int y = 0; y < MAP_ROWS; y++)
	{
		for (int x = 0; x < MAP_COLS; x++)
		{
			int xPos = x * tw;
			int yPos = y * th;
			int tileID = m_map[y][x];

			if (tileID == WALL)
			{
				DrawRectangle(xPos, yPos, tw, th, WHITE);
			}
			if (tileID == FOOD)
			{
				DrawRectangle(xPos + hw, yPos + hh, tw / 5, th / 5, YELLOW);
			}
		}
	}
	DrawText(FormatText("Score: %i", score), 10, 10, 20, BLUE);
	// deraw packman
	DrawCircle(
		m_pacPos.x + tw * 0.5f,
		m_pacPos.y + th * 0.5f,
		tw * 0.5f - 3,
		Color({ 255, 255, 0, 255 })
	);

	EndDrawing();
}

void StartupApp::ShutDown()
{
	CloseWindow();
}
