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
	Sprite_Info temp;

	temp.rect.left = interval_.getLeft();
	temp.rect.top = interval_.getTop();
	temp.rect.right = temp.rect.left + spriteData.width;
	temp.rect.bottom = temp.rect.top + spriteData.height;
	animation_.push_back(temp);

	for (int i = 1; i <endFrame; i++)
	{
		animation_.push_back(temp);
		animation_[i].rect.left = animation_[i - 1].rect.right + 1;
		animation_[i].rect.top = animation_[i - 1].rect.top;
		animation_[i].rect.right = animation_[i].rect.left + spriteData.width;
		animation_[i].rect.bottom = animation_[i - 1].rect.bottom;
		//need to set your heigh and width
	}
	Image::setVector(animation_);
	//you forgot to change the max_frame
	//remember it is in array notation so you have to subtract one from the actual amount
	endFrame = interval_.frames();
}