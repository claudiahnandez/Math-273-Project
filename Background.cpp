#include "Background.h"


Background::Background()
{
	/*floor_ = 0;
	spriteData.scale = 1;
	spriteData.x = 0;
	spriteData.y = 0;
	
	background_location_ = "";
	endFrame = 1;
	frameDelay = 0.2;
*/
	//width_ = 516;
	//height_ = 548;
	//floor_ = 38;
	//background_location_ = BACKGROUND_IMAGE;

	floor_ = 25;
	background_location_ = "";
	spriteData.width = 516;
	spriteData.height = 400;
	spriteData.scale = 1;
	endFrame = 0;
	frameDelay = 0.22;
	

}

void Background::initialize(HWND hwnd, Graphics*& graphics)
{
	set_image();//virtual void function

	//will initialize the texture og the fighter
	if (!texture_.initialize(graphics, background_location_, TRANSCOLORR))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));

	//IMAGE
	// test image 2 (mario)
	//width and height are marios height
	if (!Image::initialize(graphics, spriteData.width, spriteData.height, 1, &texture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background image"));


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
void Background::set_animation(RECT animation[])
{
	animation_.clear();
	RECT temp;
	for (int i = 0; i <=endFrame; i++)
	{
		animation_.push_back(temp);
		animation_[i]= animation[i];
	}
}

int Background::get_floor()
{
	return floor_;
}

void Background::set_image()
{
	RECT image[1];
	image[0] = help_set_rect(0, spriteData.height, spriteData.height, spriteData.width);
	set_animation(image);
}