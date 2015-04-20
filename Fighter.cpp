#include "Fighter.h"

Fighter::Fighter()
{
	position_.x = GAME_WIDTH/2;
	position_.y = GAME_HEIGHT / 2;
	state_ = STANDING;
	HP_ = 100;
}//comit

void Fighter::move(Direction direction)
{
	switch (direction)
	{
	case LEFT:
		break;
	case UP:
		break;
	case RIGHT:
		image_.setX(image_.getX() + frameTime * SPEED_);
		if (image_.getX() > GAME_WIDTH) // If offscreen right
			image_.setX((float)-image_.getWidth()); // Position offscreen left
		break;
	case DOWN:
		break;
	}
}