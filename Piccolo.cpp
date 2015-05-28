#include "Piccolo.h"


Piccolo::Piccolo()
{
	sprite_location_ = PICCOLO_SPRITE;
	
	state_ = STANDING;

	spriteData.scale = 2;

	transcolor_ = PICCOLO_TRANSCOLOR;
	character_ = PICCOLO;
}
void Piccolo::standing()
{
	int bottom_y = 94;
	spriteData.height = 47;
	spriteData.width = 53;

	RECT standing[4];
	standing[0] = help_set_rect(17, bottom_y, spriteData.height, 52);
	standing[1] = help_set_rect(79, bottom_y, spriteData.height,50);
	standing[2] = help_set_rect(140, bottom_y, spriteData.height, 52);
	standing[3] = help_set_rect(202, bottom_y, spriteData.height, 53);
	unstandardSprite(3, standing);

}
void Piccolo::walking()
{
	int bottom_y = 170;
	spriteData.height = 39;
	spriteData.width = 68;

	RECT walking[4];
	walking[0] = help_set_rect(17, bottom_y, spriteData.height, 68);//39
	walking[1] = help_set_rect(95, bottom_y, spriteData.height, 68);//38
	walking[2] = help_set_rect(174, bottom_y, spriteData.height, 68);//37
	walking[3] = help_set_rect(255, bottom_y, spriteData.height, 68);//38
	unstandardSprite(3, walking);
}
void Piccolo::running()
{
	int bottom_y = 170;
	spriteData.height = 51;
	spriteData.width = 86;

	RECT dashing[2];
	dashing[0] = help_set_rect(384, bottom_y, spriteData.height, 86);//49
	dashing[1] = help_set_rect(481, bottom_y, spriteData.height, 84);//51
	unstandardSprite(1, dashing);

}
void Piccolo::falling()
{

}
void Piccolo::jumping()
{
	int bottom_y = 900;
	spriteData.height = 66;
	spriteData.width = 40;

	RECT jumping[6];
	jumping[0] = help_set_rect(19, bottom_y, spriteData.height, 47);//43
	jumping[1] = help_set_rect(82, bottom_y, spriteData.height, 41);//58
	jumping[2] = help_set_rect(134, bottom_y, spriteData.height, 41);//58->reached top
	jumping[3] = help_set_rect(196, bottom_y, spriteData.height, 30);//66
	jumping[4] = help_set_rect(242, bottom_y, spriteData.height, 47);//43
	jumping[5] = help_set_rect(305, bottom_y, spriteData.height, 48);//40
	unstandardSprite(5, jumping);
}
void Piccolo::blocking()
{

}
void Piccolo::neutralA()
{

}
void Piccolo::neutralB()
{

}	// B
void Piccolo::sideB(){}		
void Piccolo::upB(){}			// ^B
void Piccolo::downB(){}		// vB
void Piccolo::standardAttack(){}
