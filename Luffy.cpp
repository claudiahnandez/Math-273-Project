#include "constants.h"
#include "Luffy.h"

Luffy::Luffy()
{
	sprite_location_ = LUFFY_TEST;
	scale_ = 2;
	height_ = 0;
	width_ = 0;
	min_frame_ = 0;
	position_.x = GAME_WIDTH/2;
	position_.y = GAME_HEIGHT/2;
	transcolor_ = LUFFY_TRANSCOLOR;
	character_ = LUFFY;
	state_ = STANDING;
}
void Luffy::standing()
{
	animation_.clear();
	state_ = STANDING;
	fixSprite();
}
void Luffy::walking()
{
	animation_.clear();
	state_ = WALKING;
	fixSprite();
}
void Luffy::blocking()
{
	animation_.clear();
	state_ = BLOCKING;
	fixSprite();
}
void Luffy::running()
{

}
void Luffy::falling()
{

}
void Luffy::jumping()
{
	animation_.clear();
	state_ = JUMPING;
	fixSprite();
}
void Luffy::neutralA()	// A
{

}
void Luffy::neutralB()	// B
{
	animation_.clear();
	state_ = NEUTRAL_B;
	fixSprite();
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
void Luffy::fixSprite()
{
	Size spriteSize_(state_, character_);
	Frame interval_(state_, character_);
	width_ = spriteSize_.width();
	height_ = spriteSize_.height();
	animation_.clear();
	Image::setWidth(width_);
	Image::setHeight(height_);
	max_frame_ = interval_.frames();
	RECT temp;

	temp.left = interval_.getLeft();
	temp.top = interval_.getTop();
	temp.right = temp.left + width_;
	temp.bottom = temp.top + height_;
	animation_.push_back(temp);

	for (int i = 1; i < max_frame_; i++)
	{
		RECT temp;
		animation_.push_back(temp);
		animation_[i].left = animation_[i - 1].right + 1;
		animation_[i].top = animation_[i - 1].top;
		animation_[i].right = animation_[i].left + width_;
		animation_[i].bottom = animation_[i - 1].bottom;
	}
	Image::setVector(animation_);
	//you forgot to change the max_frame
	//remember it is in array notation so you have to subtract one from the actual amount
	max_frame_ = interval_.frames();
}