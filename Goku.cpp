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
	
	position_.x = GAME_WIDTH / 3;
	position_.y = GAME_HEIGHT-50;

	transcolor_ = GOKU_TRANSCOLOR;
}


void Goku::standing()
{
	setStandardSprite(3, 55, 55, 10, 11);
	}

void Goku::walking()
{
	animation_.clear();
	max_frame_ = 3;

	setStandardSprite(3, 50, 65, 0, 65);

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
