// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// createThisClass.cpp v1.1
// This class is the core of the game

#include "createThisClass.h"

//=============================================================================
// Constructor
//=============================================================================
CreateThis::CreateThis() : Game()
{
    dxFont = new TextDX();  // DirectX font
    messageY = 0;
}

//=============================================================================
// Destructor
//=============================================================================
CreateThis::~CreateThis()
{
    releaseAll();           // call onLostDevice() for every graphics item
    safeDelete(dxFont);
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void CreateThis::initialize(HWND hwnd)
{
    Game::initialize(hwnd); // throws GameError

    // background texture
    if (!backgroundTexture.initialize(graphics, BACKGROUND_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));

    // menu texture
    if (!menuTexture.initialize(graphics,MENU_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu texture"));

    // background image
    if (!background.initialize(graphics, 0, 0, 0, &backgroundTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background"));

    // menu image
    if (!menu.initialize(graphics,0,0,0,&menuTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));

    // initialize DirectX font
    // 18 pixel high Arial
    if(dxFont->initialize(graphics, 18, true, false, "Arial") == false)
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));

    menu.setDegrees(300);
    menu.setScale(0.002861f);

    message = "\n\n\nUtilizes Object Oriented C++ and DirectX\n\n";
    message += "Sprites with Transparency\n\n";
    message += "Collision Detection Supported:\n";
    message += "     - Circular (Distance)\n";
    message += "     - Axis-aligned bounding box\n";
    message += "     - Rotated bounding box\n";
    message += "     - Rotated bounding box and circle\n";
    message += "     - Pixel Perfect\n\n";
    message += "XACT Audio\n\n";
    message += "Sprite and DirectX Text\n\n";
    message += "Tile Based Graphics\n\n";
    message += "Xbox 360 Controller Input\n\n";
    message += "TCP/IP and UDP/IP Network Support\n\n";
    messageY = GAME_HEIGHT;

    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void CreateThis::update()
{
    static float delay = 0;
    delay += frameTime;

    if(menu.getDegrees() > 0)
    {
        menu.setDegrees(menu.getDegrees() - frameTime * 120);
        menu.setScale(menu.getScale() + frameTime * 0.4f);
    }
    else
        menu.setDegrees(0);

    if(delay > 15)           // start over
    {
        menu.setDegrees(300);
        menu.setScale(0.002861f);
        menu.setY(0);
        delay = 0;
        messageY = GAME_HEIGHT;
    }
    else if(delay > 5)
    {
        menu.setY(menu.getY() - frameTime * 300);
        if (messageY > 10)
            messageY -= frameTime * 300;
    }
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void CreateThis::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void CreateThis::collisions()
{}

//=============================================================================
// Render game items
//=============================================================================
void CreateThis::render()
{
    graphics->spriteBegin();                // begin drawing sprites

    background.draw(graphicsNS::ALPHA50);
    menu.draw();
    dxFont->setFontColor(graphicsNS::ORANGE);
    dxFont->print(message,20,(int)messageY);

    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void CreateThis::releaseAll()
{
    dxFont->onLostDevice();
    menuTexture.onLostDevice();
    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void CreateThis::resetAll()
{
    menuTexture.onResetDevice();
    dxFont->onResetDevice();
    Game::resetAll();
    return;
}
