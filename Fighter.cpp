#include "Fighter.h"
float frameTime = 0.00417180452;
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
		image_.setX(image_.getX() - frameTime * SPEED_);
		if (image_.getX() < -image_.getWidth()) // If offscreen left
			image_.setX((float)GAME_WIDTH); // Position offscreen right
		break;
	case UP:
		image_.setY(image_.getY() - frameTime * SPEED_);
		if (image_.getY() < -image_.getHeight()) // If offscreen top
			image_.setY((float)GAME_HEIGHT); // Position offscreen
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