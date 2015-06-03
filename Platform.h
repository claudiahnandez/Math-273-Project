

#ifndef platform_h             // Prevent multiple definitions if this 
#define platform_h             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace platformNS
{
	const int WIDTH = 100;                  // image width
	const int HEIGHT = 25;                  // image height
	const int X = GAME_WIDTH / 2 - WIDTH/2;   // location on screen
	const int Y = GAME_HEIGHT - HEIGHT;
	const float SPEED = 200;                // pixels per second
	const float MASS = 1.0e6f;
}

// inherits from Entity class
class Platform : public Entity
{
public:
	// constructor
	Platform();

	// inherited member functions
	void update(float frameTime);

	void disable() { visible = false; active = false; }
	void enable()  { visible = true; active = true; }

	void activate() { active = true; }
	void deactivate() { active = false; }
	void makeVisible() { visible = true; }
	void makeInvisible(){ visible = false; }
};
#endif

