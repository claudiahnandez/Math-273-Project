#include "Fighter.h"
Fighter::Fighter()
{
	position_.x = GAME_WIDTH/2;
	position_.y = GAME_HEIGHT / 2;
	state_ = STANDING;
	HP_ = 100;
}//comit

void Fighter::move(const Input* input, float frameTime)
{
	if (input->isKeyDown(VK_RIGHT))	// If move right
	{
		image_.setX(image_.getX() + frameTime * SPEED_);
		if (image_.getX() > GAME_WIDTH) // If offscreen right
			image_.setX((float)-image_.getWidth()); // Position offscreen left
	}
	if (input->isKeyDown(VK_LEFT))	// If move left
	{
		image_.setX(image_.getX() - frameTime * SPEED_);
		if (image_.getX() < -image_.getWidth()) // If offscreen left
			image_.setX((float)GAME_WIDTH); // Position offscreen right
	}
	if (input->isKeyDown(VK_UP))	// If move up
	{
		image_.setY(image_.getY() - frameTime * SPEED_);
		if (image_.getY() < -image_.getHeight()) // If offscreen top
			image_.setY((float)GAME_HEIGHT); // Position offscreen
		// bottom
	}
	if (input->isKeyDown(VK_DOWN))	// If move down
	{
		image_.setY(image_.getY() + frameTime * SPEED_);
		if (image_.getY() > GAME_HEIGHT) // If offscreen bottom
			image_.setY((float)-image_.getHeight());// Position offscreen top
	}
}