#include "Goku.h"


Goku::Goku()
{
	sprite_location_ = GOKU_SPRITE;
	height_ = 55;
	width_ = 55;

	state_ = STANDING;
	min_frame_ = 0;
	max_frame_ = 3;
	
	position_.x = GAME_WIDTH / 3;
	position_.y = GAME_HEIGHT-50;

	transcolor_ = GOKU_TRANSCOLOR;


}


void Goku::standing()
{
	animation_.clear();
	max_frame_ = 3;

	height_ = 55;
	width_ = 55;

	image_.setWidth(55);
	image_.setHeight(55);

	RECT run_goku;
	run_goku.left = 10;
	run_goku.top = 11;
	run_goku.right = run_goku.left + width_;
	run_goku.bottom = run_goku.top + height_;
	animation_.push_back(run_goku);

	//the rest of the frames are drawn based on the width
	for (int i = 1; i < 4; i++)
	{
		RECT temp;
		animation_.push_back(temp);
		animation_[i].left = animation_[0].left + (i*width_);
		animation_[i].top = animation_[0].top;
		animation_[i].right = animation_[0].right + (i*width_);
		animation_[i].bottom = animation_[0].bottom;
	}

	image_.setVector(animation_);
	
}

void Goku::walking()
{
	animation_.clear();
	max_frame_ = 3;

	image_.setWidth(65);
	image_.setHeight(55);

	width_ = 65;
	height_=50;

	RECT walk;
	walk.left = 0;
	walk.top = 65;
	walk.right = walk.left + width_;
	walk.bottom = walk.top + height_;
	animation_.push_back(walk);

	for (int i = 1; i <=max_frame_; i++)
	{
		RECT temp;
		animation_.push_back(temp);
		animation_[i].left = animation_[0].left + (width_*i);
		animation_[i].top = animation_[0].top;
		animation_[i].right = animation_[0].right + (i*width_);
		animation_[i].bottom = animation_[0].bottom;
	}

	image_.setVector(animation_);


}
void Goku::running(){}
void Goku::falling(){}
void Goku::jumping(){}
void Goku::crouching(){}
void Goku::neutralA(){}	// A
void Goku::neutralB(){}	// B
void Goku::sideB(){}		// <B>
void Goku::upB(){}			// ^B
void Goku::downB(){}		// vB
void Goku::standardAttack(){}
