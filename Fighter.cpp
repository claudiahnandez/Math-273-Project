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

}

void Fighter::move(Direction direction)
{

}

void Fighter::initialize(HWND hwnd, Graphics*& graphics, const char sprite_location[])
{

	//TEXTURE

	//texture=save the image
	//Testing a back ground and transperancy
	if (!background_.initialize(graphics, BACKGROUND_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));

	//will initialize the texture og the fighter
	if (!fighter_.initialize(graphics, sprite_location))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));

	//IMAGE
	// background image
	if (!background_draw_.initialize(graphics, 0,0, 0, &background_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background"));

	// test image 2 (mario)
	//width and height are marios height
	if (!fighter_draw_.initialize(graphics, width_, height_, images_per_column_, &fighter_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));

	background_draw_.setX(0);
	background_draw_.setY(0);

	fighter_draw_.setScale(scale_);
	fighter_draw_.setFrames(min_frame_, max_frame_);
	//marioWalkRunImage_.setCurrentFrame(0);
	fighter_draw_.setFrameDelay(0.2);
	fighter_draw_.setY(200);
}



void Fighter::draw(Graphics*& graphics)
{
	background_draw_.draw();
	fighter_draw_.draw();
}

void Fighter::update(float frameTime)
{
	//will need to be changed due to position
	fighter_draw_.update(frameTime);

	fighter_draw_.setX(fighter_draw_.getX() + frameTime * MARIO_SPEED); // Move mario right
	if (fighter_draw_.getX() > GAME_WIDTH) // If offscreen right
	{
		fighter_draw_.setX((float)-fighter_draw_.getWidth());// Position off screen left
	}
}
