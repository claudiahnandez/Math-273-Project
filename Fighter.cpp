#include "Fighter.h"
Fighter::Fighter()
{
	position_.x = GAME_WIDTH/2;
	position_.y = GAME_HEIGHT / 2;
	state_ = fighterNS::STANDING;
}

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

void Fighter::initialize(HWND hwnd, Graphics*& graphics, const char sprite_location[])
{
	//get Graphics object


	//Texture
	//will initialize the texture og the fighter
	if (!texture_.initialize(graphics, sprite_location))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing fighter texture"));

	//Image
	if (!image_.initialize(graphics, image_width_,image_height_, num_cols_, &texture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing fighter image"));

	image_.setScale(scale_);
	image_.setFrames(first_frame_, last_frame_);
	image_.setFrameDelay(animation_delay_);
	image_.setY(200);//change the 200 later to a variable?
}



void Fighter::draw(Graphics*& graphics)
{
	image_.draw();
}

void Fighter::update(float frameTime)
{
	image_.update(frameTime);
}