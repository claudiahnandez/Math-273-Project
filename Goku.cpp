#include "Goku.h"


Goku::Goku()
{
	sprite_location_ = GOKU_SPRITE;
	height_ = 49;
	width_ = 47;
	width_gap = 10;
	height_gap = 26;

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

	height_ = 49;
	width_ = 47;
	width_gap = 10;

	image_.setWidth(width_);
	image_.setHeight(height_);

	RECT run_goku;
	run_goku.left = width_gap - 1;
	run_goku.top = 11;
	run_goku.right = run_goku.left + width_;
	run_goku.bottom = run_goku.top + height_;
	animation_.push_back(run_goku);

	//the rest of the frames are drawn based on the width
	for (int i = 1; i < 4; i++)
	{
		RECT temp;
		animation_.push_back(temp);
		animation_[i].left = animation_[i-1].right + width_gap;
		animation_[i].top = animation_[i - 1].top;
		animation_[i].right = animation_[i].left + width_;
		animation_[i].bottom = animation_[i - 1].bottom;
		if (i == 1)
		{
			animation_[i].left += 1;
			animation_[i].right += 1;
		}
		if (i == 2)
		{
			animation_[i].left -= 1;
			animation_[i].right -= 1;
		}
	}

	image_.setVector(animation_);
	
}

void Goku::walking()
{
	animation_.clear();
	max_frame_ = 3;
	width_ = 54;
	height_= 39;
	image_.setWidth(width_);
	image_.setHeight(height_);

	

	RECT walk;
	walk.left = width_gap + 1;
	walk.top = 65;
	walk.right = walk.left + width_;
	walk.bottom = walk.top + height_;
	animation_.push_back(walk);

	for (int i = 1; i <=max_frame_; i++)
	{
		RECT temp;
		animation_.push_back(temp);
		animation_[i].left = animation_[i - 1].right + width_gap;
		animation_[i].top = animation_[i - 1].top;
		animation_[i].right = animation_[i].left + width_;
		animation_[i].bottom = animation_[i - 1].bottom;
		if (i == 1)
		{
			animation_[i].left += 1;
			animation_[i].right += 1;
		}
		if (i == 2)
		{
			animation_[i].left -= 1;
			animation_[i].right -= 1;
		}
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
