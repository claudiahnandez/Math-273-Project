#include "Health_Bar.h"


Health_Bar::Health_Bar()
{
	right_ = false;
}

void Health_Bar::initialize(HWND hwnd, Graphics*& graphics, bool right, Character picked)
{
	right_ = right;
	bar = picked;
	
	switch (bar)
	{
	case GOKU:
		transcolor = GOKU_BAR_TRANS;
		location_ = GOKU_BAR;
		break;
	case PICCOLO:
		transcolor = PICCOLO_BAR_TRANS;
		location_ = PICCOLO_BAR;
		break;
	case NARRUTO:
		transcolor = NARUTO_BAR_TRANS;
		location_ = NARUTO_BAR;
		break;
	case LUFFY:
		transcolor = LUFFY_BAR_TRANS;
		location_ = LUFFY_BAR;
		break;
	}

	if (!image_.initialize(graphics, 255, 32, 0, &texture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing GOKU menu"));

	if (!texture_.initialize(graphics, location_, transcolor))
	
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing GOKU menu texture"));
	if (right_)
	{
		image_.setX(GAME_WIDTH - 220);
	}
}

void Health_Bar::draw(Graphics*& graphics)
{
	image_.draw();
}

void Health_Bar::update(float frameTime)
{
	image_.update(frameTime);
}