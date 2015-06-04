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
	//player3_ = NULL;
	//player4_ = NULL;
	stage_ = NULL;
	musicOff = false;
	menuOn = true;
	char_select = false;//turns on character selection
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
	//delete player3_;
	//delete player4_;
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

	stage_ = new Budakai;
	stage_->initialize(hwnd, graphics);
	play1_select.initialize(hwnd, graphics, false);//player 1 character selection
	play2_select.initialize(hwnd, graphics, true);//player 2 character selection

	//player1_ = new Piccolo();
	//player1_->initialize(hwnd, graphics, stage_->get_floor());
	//player2_ = new Goku();
	//player2_->initialize(hwnd, graphics, stage_->get_floor());
	///*player3_ = new Naruto();
	//player3_->initialize(hwnd, graphics, stage_->get_floor());
	//player4_ = new Luffy();
	//player4_->initialize(hwnd, graphics, stage_->get_floor());*/


	//player3_->flipHorizontal(true);
	//player4_->flipHorizontal(true);
	//player4_->setVelocity(VECTOR2(10, -10));

	/*player1_->setX(100);
	player2_->setX(300);*/
	/*player3_->setX(500);
	player4_->setX(700);*/

	//player1_->setCollisionType(entityNS::BOX);
	//player2_->setCollisionType(entityNS::BOX);
	//player3_->setCollisionType(entityNS::BOX);
	//player4_->setCollisionType(entityNS::BOX);

	//player1_->setActive(true);
	//player2_->setActive(true);
	//player3_->setActive(true);
	//player4_->setActive(true);



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

	//------------------------
	//initializing start menu
	//------------------------

	//initializing start menu
	if (!s_menuImage.initialize(graphics, GAME_WIDTH, GAME_HEIGHT, 0, &s_menuTexture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing start menu"));

	if (!s_menuTexture_.initialize(graphics, START_MENU, TRANSCOLORR))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing start menu texture"));

	//-------------
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

	//image1
	if (!hitbox1_.initialize(this, platformNS::WIDTH, platformNS::HEIGHT, 0, &platformTexture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing hitbox"));

	//image2
	if (!hitbox2_.initialize(this, platformNS::WIDTH, platformNS::HEIGHT, 0, &platformTexture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing hitbox"));

	//image3
	if (!hitbox3_.initialize(this, platformNS::WIDTH, platformNS::HEIGHT, 0, &platformTexture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing hitbox"));

	//image4
	if (!hitbox4_.initialize(this, platformNS::WIDTH, platformNS::HEIGHT, 0, &platformTexture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing hitbox"));

	hitbox1_.setX(0);
	hitbox2_.setX(0);
	hitbox3_.setX(0);
	hitbox4_.setX(0);

	hitbox1_.setY(GAME_HEIGHT / 2);
	hitbox2_.setY(GAME_HEIGHT / 2);
	hitbox3_.setY(GAME_HEIGHT / 2);
	hitbox4_.setY(GAME_HEIGHT / 2);

	hitbox1_.enable();
	hitbox2_.disable();
	hitbox3_.disable();
	hitbox4_.disable();

	// health bar
	//healthBar.initialize(graphics, &gameTextures, 0, spacewarNS::HEALTHBAR_Y, 2.0f, graphicsNS::WHITE);

	//audio->playCue(ACTION_THEME);
	//audio->playCue(BOSS_BATTLE_THEME);



	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void SquirtleSquad::update()
{
	if (menuOn)
	{
		if (input->anyKeyPressed())
		{
			menuOn = false;
			char_select = true;
			input->clearAll();
		}
	}
	else if (char_select)
	{
		play1_select.update(frameTime);
		play2_select.update(frameTime);

		//player 1 choose
		if (input->getGamepadLeftShoulder(0))
		{
			play1_select.left_change_character();
		}
		if (input->getGamepadRightShoulder(0))
		{
			play1_select.right_change_character();
		}
		if (input->getGamepadA(0))
		{
			player1 = play1_select.chosen_character();
			play1_selected = true;
		}

		//player 2 choose
		//player 1 choose
		if (input->isKeyDown(VK_LEFT))
		{
			play2_select.left_change_character();
		}
		if (input->isKeyDown(VK_RIGHT))
		{
			play2_select.right_change_character();
		}
		if (input->isKeyDown(VK_SPACE))
		{
			player2 = play2_select.chosen_character();
			play2_selected = true;
		}
		input->clearAll();

		if (play1_selected && play2_selected)
		{
			char_select = false;
			switch (player1)
			{
			case GOKU:
				player1_ = new Goku();
				break;
			case PICCOLO:
				player1_ = new Piccolo();
				break;
			case NARRUTO:
				player1_ = new Naruto();
				break;
			case LUFFY:
				player1_ = new Luffy();
				break;
			}
			player1_->initialize(hwnd, graphics, stage_->get_floor());

			switch (player2)
			{
			case GOKU:
				player2_ = new Goku();
				break;
			case PICCOLO:
				player2_ = new Piccolo();
				break;
			case NARRUTO:
				player2_ = new Naruto();
				break;
			case LUFFY:
				player2_ = new Luffy();
				break;
			}
			player2_->initialize(hwnd, graphics, stage_->get_floor());

			player1_->setX(100);
			player2_->setX(300);
			player1_->flipHorizontal(false);
			player2_->flipHorizontal(true);
			player1_->setCollisionType(entityNS::BOX);
			player2_->setCollisionType(entityNS::BOX);
			player1_->setActive(true);
			player2_->setActive(true);


		}
	}
	else
	{
		//Is an inherited function and is called in Game::run()
		//So is : ai(), collisions(), and input*
		static float delay = 0;
		delay += frameTime;
		stage_->update(frameTime);

		player1_->update(frameTime);
		player2_->update(frameTime);
		/*player3_->update(frameTime);
		player4_->update(frameTime);*/

		//----------------------------------------------
		//Keyboard Input
		input->readControllers();
		/*if (input->getGamepadConnected(0))
		{
		input->gamePadVibrateLeft(0, 65535, 1.0);
		}*/

		player1_->move(input, frameTime, 0, hitbox1_);
		//player2_->move(input, frameTime, 1);
		/*	player3_->move(input, frameTime, 2);
			player4_->move(input, frameTime, 3);*/

		//-------------------------------
		//move hitbox to players position
		//-------------------------------
		hitbox1_.setX(player1_->getX());
		hitbox1_.setY(player1_->getY() + player1_->getHeight()*.3);

		//adjust hitbox based on direction the fighter is facing
		if (player1_->getDirection())
		{
			hitbox1_.setX(hitbox1_.getX() - player1_->getWidth()*player1_->getScale());
		}
		else
		{
			hitbox1_.setX(hitbox1_.getX() + player1_->getWidth()*player1_->getScale());
		}


		//-------------------------------
		//
		//-------------------------------
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

	if (!char_select && !menuOn)
	{
		// if collision between energy attack and player2_
		if (Energy_Attack_1_.collidesWith(*(Entity*)(player2_->get_entity()), collisionVector))
		{
			//player2_->damage(ENERGY_ATTACK);
			Energy_Attack_1_.setVisible(false);
			Energy_Attack_1_.setActive(false);
			input->gamePadVibrateRight(1, 65535, 0.5);
		}
		if (Energy_Attack_2_.collidesWith(*(Entity*)(player1_->get_entity()), collisionVector))
		{
			//player1_->damage(ENERGY_ATTACK);
			Energy_Attack_2_.setVisible(false);
			Energy_Attack_2_.setActive(false);
			input->gamePadVibrateRight(0, 65535, 0.5);
		}


		//--------------
		//Player1 hitbox
		//--------------

		//hitbox1 vs Player2
		if (hitbox1_.collidesWith(*(Entity*)(player2_->get_entity()), collisionVector))
		{
			player2_->setState(FALLING);
			player2_->setY(100);
			input->gamePadVibrateRight(0, 65535, 0.5);

		}

		//player1 vs Player2
		if (player1_->collidesWith(*(Entity*)(player2_->get_entity()), collisionVector))
		{
			player1_->setState(FALLING);
			player2_->setState(FALLING);
			input->gamePadVibrateRight(0, 65535, 0.5);
		}
	}
}

//=============================================================================
// Render game items
//=============================================================================
void SquirtleSquad::render()
{
	//part of Game::renderGame(); (probably called in while(!done) in WinMain

	//draws start menu
	graphics->spriteBegin();
	if (menuOn)
	{
		s_menuImage.draw();
	}
	else if (char_select)
	{
		play1_select.draw(graphics);
		play2_select.draw(graphics);
	}

	else
	{
		// begin drawing sprites
		//------------------------
		//background is being drawn
		//------------------------
		stage_->draw(graphics);
		//platform1_.draw();
		//platform2_.draw();
		//platform3_.draw();
		//platform4_.draw();
		//platform5_.draw();

		//---------------------------------
		//draw fighters here
		//----------------------------------
		player1_->draw(graphics);
		player2_->draw(graphics);
		//player3_->draw(graphics);
		//player4_->draw(graphics);

		hitbox1_.draw();
		hitbox2_.draw();
		hitbox3_.draw();
		hitbox4_.draw();

		Energy_Attack_1_.draw();

		dxFont_->setFontColor(graphicsNS::ORANGE);
		dxFont_->print(message_, 20, (int)messageY_);
	}

	graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.-
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void SquirtleSquad::releaseAll()
{
	play1_select.onLostDevice();
	play2_select.onLostDevice();
	platformTexture_.onLostDevice();
	dxFont_->onLostDevice();
	s_menuTexture_.onLostDevice();
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
	s_menuTexture_.onResetDevice();
	dxFont_->onResetDevice();
	Game::resetAll();
	return;
}
