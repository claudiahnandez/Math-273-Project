#include "Piccolo.h"


Piccolo::Piccolo()
{
	sprite_location_ = PICCOLO_SPRITE;
	
	state_ = STANDING;

	position_.x = GAME_WIDTH / 3;
	position_.y = GAME_HEIGHT - 200;

	transcolor_ = PICCOLO_TRANSCOLOR;

}

void Piccolo::standing()
{
	setStandardSprite(3, 50, 60, 15, 45);
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
