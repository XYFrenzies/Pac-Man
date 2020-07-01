
#include "GameApp.h"
#include "raylib.h"

GameApp::GameApp() : m_screenWidth(), m_screenHeight(), m_tileWidth(), m_tileHeight(), m_pacPos(), m_pacDir(), m_pacSpeed()
{

}
GameApp::~GameApp()
{

}

void GameApp::Startup()
{
    m_screenWidth = MAP_COLS * 30;
    m_screenHeight = MAP_ROWS * 30;

    InitWindow(m_screenWidth, m_screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);

    m_pacPos.x = 0;
    m_pacPos.y = 0;
    m_pacDir.x = 0;
    m_pacDir.y = 0;
    
    m_tileWidth = m_screenWidth / MAP_COLS;
    m_tileHeight = m_screenHeight / MAP_ROWS;

    m_pacSpeed = 10;

    for (int y = 0; y < MAP_ROWS; y++)
    {
        for (int x = 0; x < MAP_COLS; x++)
        {
            if (m_map[y][x] == START)
            {
                m_pacPos.x = x * m_tileWidth;
                m_pacPos.y = y * m_tileHeight;
            }
            else if (m_map[y][x] == GHOST)
            {
                // TODO: create a ghost
                Ghost *ghost = new Ghost();
                ghost->pos = { x * (float)m_tileWidth, y * (float)m_tileHeight };
                ghost->dir = { 1, 0 };
                ghost->speed = m_pacSpeed / 2;
                ghost->col = { 255, 0, 0, 255 };
                m_ghosts.push_back(ghost);
            }
        }
    }
}


void GameApp::Shutdown()
{
    // loop throug the ghosts collection and delete them
    for (auto& ghost : m_ghosts)
    {
        delete ghost;
    }
    m_ghosts.clear();

    CloseWindow();
}

void GameApp::Run()
{
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        Update();
        Draw();
    }
}

void GameApp::Update()
{
    if (IsKeyPressed(KEY_UP))
    {
        m_pacDir = { 0, -1 };

    }
    if (IsKeyPressed(KEY_DOWN))
    {
        m_pacDir = { 0, 1 };
    }
    if (IsKeyPressed(KEY_LEFT))
    {
        m_pacDir = { -1, 0 };
    }
    if (IsKeyPressed(KEY_RIGHT))
    {
        m_pacDir = { 1, 0 };
    }

    m_pacPos.x += m_pacDir.x * m_pacSpeed;
    m_pacPos.y += m_pacDir.y * m_pacSpeed;


    // what tile index is pacman on?
    int currentIndexX = (m_pacPos.x + m_tileWidth*0.5f) / m_tileWidth;
    int currentIndexY = (m_pacPos.y + m_tileHeight*0.5f) / m_tileHeight;

    // what tile index is packman on next tile?
    int nextIndexX = currentIndexX + m_pacDir.x;
    int nextIndexY = currentIndexY + m_pacDir.y;

    if (m_map[currentIndexY][currentIndexX] == FOOD)
    {
        m_map[currentIndexY][currentIndexX] = EMPTY;
    }

    if (m_map[nextIndexY][nextIndexX] == WALL)
    {
        m_pacDir.x = 0;
        m_pacDir.y = 0;
        m_pacPos.x = currentIndexX * m_tileWidth;
        m_pacPos.y = currentIndexY * m_tileHeight;
    }

    // draw each ghost
    for (auto& ghost : m_ghosts)
    {
        UpdateGhost(ghost);
    }


}
void GameApp::Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    // DrawRectangle(100, 100, 100, 100, Color({ 0, 0, 0, 255 }));


    
    int tw = m_tileWidth;
    int th = m_tileHeight;
    int hw = tw / 2;
    int hh = th / 2;

    for (int y = 0; y < MAP_ROWS; y++)
    {
        for (int x = 0; x < MAP_COLS; x++)
        {
            int xPos = x * tw;
            int yPos = y * th;
            int tileID = m_map[y][x];

            if (tileID == WALL)
            {
                DrawRectangle(xPos, yPos, tw, th, Color({ 0, 255, 0, 255 }));
            }
            if (tileID == FOOD)
            {
                DrawRectangle(xPos + hw, yPos + hh, tw/5, th/5, Color({ 255, 255, 0, 255 }));
            }
        }
    }

    // deraw packman
    DrawCircle(
        m_pacPos.x + tw*0.5f, 
        m_pacPos.y + th * 0.5f, 
        tw*0.5f - 3,
        Color({ 255, 255, 0, 255 })
    );

    // draw each ghost
    for (auto& ghost : m_ghosts)
    {
        DrawGhost(ghost);
    }


    EndDrawing();
}


void GameApp::UpdateGhost(Ghost* ghost)
{
    // what tile index is pacman on?
    int currentIndexX = (ghost->pos.x + m_tileWidth * 0.5f) / m_tileWidth;
    int currentIndexY = (ghost->pos.y + m_tileHeight * 0.5f) / m_tileHeight;

    // what tile index is packman on next tile?
    int nextIndexX = currentIndexX + ghost->dir.x;
    int nextIndexY = currentIndexY + ghost->dir.y;

    // if we are not moving at all... bail out.
    if (currentIndexX == nextIndexX && currentIndexY == nextIndexY)
        return;

    std::vector<int> directions;

    if (ghost->dir.x != 0)
    {
        int tileAbove = m_map[currentIndexY - 1][currentIndexX + 0];
        int tileBelow = m_map[currentIndexY + 1][currentIndexX + 0];
        int tileNext = m_map[nextIndexY][nextIndexX];
        if (tileAbove != WALL) directions.push_back(NORTH);
        if (tileBelow != WALL) directions.push_back(SOUTH);
        if( ghost->dir.x < 0 && tileNext != WALL) directions.push_back(WEST);
        if (ghost->dir.x > 0 && tileNext != WALL) directions.push_back(EAST);
    }

    if (ghost->dir.y != 0)
    {
        int tileLfet = m_map[currentIndexY][currentIndexX - 1];
        int tileRight = m_map[currentIndexY][currentIndexX + 1];
        int tileNext = m_map[nextIndexY][nextIndexX];
        if (tileLfet != WALL) directions.push_back(WEST);
        if (tileRight != WALL) directions.push_back(EAST);
        if (ghost->dir.y < 0 && tileNext != WALL) directions.push_back(NORTH);
        if (ghost->dir.y > 0 && tileNext != WALL) directions.push_back(SOUTH);
    };

    int newDir = rand() % directions.size();
    switch (directions[newDir])
    {
    case NORTH:ghost->dir = { 0, -1}; break; 
    case SOUTH:ghost->dir = { 0,  1}; break; 
    case EAST: ghost->dir = { 1,  0}; break; 
    case WEST: ghost->dir = {-1,  0}; break; 
    default: break; // WTF??
    }

    ghost->pos.x += ghost->dir.x * ghost->speed;
    ghost->pos.y += ghost->dir.y * ghost->speed;

}

void GameApp::DrawGhost(Ghost* ghost)
{
    int tw = m_tileWidth;
    int th = m_tileHeight;
    int hw = tw / 2;
    int hh = th / 2;

    DrawCircle(
        ghost->pos.x + tw * 0.5f,
        ghost->pos.y + th * 0.5f,
        tw * 0.5f - 6,
        ghost->col);
}

