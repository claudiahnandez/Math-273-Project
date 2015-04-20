// Programming 2Dxc Games
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
	dude_ = NULL;
    dxFont_ = new TextDX();  // DirectX font
    messageY_ = 0;
}

//=============================================================================
// Destructor
//=============================================================================
SquirtleSquad::~SquirtleSquad()
{
	delete dude_;
	dude_ = NULL;
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
	dude_ = new Mario;
	dude_->run();
	dude_->initialize(hwnd, graphics, MARIO_WALK_RUN);

    messageY_ = GAME_HEIGHT;

    return;
}

//=============================================================================
// Update all game items
//=============================================================================
void SquirtleSquad::update()
{
	//Is an inherited function and is called in Game::run()
	//So is : ai(), collisions(), and input*
    static float delay = 0;
    delay += frameTime;

	dude_->update(frameTime);



	//------------------------------------------
	//Original Code Comented out
	//------------------------------------------? 

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
	//part of Game::renderGame(); (probably called in while(!done) in WinMain


    graphics->spriteBegin();                // begin drawing sprites

	//---------------------------------
	//will draw fighters here
	//----------------------------------
	dude_->draw(graphics);

    //background_.draw(graphicsNS::ALPHA50);
    //menu_.draw();
	//testImage1_.draw();

	//marioWalkRunImage_.draw();
	

	//mario.draw();

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
