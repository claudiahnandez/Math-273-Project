#include "constants.h"
#include "Luffy.h"

Luffy::Luffy()
{
	sprite_location_ = LUFFY_TEST;
	spriteData.scale = 2;
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
	spriteData.width = spriteSize_.width();
	spriteData.height = spriteSize_.height();
	animation_.clear();
	endFrame = interval_.frames();
	RECT temp;

	temp.left = interval_.getLeft();
	temp.top = interval_.getTop();
	temp.right = temp.left + spriteData.width;
	temp.bottom = temp.top + spriteData.height;
	animation_.push_back(temp);

	for (int i = 1; i <endFrame; i++)
	{
		animation_.push_back(temp);
		animation_[i].left = animation_[i - 1].right + 1;
		animation_[i].top = animation_[i - 1].top;
		animation_[i].right = animation_[i].left + spriteData.width;
		animation_[i].bottom = animation_[i - 1].bottom;
		//need to set your heigh and width
	}
	Image::setVector(animation_);
	//you forgot to change the max_frame
	//remember it is in array notation so you have to subtract one from the actual amount
	endFrame = interval_.frames();
}