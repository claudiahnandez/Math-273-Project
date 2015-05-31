#pragma once           
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace Energy_AttackNS
{
	const int   WIDTH = 16;             // image width
	const int   HEIGHT = 22;           // image height
	const int   COLLISION_RADIUS = 4;   // for circular collision
	const float SPEED = 400;            // pixels per second
	const float MASS = 300.0f;          // mass
	const float FIRE_DELAY = 2.0f;      // 4 seconds between torpedo firing
	const int   TEXTURE_COLS = 3;       // texture has 8 columns
	const int   START_FRAME = 2;       // starts at frame 40
	const int   END_FRAME = 2;         // animation frames 40,41,42,43
	const float ANIMATION_DELAY = 0.1f; // time between frames
}

class Enery_Attack : public Entity           // inherits from Entity class
{
private:
	float   fireTimer;                  // time remaining until fire enabled
public:
	// constructor
	Enery_Attack();

	// inherited member functions //moves it
	void update(float frameTime);
	float getMass()    const { return Energy_AttackNS::MASS; }

	// new member functions
	void fire(Entity *fighter);                // fire projectile from fighter
};