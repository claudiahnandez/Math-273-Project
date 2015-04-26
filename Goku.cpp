#include "Goku.h"


Goku::Goku()
{
	sprite_location_ = GOKU_SPRITE;
	height_ = 49;
	width_ = 48;
	/*width_gap = 10;
	height_gap = 26;*/

	state_ = STANDING;
	
	min_frame_ = 0;
	
	position_.x = GAME_WIDTH / 3;
	position_.y = GAME_HEIGHT-50;

	transcolor_ = GOKU_TRANSCOLOR;
}


void Goku::standing()
{
	setStandardSprite(3, 49, 47, 10, 11);
}

void Goku::walking()
{
	setStandardSprite(3, 39, 55, 9, 65);
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
