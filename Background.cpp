#include "Background.h"


Background::Background()
{
	width_ = 0;
	height_ = 0;
	floor_ = 0;
	background_location_ = "";
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

	Image::setX(0);
	Image::setY(0);

	//might have to set scale;

}

void Background::draw(Graphics*& graphic)
{
	Image::draw();
}