#include "Goku.h"


Goku::Goku()
{
	sprite_location_ = GOKU_SPRITE;
	height_ = 55;
	width_ = 55;

	state_ = STANDING;
	max_frame_ = 4;
	
	position_.x = GAME_WIDTH / 3;
	position_.y = GAME_HEIGHT-50;

	//default
	//goku_runnig
	
	/*makes first rect as a basis
	RECT run_goku;
	run_goku.left = 10;
	run_goku.top = 15;
	run_goku.right = run_goku.left + width_;
	run_goku.bottom = run_goku.top + height_;
	animation_.push_back(run_goku);

	the rest of the frames are drawn based on the width
	for (int i = 1; i < max_frame_; i++)
	{
		RECT temp;
		animation_.push_back(temp);
		animation_[i].left = animation_[0].left + (i*width_);
		animation_[i].top = animation_[0].top;
		animation_[i].right = animation_[0].right + (i*width_);
		animation_[i].bottom = animation_[0].bottom;
	}
	*/
}


void Goku::standing()
{
	animation_.clear();

	transcolor_ = GOKU_TRANSCOLOR;


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

void Goku::walking(){}
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
