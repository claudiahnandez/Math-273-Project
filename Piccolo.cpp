#include "Piccolo.h"


Piccolo::Piccolo()
{
	sprite_location_ = PICCOLO_SPRITE;
	
	state_ = STANDING;

	spriteData.scale = 2;

	transcolor_ = PICCOLO_TRANSCOLOR;
	//transcolor_ = TRANSCOLORR;

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
	int bottom_y = 1952;
	spriteData.height = 62;
	spriteData.width = 56;

	RECT jumping[4];
	jumping[0] = help_set_rect(26, bottom_y, spriteData.height, 55);//41
	jumping[1] = help_set_rect(96, bottom_y, spriteData.height, 51);//49
	jumping[2] = help_set_rect(163, bottom_y, spriteData.height, 49);//62->reached top
	jumping[3] = help_set_rect(221, bottom_y, spriteData.height, 56);//56
	unstandardSprite(3, jumping);
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
	int bottom_y = 88;
	spriteData.height = 47;
	spriteData.width = 47;

	RECT dashing[3];
	dashing[0] = help_set_rect(300, bottom_y, spriteData.height, 45);//47
	dashing[1] = help_set_rect(356, bottom_y, spriteData.height, 50);//45
	dashing[2] = help_set_rect(415, bottom_y, spriteData.height, 47);//47
	unstandardSprite(1, dashing);

}
void Piccolo::neutralA()
{
	int bottom_y = 468;
	spriteData.height = 96;
	spriteData.width = 50;

	RECT light[12];
	light[0] = help_set_rect(16, bottom_y, spriteData.height, 52);//48
	light[1] = help_set_rect(83, bottom_y, spriteData.height, 59);//53
	light[2] = help_set_rect(166, bottom_y, spriteData.height, 62);//47->reached top
	light[3] = help_set_rect(245, bottom_y, spriteData.height, 59);//49
	light[4] = help_set_rect(325, bottom_y, spriteData.height, 83);//62
	light[5] = help_set_rect(418, bottom_y, spriteData.height, 114);//96
	light[6] = help_set_rect(550, bottom_y, spriteData.height, 139);//71
	light[7] = help_set_rect(693, bottom_y, spriteData.height, 164);//54->reached top
	light[8] = help_set_rect(876, bottom_y, spriteData.height, 173);//49
	light[9] = help_set_rect(1059, bottom_y, spriteData.height, 59);//49
	light[10] = help_set_rect(1132, bottom_y, spriteData.height, 58);//49
	light[11] = help_set_rect(1200, bottom_y, spriteData.height, 50);//48
	unstandardSprite(11, light);
}
void Piccolo::neutralB()
{
	int bottom_y = 267;
	spriteData.height = 54;
	spriteData.width = 59;

	RECT smack[5];
	smack[0] = help_set_rect(22, bottom_y, spriteData.height, 47);//54
	smack[1] = help_set_rect(81, bottom_y, spriteData.height, 84);//52
	smack[2] = help_set_rect(175, bottom_y, spriteData.height, 68);//52->reached top
	smack[3] = help_set_rect(266, bottom_y, spriteData.height, 60);//49
	smack[4] = help_set_rect(345, bottom_y, spriteData.height, 59);//47
	unstandardSprite(4, smack);

}	// B
void Piccolo::sideB(){}		
void Piccolo::upB(){}			// ^B
void Piccolo::downB(){}	
// vB
void Piccolo::standardAttack()
{
	int bottom_y = 816;
	spriteData.height = 60;
	spriteData.width = 48;

	RECT lightning[12];
	lightning[0] = help_set_rect(24, bottom_y, spriteData.height, 49);//51
	lightning[1] = help_set_rect(84, bottom_y, spriteData.height, 52);//55
	lightning[2] = help_set_rect(150, bottom_y, spriteData.height, 52);//48->reached top
	lightning[3] = help_set_rect(216, bottom_y, spriteData.height, 76);//57
	lightning[4] = help_set_rect(303, bottom_y, spriteData.height, 92);//57
	lightning[5] = help_set_rect(413, bottom_y, spriteData.height, 108);//58
	lightning[6] = help_set_rect(537, bottom_y, spriteData.height, 124);//59
	lightning[7] = help_set_rect(673, bottom_y, spriteData.height, 123);//58->reached top
	lightning[8] = help_set_rect(811, bottom_y, spriteData.height, 123);//60
	lightning[9] = help_set_rect(944, bottom_y, spriteData.height, 51);//48
	lightning[10] = help_set_rect(1008, bottom_y, spriteData.height,51);//48
	lightning[11] = help_set_rect(1075, bottom_y, spriteData.height, 48);//48
	unstandardSprite(11, lightning);
}
