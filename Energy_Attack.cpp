#include "Energy_Attack.h"

//=============================================================================
// default constructor
//=============================================================================
Enery_Attack::Enery_Attack() : Entity()
{
	active = false;                                 // torpedo starts inactive
	spriteData.width = Energy_AttackNS::WIDTH;     // size of 1 image
	spriteData.height = Energy_AttackNS::HEIGHT;
	spriteData.rect.bottom = Energy_AttackNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = Energy_AttackNS::WIDTH;
	cols = Energy_AttackNS::TEXTURE_COLS;
	frameDelay = Energy_AttackNS::ANIMATION_DELAY;
	startFrame = Energy_AttackNS::START_FRAME;       // first frame of ship animation
	endFrame = Energy_AttackNS::END_FRAME;         // last frame of ship animation
	currentFrame = startFrame;
	radius = Energy_AttackNS::COLLISION_RADIUS;  // for circular collision
	visible = false;
	fireTimer = 0.0f;
	mass = Energy_AttackNS::MASS;
	collisionType = entityNS::CIRCLE;
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Enery_Attack::update(float frameTime)
{
	fireTimer -= frameTime;                     // time remaining until fire enabled

	if (visible == false)
		return;

	if (fireTimer < 0)                           // if ready to fire
	{
		visible = false;                        // old torpedo off
		active = false;
	}

	Image::update(frameTime);

	spriteData.x += frameTime * velocity.x;     // move along X 
	spriteData.y += frameTime * velocity.y;     // move along Y

	// Wrap around screen edge
	if (spriteData.x > GAME_WIDTH)              // if off right screen edge
		spriteData.x = -Energy_AttackNS::WIDTH;       // position off left screen edge
	else if (spriteData.x < -Energy_AttackNS::WIDTH)  // else if off left screen edge
		spriteData.x = GAME_WIDTH;              // position off right screen edge
	if (spriteData.y > GAME_HEIGHT)             // if off bottom screen edge
		spriteData.y = -Energy_AttackNS::HEIGHT;      // position off top screen edge
	else if (spriteData.y < -Energy_AttackNS::HEIGHT) // else if off top screen edge
		spriteData.y = GAME_HEIGHT;             // position off bottom screen edge
}

//=============================================================================
// fire
// Fires a torpedo from ship
//=============================================================================
void Enery_Attack::fire(Entity *fighter)
{
	if (fireTimer <= 0.0f)                       // if ready to fire
	{
		velocity.x = (float)cos(fighter->getRadians()) * Energy_AttackNS::SPEED;
		velocity.y = (float)sin(fighter->getRadians()) * Energy_AttackNS::SPEED;
		spriteData.x = fighter->getCenterX() - spriteData.width / 2;
		spriteData.y = fighter->getCenterY() - spriteData.height / 2;
		visible = true;                         // make torpedo visible
		active = true;                          // enable collisions
		fireTimer = Energy_AttackNS::FIRE_DELAY;      // delay firing
		//audio->playCue(TORPEDO_FIRE);
	}
}

