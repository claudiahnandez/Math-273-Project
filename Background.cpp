#include "Background.h"


Background::Background()
{
	width_ = 0;
	height_ = 0;
	floor_ = 0;
	scale_ = 1;
	background_location_ = "";
	max_frames = 1;
}

void Background::initialize(HWND hwnd, Graphics*& graphics)
{
	//will initialize the texture og the fighter
	if (!texture_.initialize(graphics, background_location_, TRANSCOLORR))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));

	//IMAGE
	// test image 2 (mario)
	//width and height are marios height
	if (!Image::initialize(graphics, width_, height_, 1, &texture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background image"));

	set_image();
	Image::setFrames(0, max_frames);
	Image::setX(0);
	Image::setY(0);
	Image::setFrameDelay(0.2);
	Image::setScale(scale_);

	//might have to set scale;

}

void Background::draw(Graphics*& graphic)
{
	set_image();
	Image::draw();
}

void Background::update(float frameTime)
{
	Entity::update(frameTime);
}
void Background::set_animation(Sprite_Info animation[])
{
	animation_.clear();
	RECT temp;
	for (int i = 0; i <=max_frames; i++)
	{
		animation_.push_back(temp);
		animation_[i] = animation[i].rect;
	}

}