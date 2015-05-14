#include "constants.h"
#include "Luffy.h"

Luffy::Luffy()
{
	sprite_location_ = LUFFY_TEST;
	height_ = 0;
	width_ = 0;
	state_ = STANDING;
	min_frame_ = 0;
	position_.x = GAME_WIDTH / 3;
	position_.y = GAME_HEIGHT - 50;
	transcolor_ = LUFFY_TRANSCOLOR;
	character_ = LUFFY;
}
void Luffy::standing()
{
	state_ = STANDING;
	Size spriteSize_(state_, character_);
	Frame interval_(state_, character_);
	fixSprite(spriteSize_, interval_);

	animation_.clear();
	image_.setWidth(width_);
	image_.setHeight(height_);

	RECT temp;

}
void Luffy::walking()
{

}
void Luffy::running()
{

}
void Luffy::falling()
{

}
void Luffy::jumping()
{

}
void Luffy::crouching()
{

}
void Luffy::neutralA()	// A
{

}
void Luffy::neutralB()	// B
{

}
void Luffy::sideB()		// <B>
{

}
void Luffy::upB()			// ^B
{

}
void Luffy::downB()		// vB
{

}
void Luffy::standardAttack()
{

}
//helper function
void Luffy::fixSprite(Size size, Frame interval)
{
	width_ = size.width();
	height_ = size.height();
	min_frame_ = interval.start();
	max_frame_ = interval.end();
}