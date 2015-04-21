#include "Fighter.h"
Fighter::Fighter()
{
	position_.x = GAME_WIDTH/2;
	position_.y = GAME_HEIGHT / 2;

	state_ = STANDING;

	HP_ = 100;
	max_frame_ = 0;
	min_frame_ = 0;
	width_ = 0;
	height_ = 0;
	scale_ = 0;
	images_per_column_ = 0;
	sprite_location_ = "";
}//comit


void Fighter::move(const Input* input, float frameTime)
{
	if (input->isKeyDown(VK_RIGHT))	// If move right
	{
		image_.setX(image_.getX() + frameTime * SPEED_);
		if (image_.getX() > GAME_WIDTH) // If offscreen right
			image_.setX((float)-image_.getWidth()); // Position offscreen left
		//state_ = 
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
	}
		// bottom

	if (input->isKeyDown(VK_DOWN))	// If move down
	{

	}

}


void Fighter::initialize(HWND hwnd, Graphics*& graphics)
{

	//TEXTURE

	//texture=save the image
	//Testing a back ground and transperancy
	if (!background_.initialize(graphics, BACKGROUND_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));

	//will initialize the texture og the fighter
	if (!texture_.initialize(graphics, sprite_location_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));

	//IMAGE
	// background image
	if (!background_draw_.initialize(graphics, 0,0, 0, &background_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background"));

	// test image 2 (mario)
	//width and height are marios height
	if (!image_.initialize(graphics, width_, height_, images_per_column_, &texture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));

	

	background_draw_.setX(0);
	background_draw_.setY(0);

	image_.setScale(scale_);
	image_.setFrames(min_frame_, max_frame_);
	//marioWalkRunImage_.setCurrentFrame(0);
	image_.setFrameDelay(0.2);
	image_.setY(200);
}


void Fighter::draw(Graphics*& graphics)
{
	background_draw_.draw();
	image_.draw();
}

void Fighter::update(float frameTime)
{
	//will need to be changed due to position
	image_.update(frameTime);

	image_.setX(image_.getX() + frameTime * MARIO_SPEED); // Move mario right
	if (image_.getX() > GAME_WIDTH) // If offscreen right
	{
		image_.setX((float)-image_.getWidth());// Position off screen left
	}
		image_.setY(image_.getY() + frameTime * SPEED_);
		if (image_.getY() > GAME_HEIGHT) // If offscreen bottom
			image_.setY((float)-image_.getHeight());// Position offscreen top
	
}