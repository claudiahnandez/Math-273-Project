// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly

#include "Platform.h"

//=============================================================================
// default constructor
//=============================================================================
Platform::Platform() : Entity()
{
	spriteData.width = platformNS::WIDTH;         // size of Ship1
	spriteData.height = platformNS::HEIGHT;
	spriteData.x = platformNS::X;                 // location on screen
	spriteData.y = platformNS::Y;
	spriteData.rect.bottom = platformNS::HEIGHT;  // rectangle to select parts of an image
	spriteData.rect.right = platformNS::WIDTH;
	frameDelay = 1;
	startFrame = 0;                             // first frame of animation
	endFrame = 0;                           // last frame of animation
	currentFrame = startFrame;
	edge.top = -platformNS::HEIGHT / 2;             // set collision edges
	edge.bottom = platformNS::HEIGHT / 2;
	edge.left = -platformNS::WIDTH / 2;
	edge.right = platformNS::WIDTH / 2;
	collisionType = entityNS::ROTATED_BOX;
	mass = platformNS::MASS;
	edge.left = -20;
	edge.top = -20;
	edge.right = 20;
	edge.bottom = 20;
	active = true;
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Platform::update(float frameTime)
{
	Entity::update(frameTime);

	// Bounce off walls
	if (spriteData.x > GAME_WIDTH - platformNS::WIDTH)  // if hit right screen edge
		spriteData.x = GAME_WIDTH - platformNS::WIDTH;  // position at right screen edge
	else if (spriteData.x < 0)                    // else if hit left screen edge
		spriteData.x = 0;                           // position at left screen edge
}
