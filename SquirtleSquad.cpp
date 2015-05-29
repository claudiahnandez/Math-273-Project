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
	player1_ = NULL;
	player2_ = NULL;
	player3_ = NULL;
	player4_ = NULL;
	stage_ = NULL;
    dxFont_ = new TextDX();  // DirectX font
    messageY_ = 0;
}

//=============================================================================
// Destructor
//=============================================================================
SquirtleSquad::~SquirtleSquad()
{
	delete player1_;
	delete player2_;
	delete player3_;
	delete player4_;
	delete stage_;
    releaseAll();           // call onLostDevice() for every graphics item
    safeDelete(dxFont_);
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void SquirtleSquad::initialize(HWND hwnd)
{

	//use the dimmensions from stage to set game
    Game::initialize(hwnd); // throws GameError

	stage_ = new Magma;
	stage_->initialize(hwnd, graphics);


	player1_ = new Piccolo();
	player1_->initialize(hwnd, graphics, stage_->get_floor());
	player2_ = new Goku();
	player2_->initialize(hwnd, graphics, stage_->get_floor());
	player3_ = new Luffy();
	player3_->initialize(hwnd, graphics, stage_->get_floor());

	//player1_->flipHorizontal(true);
	//player1_->setVelocity(VECTOR2(10, -10));

	player1_->setX(100);
	player2_->setX(200);
	player3_->setX(300);

	//From Pedro: Please don't delete - I will move it to its own class later
	//--------------------//
	//--platform texture--//
	//--------------------//
	//texture
	if (!platformTexture_.initialize(graphics, PLATFORM_IMAGE, SETCOLOR_ARGB(0, 0, 0, 0)))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platform texture"));

	//image1
	if (!platform1_.initialize(this, platformNS::WIDTH, platformNS::HEIGHT, 0, &platformTexture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing paddle"));

	//image2
	if (!platform2_.initialize(this, platformNS::WIDTH, platformNS::HEIGHT, 0, &platformTexture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing paddle"));

	//image3
	if (!platform3_.initialize(this, platformNS::WIDTH, platformNS::HEIGHT, 0, &platformTexture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing paddle"));

	//image4
	if (!platform4_.initialize(this, platformNS::WIDTH, platformNS::HEIGHT, 0, &platformTexture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing paddle"));

	//image5
	if (!platform5_.initialize(this, platformNS::WIDTH, platformNS::HEIGHT, 0, &platformTexture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing paddle"));

	platform1_.setX(0);
	platform2_.setX(200);
	platform3_.setX(400);
	platform4_.setX(600);
	platform5_.setX(800);


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
	stage_->update(frameTime);

	player1_->update(frameTime);
	player2_->update(frameTime);
	player3_->update(frameTime);

	//----------------------------------------------
	//Keyboard Input
	player1_->move(input,frameTime );
	player2_->move(input, frameTime);
	player3_->move(input, frameTime);


	//--------------------------//
	//--Test Code for platform--//
	//--------------------------//

	//if (input->isKeyDown(VK_LEFT))
	//	platform_.setX(platform_.getX() - platformNS::SPEED*frameTime);
	//else if (input->isKeyDown(VK_RIGHT))
	//	platform_.setX(platform_.getX() + platformNS::SPEED*frameTime);
	platform1_.update(frameTime);
	platform2_.update(frameTime);
	platform3_.update(frameTime);
	platform4_.update(frameTime);
	platform5_.update(frameTime);

	//------------------------------

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
{
	VECTOR2 collisionVector;
	//if (player1_->collidesWith(platform_, collisionVector))
		//player1_->bounce(collisionVector, platform_);

	////If collision between fighters
	//if (player1_->collidesWith(*player2_, collisionVector))
	//{
	//	//Bounce off player2
	//	//player1_->bounce(collisionVector, *player2_);
	//	player1_.damage(ATTACK_A);

	//	// Change the direction of the collisionVector for player2
	//	//player2_->bounce(collisionVector*-1, *player1_);
	//	player2_.damage(ATTACK_A);
	//}

	//// If collision between ship and planet
	//if (player1_.collidesWith(player2_, collisionVector))
	//{
	//	// Bounce off planet
	//	player1_.bounce(collisionVector, player2_);
	//	ship1.damage(PLANET);
	//}
}

//=============================================================================
// Render game items
//=============================================================================
void SquirtleSquad::render()
{
	//part of Game::renderGame(); (probably called in while(!done) in WinMain


    graphics->spriteBegin();                // begin drawing sprites
	//------------------------
	//background is being drawn
	//------------------------
	stage_->draw(graphics);
	platform1_.draw();
	platform2_.draw();
	platform3_.draw();
	platform4_.draw();
	//platform5_.draw();

	//---------------------------------
	//draw fighters here
	//----------------------------------
	player1_->draw(graphics);
	player2_->draw(graphics);
	player3_->draw(graphics);

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
	platformTexture_.onLostDevice();
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
	platformTexture_.onResetDevice();
    menuTexture_.onResetDevice();
    dxFont_->onResetDevice();
    Game::resetAll();
    return;
}
