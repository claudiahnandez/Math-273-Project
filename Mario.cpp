#include "Mario.h"


Mario::Mario() :Fighter()
{
}

void Mario::run()
{
	scale_ = 5;
	min_frame_ = 1;
	max_frame_ = 5;
	width_ = 20;
	height_ = 32;
	images_per_column_ = 9;

}


void Mario::neutralB(){}
void Mario::sideB(){}//<B>
void Mario::upB(){}  //^B
void Mario::downB(){}//vB
void Mario::standardAttack(){}//A 

