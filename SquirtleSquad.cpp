// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// SquirtleSquadClass.cpp v1.1
// This class is the core of the game

#include "SquirtleSquad.h"

//=============================================================================
// Constructor
//=============================================================================
SquirtleSquad::SquirtleSquad() : Game()
{
    dxFont_ = new TextDX();  // DirectX font
    messageY_ = 0;
}

//=============================================================================
// Destructor
//=============================================================================
SquirtleSquad::~SquirtleSquad()
{
    releaseAll();           // call onLostDevice() for every graphics item
    safeDelete(dxFont_);
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void SquirtleSquad::initialize(HWND hwnd)
{
    Game::initialize(hwnd); // throws GameError


	//-------------------------------------------------------------------------
	//Textures
    // background texture
    if (!backgroundTexture_.initialize(graphics, BACKGROUND_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));

    // menu texture
    if (!menuTexture_.initialize(graphics,MENU_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu texture"));

	// test texture1
	if (!testTexture1_.initialize(graphics, TEST_IMAGE1))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu texture"));

	//-------------------------------------------------------------------------
	//Images

    // background image
    if (!background_.initialize(graphics, 0, 0, 0, &backgroundTexture_))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background"));

    // menu image
    if (!menu_.initialize(graphics,0,0,0,&menuTexture_))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));

	// test image
	if (!testImage1_.initialize(graphics, 25, 25, 0, &testTexture1_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));

    // initialize DirectX font
    // 18 pixel high Arial
    if(dxFont_->initialize(graphics, 18, true, false, "Arial") == false)
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));

    menu_.setDegrees(300);
    menu_.setScale(0.002861f);

	testImage1_.setScale(5);


	message_ = "\n\n\nTaking Over";
    message_ += "\n\n\nUtilizes Object Oriented C++ and DirectX\n\n";
    message_ += "Sprites with Transparency\n\n";
    message_ += "Collision Detection Supported:\n";
    message_ += "     - Circular (Distance)\n";
    message_ += "     - Axis-aligned bounding box\n";
    message_ += "     - Rotated bounding box\n";
    message_ += "     - Rotated bounding box and circle\n";
    message_ += "     - Pixel Perfect\n\n";
    message_ += "XACT Audio\n\n";
    message_ += "Sprite and DirectX Text\n\n";
    message_ += "Tile Based Graphics\n\n";
    message_ += "Xbox 360 Controller Input\n\n";
    message_ += "TCP/IP and UDP/IP Network Support\n\n";
    messageY_ = GAME_HEIGHT;

    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void SquirtleSquad::update()
{
    static float delay = 0;
    delay += frameTime;

    //if(menu_.getDegrees() > 0)
    //{
    //    menu_.setDegrees(menu_.getDegrees() - frameTime * 120);
    //    menu_.setScale(menu_.getScale() + frameTime * 0.4f);
    //}
    //else
    //    menu_.setDegrees(0);

    //if(delay > 15)           // start over
    //{
    //    menu_.setDegrees(300);
    //    menu_.setScale(0.002861f);
    //    menu_.setY(0);
    //    delay = 0;
    //    messageY_ = GAME_HEIGHT;
    //}
    //else if(delay > 5)
    //{
    //    menu_.setY(menu_.getY() - frameTime * 300);
    //    if (messageY_ > 10)
    //        messageY_ -= frameTime * 300;
    //}
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void SquirtleSquad::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void SquirtleSquad::collisions()
{}

//=============================================================================
// Render game items
//=============================================================================
void SquirtleSquad::render()
{
    graphics->spriteBegin();                // begin drawing sprites

    //background_.draw(graphicsNS::ALPHA50);
    //menu_.draw();
	testImage1_.draw();
    dxFont_->setFontColor(graphicsNS::ORANGE);
    dxFont_->print(message_,20,(int)messageY_);

    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void SquirtleSquad::releaseAll()
{
    dxFont_->onLostDevice();
    menuTexture_.onLostDevice();
    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void SquirtleSquad::resetAll()
{
    menuTexture_.onResetDevice();
    dxFont_->onResetDevice();
    Game::resetAll();
    return;
}
