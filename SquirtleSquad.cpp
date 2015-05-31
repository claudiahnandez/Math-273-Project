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
	player3_ = new Naruto();
	player3_->initialize(hwnd, graphics, stage_->get_floor());
	player4_ = new Luffy();
	player4_->initialize(hwnd, graphics, stage_->get_floor());


	player3_->flipHorizontal(true);
	player4_->flipHorizontal(true);
	//player4_->setVelocity(VECTOR2(10, -10));

	player1_->setX(100);
	player2_->setX(300);
	player3_->setX(500);
	player4_->setX(700);

	//From Pedro: Please don't delete
	//------------------------
	//--Test platforms texture
	//------------------------

	//texture
	if (!platformTexture_.initialize(graphics, PLATFORM_IMAGE, SETCOLOR_ARGB(0, 0, 0, 0)))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platform texture"));

	//image1
	if (!platform1_.initialize(this, platformNS::WIDTH, platformNS::HEIGHT, 0, &platformTexture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platform"));

	//image2
	if (!platform2_.initialize(this, platformNS::WIDTH, platformNS::HEIGHT, 0, &platformTexture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platform"));

	//image3
	if (!platform3_.initialize(this, platformNS::WIDTH, platformNS::HEIGHT, 0, &platformTexture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platform"));

	//image4
	if (!platform4_.initialize(this, platformNS::WIDTH, platformNS::HEIGHT, 0, &platformTexture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platform"));

	//image5
	if (!platform5_.initialize(this, platformNS::WIDTH, platformNS::HEIGHT, 0, &platformTexture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing platform"));

	platform1_.setX(0);
	platform2_.setX(200);
	platform3_.setX(400);
	platform4_.setX(600);
	platform5_.setX(800);

	//--------------
	//Energy Attacks
	//--------------
	//temporary game textures
	if (!gameTextures.initialize(graphics, BALL, NARUTO_TRANSCOLOR))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));

	// attack 1
	if (!Energy_Attack_1_.initialize(this, Energy_AttackNS::WIDTH, Energy_AttackNS::HEIGHT, Energy_AttackNS::TEXTURE_COLS, &gameTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Energy_Attack1"));


	Energy_Attack_1_.setFrames(Energy_AttackNS::START_FRAME, Energy_AttackNS::END_FRAME);
	Energy_Attack_1_.setCurrentFrame(Energy_AttackNS::START_FRAME);
	Energy_Attack_1_.setColorFilter(SETCOLOR_ARGB(255, 128, 128, 255));   // light blue
	Energy_Attack_1_.setScale(4);

	// attack 2
	if (!Energy_Attack_1_.initialize(this, Energy_AttackNS::WIDTH, Energy_AttackNS::HEIGHT, Energy_AttackNS::TEXTURE_COLS, &gameTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Energy_Attack1"));

	Energy_Attack_2_.setFrames(Energy_AttackNS::START_FRAME, Energy_AttackNS::END_FRAME);
	Energy_Attack_2_.setCurrentFrame(Energy_AttackNS::START_FRAME);
	Energy_Attack_2_.setColorFilter(SETCOLOR_ARGB(255, 255, 255, 64));     // light yellow
	Energy_Attack_2_.setScale(1);


	// attack 3
	if (!Energy_Attack_3_.initialize(this, Energy_AttackNS::WIDTH, Energy_AttackNS::HEIGHT, Energy_AttackNS::TEXTURE_COLS, &gameTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Energy_Attack1"));

	Energy_Attack_3_.setFrames(Energy_AttackNS::START_FRAME, Energy_AttackNS::END_FRAME);
	Energy_Attack_3_.setCurrentFrame(Energy_AttackNS::START_FRAME);
	Energy_Attack_3_.setColorFilter(SETCOLOR_ARGB(255, 128, 128, 255));   // light blue
	Energy_Attack_3_.setScale(1);


	// attack 4
	if (!Energy_Attack_4_.initialize(this, Energy_AttackNS::WIDTH, Energy_AttackNS::HEIGHT, Energy_AttackNS::TEXTURE_COLS, &gameTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Energy_Attack1"));

	Energy_Attack_4_.setFrames(Energy_AttackNS::START_FRAME, Energy_AttackNS::END_FRAME);
	Energy_Attack_4_.setCurrentFrame(Energy_AttackNS::START_FRAME);
	Energy_Attack_4_.setColorFilter(SETCOLOR_ARGB(255, 255, 255, 64));     // light yellow
	Energy_Attack_4_.setScale(1);


	// health bar
	//healthBar.initialize(graphics, &gameTextures, 0, spacewarNS::HEALTHBAR_Y, 2.0f, graphicsNS::WHITE);


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
	player4_->update(frameTime);

	//----------------------------------------------
	//Keyboard Input
	input->readControllers();
	/*if (input->getGamepadConnected(0))
	{
		input->gamePadVibrateLeft(0, 65535, 1.0);
	}*/


	player1_->move(input,frameTime, 0 );
	player2_->move(input, frameTime, 1);
	player3_->move(input, frameTime, 2);
	player4_->move(input, frameTime, 3);


	if (input->isKeyDown(VK_SPACE) ^ const_cast<Input*>(input)->getGamepadA(0))
	{
		Energy_Attack_1_.fire(*&player1_);                  // fire projectile
	}
	//if (input->isKeyDown(VK_SPACE) ^ const_cast<Input*>(input)->getGamepadA(1))
	//{
	//	Energy_Attack_2_.fire(*&player2_);                  // fire projectile
	//}	
	//if (input->isKeyDown(VK_SPACE) ^ const_cast<Input*>(input)->getGamepadA(2))
	//{
	//	Energy_Attack_3_.fire(*&player3_);                  // fire projectile
	//}
	//if (input->isKeyDown(VK_SPACE) ^ const_cast<Input*>(input)->getGamepadA(3))
	//{
	//	Energy_Attack_4_.fire(*&player4_);                  // fire projectile
	//}

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

	Energy_Attack_1_.update(frameTime);

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
	// if collision between energy attack and player2_
	if (Energy_Attack_1_.collidesWith(*(Entity*)(player2_->get_entity()), collisionVector))
	{
		//player2_->damage(ENERGY_ATTACK);
		Energy_Attack_1_.setVisible(false);
		Energy_Attack_1_.setActive(false);
		input->gamePadVibrateRight(1, 20000, 0.5);
	}
	if (Energy_Attack_1_.collidesWith(*(Entity*)(player1_->get_entity()), collisionVector))
	{
		//player1_->damage(ENERGY_ATTACK);
		Energy_Attack_2_.setVisible(false);
		Energy_Attack_2_.setActive(false);
		input->gamePadVibrateRight(0, 20000, 0.5);
	}

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
	player4_->draw(graphics);

	Energy_Attack_1_.draw();

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
