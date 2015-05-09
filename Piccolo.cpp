#include "Piccolo.h"


Piccolo::Piccolo()
{
	sprite_location_ = PICCOLO_SPRITE;
	
	state_ = STANDING;

	scale_ = 1;


	position_.x = GAME_WIDTH / 3;
	position_.y = GAME_HEIGHT - 200;

	transcolor_ = PICCOLO_TRANSCOLOR;

}

void Piccolo::standing()
{
	//settingStandardSprite(1, 5, 5, 1, 0);
}
void Piccolo::walking(){}
void Piccolo::running(){}
void Piccolo::falling(){}
void Piccolo::jumping(){}
void Piccolo::crouching(){}
void Piccolo::neutralA(){}	// A
void Piccolo::neutralB(){}	// B
void Piccolo::sideB(){}		// <B>
void Piccolo::upB(){}			// ^B
void Piccolo::downB(){}		// vB
void Piccolo::standardAttack(){}
