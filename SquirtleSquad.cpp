// Programming 2Dxc Games
// Copyright (c) 2011 by: 
// Charles Kelly
// SquirtleSquadClass.cpp v1.1
// This class is the core of the game

#include "SquirtleSquad.h"
#include "input.h"

//=============================================================================
// Constructor
//=============================================================================
SquirtleSquad::SquirtleSquad() : Game()
{
	player2_ = NULL;
    dxFont_ = new TextDX();  // DirectX font
    messageY_ = 0;
}

//=============================================================================
// Destructor
//=============================================================================
SquirtleSquad::~SquirtleSquad()
{
	//delete player1_;
	delete player2_;
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
	//player1_ = new Mario(graphics);
	player2_ = new Piccolo();
	player2_->initialize(hwnd,graphics);
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

	//player1_->update(frameTime);
	player2_->update(frameTime);

	//----------------------------------------------
	//Keyboard Input
	//player1_->move(input,frameTime );
	player2_->move(input, frameTime);

/*//Old input code (moved to fighter class)

	if (input->isKeyDown(VK_RIGHT))	// If move right
	{
		marioWalkRunImage_.setX(marioWalkRunImage_.getX() + frameTime * SPEED_);
		if (marioWalkRunImage_.getX() > GAME_WIDTH) // If offscreen right
			marioWalkRunImage_.setX((float)-marioWalkRunImage_.getWidth()); // Position offscreen left
	}
	if (input->isKeyDown(VK_LEFT))	// If move left
	{
		marioWalkRunImage_.setX(marioWalkRunImage_.getX() - frameTime * SPEED_);
		if (marioWalkRunImage_.getX() < -marioWalkRunImage_.getWidth()) // If offscreen left
			marioWalkRunImage_.setX((float)GAME_WIDTH); // Position offscreen right
	}
	if (input->isKeyDown(VK_UP))	// If move up
	{
		marioWalkRunImage_.setY(marioWalkRunImage_.getY() - frameTime * SPEED_);
		if (marioWalkRunImage_.getY() < -marioWalkRunImage_.getHeight()) // If offscreen top
			marioWalkRunImage_.setY((float)GAME_HEIGHT); // Position offscreen
		// bottom
	}
	if (input->isKeyDown(VK_DOWN))	// If move down
	{
		marioWalkRunImage_.setY(marioWalkRunImage_.getY() + frameTime * SPEED_);
		if (marioWalkRunImage_.getY() > GAME_HEIGHT) // If offscreen bottom
			marioWalkRunImage_.setY((float)-marioWalkRunImage_.getHeight());// Position offscreen top
	}
*/


/*// Automatic walk (left here for future reference)

	marioWalkRunImage_.setX(marioWalkRunImage_.getX() + frameTime * MARIO_SPEED); // Move mario right
	if (marioWalkRunImage_.getX() > GAME_WIDTH) // If offscreen right
	{
		marioWalkRunImage_.setX((float)-marioWalkRunImage_.getWidth());// Position off screen left
	}
*/

/*
	//Original Code (rotates text)

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
*/
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
	//player1_->draw(graphics);
	player2_->draw(graphics);

	/*
		//Original Code
		//background_.draw(graphicsNS::ALPHA50);
		//menu_.draw();
	*/

    dxFont_->setFontColor(graphicsNS::ORANGE);
    dxFont_->print(message_,20,(int)messageY_);

    graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.-
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
