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
	character_ = GOKU;

	// Set collision type (NONE, CIRCLE, BOX, ROTATED_BOX)
	setCollisionType(entityNS::BOX);
	velocity.y = 0;
	velocity.x = 0;
	setGravity(10);
	setMass(1);
}


void Goku::standing()
{
	//use spritecow.com to get coordinates
	Sprite_Info standing[4];
	standing[0] = help_set_rect(10, 61, 49, 47);
	standing[1] = help_set_rect(68, 61, 49, 46);
	standing[2] = help_set_rect(124, 61, 49, 47);
	standing[3] = help_set_rect(181, 61, 49, 46);

	unstandardSprite(3, standing);
}
void Goku::walking()
{
	Sprite_Info walking[4];
	walking[0] = help_set_rect(11,107, 39, 54);
	walking[1] = help_set_rect(76,107,39,52);
	walking[2] = help_set_rect(139,107,39,52);//37
	walking[3] = help_set_rect(202,107,39,53);//37
	unstandardSprite(3, walking);


	//setStandardSprite(3, 39, 55, 9, 65);
}
void Goku::running()
{
	Sprite_Info sprinting[2];
	sprinting[0] = help_set_rect(9,150,38,61);
	sprinting[1] = help_set_rect(80,150,38,63);
	unstandardSprite(1, sprinting);
	
	min_frame_ = 1;
	max_frame_ = 1;
}
void Goku::falling()
{
	//getting punched
	Sprite_Info punched[4];
	punched[3] = help_set_rect(16, 800, 51, 50);
	punched[2] = help_set_rect(73, 800, 51, 44);
	punched[1] = help_set_rect(125, 800, 55, 41);
	punched[0] = help_set_rect(174, 800, 57, 43);
	unstandardSprite(3, punched);

}
void Goku::jumping()
{
	
	Sprite_Info jumping[7];
	jumping[0] = help_set_rect(10, 210, 41, 44);//abaout to jump
	jumping[1] = help_set_rect(64, 210, 57, 40);//57 going up
	jumping[2] = help_set_rect(114, 210, 40, 36);//40 reached highest point
	jumping[3] = help_set_rect(160, 210, 62, 40);//62 coming down
	jumping[4] = help_set_rect(210, 210, 41, 44);//41 REACHED BUTTOM
	jumping[5] = help_set_rect(264, 210, 35, 47);//35
	jumping[6] = help_set_rect(320, 210, 41, 44);//41
	unstandardSprite(0, jumping);
	
}
void Goku::blocking()
{
	Sprite_Info shield[3];
	shield[0] = help_set_rect(777, 290, 49, 44);
	shield[1] = help_set_rect(829, 290, 49, 43);//47
	shield[2] = help_set_rect(879, 290, 49, 43);
	unstandardSprite(2, shield);
}
void Goku::neutralA()
{
	//Image::setFrames(0, 14);
	Sprite_Info gtfo[15];
	gtfo[0] = help_set_rect(15, 1105, 47, 41);
	gtfo[1] = help_set_rect(65, 1105, 47, 40);//44
	gtfo[2] = help_set_rect(115, 1105, 47, 40);//43
	gtfo[3] = help_set_rect(165, 1105, 47, 40);//44
	gtfo[4] = help_set_rect(215, 1105, 47, 40);//43
	gtfo[5] = help_set_rect(265, 1105, 47, 40);//44
	gtfo[6] = help_set_rect(315, 1105, 47, 84);//43
	gtfo[7] = help_set_rect(409, 1105, 47, 112);//43
	gtfo[8] = help_set_rect(533, 1105, 47, 148);//41
	gtfo[9] = help_set_rect(691, 1105, 47, 158);//41
	gtfo[10] = help_set_rect(861, 1105, 47, 168);//41
	gtfo[11] = help_set_rect(1040, 1105, 47, 166);//41
	gtfo[12] = help_set_rect(1215, 1105, 47, 165);//41
	gtfo[13] = help_set_rect(1392, 1105, 47, 51);//41
	gtfo[14] = help_set_rect(1453, 1105, 47, 43);//43
	unstandardSprite(14,gtfo);
}
void Goku::neutralB()
{
	Sprite_Info punch[6];
	punch[0] = help_set_rect(13,366,52,44);//50
	punch[1] = help_set_rect(67, 366, 52, 43);
	punch[2] = help_set_rect(120, 366, 52, 42);//48;
	punch[3] = help_set_rect(172, 366, 52, 63);//48
	punch[4] = help_set_rect(245, 366, 52, 63);//48
	punch[5] = help_set_rect(318, 366, 52, 43);//50
	unstandardSprite(5, punch);
}
void Goku::sideB()
{
	Sprite_Info air_kick[13];
	air_kick[0] = help_set_rect(14,470,45,42);
	air_kick[1] = help_set_rect(66, 470, 52, 38);
	air_kick[2] = help_set_rect(114, 470, 57, 52);
	air_kick[3] = help_set_rect(176, 470, 51, 57);
	air_kick[4] = help_set_rect(243, 470, 53, 63);
	air_kick[5] = help_set_rect(316, 470, 55, 58);
	air_kick[6] = help_set_rect(384, 470, 55, 57);
	air_kick[7] = help_set_rect(451, 470, 51, 57);
	air_kick[8] = help_set_rect(518, 470, 53, 63);
	air_kick[9] = help_set_rect(591, 470, 55, 58);
	air_kick[10] = help_set_rect(659, 470, 55, 57);
	air_kick[11] = help_set_rect(730, 470, 48, 41);
	air_kick[12] = help_set_rect(784, 470, 52, 43);

	Sprite_Info kick[11];
	kick[0] = help_set_rect(13, 415, 51, 44);//49
	kick[1] = help_set_rect(67, 415, 51, 43);//50
	kick[2] = help_set_rect(120, 415, 51, 41);
	kick[3] = help_set_rect(171, 415, 51, 59);//42
	kick[4] = help_set_rect(240, 415, 51, 58);//44
	kick[5] = help_set_rect(308, 415, 51, 63);//42
	kick[6] = help_set_rect(382, 415, 51, 61);//44
	kick[7] = help_set_rect(453, 415, 51, 59);//42
	kick[8] = help_set_rect(523, 415, 51, 41);//51
	kick[9] = help_set_rect(574, 415, 51, 43);//50
	kick[10] = help_set_rect(628, 415, 51, 44);//49

	unstandardSprite(10, kick);

}
void Goku::upB()
{
	//Image::setFrames(1, 1);
	Sprite_Info slash[5];
	slash[0] = help_set_rect(16, 1003, 64, 39);
	slash[1] = help_set_rect(65, 1003, 64, 43);//57
	slash[2] = help_set_rect(118, 1003, 64, 54);//61
	slash[3] = help_set_rect(182, 1003, 64, 54);//44
	slash[4] = help_set_rect(246, 1003, 64, 39);//46

	unstandardSprite(4, slash);

}			
void Goku::downB()
{
	Sprite_Info ball[8];
	ball[0] = help_set_rect(17, 942, 72, 38);//30
	ball[1] = help_set_rect(68, 942, 72, 49);//58
	ball[2] = help_set_rect(127, 942, 72, 49);//30
	ball[3] = help_set_rect(186, 942, 72, 53);//58
	ball[4] = help_set_rect(249, 942, 72, 39);//30
	ball[5] = help_set_rect(298, 942, 72, 44);//58
	ball[6] = help_set_rect(352, 942, 72, 47);//30
	ball[7] = help_set_rect(408, 942, 72, 44);//58
	unstandardSprite(7, ball);

	//int bottom_height = 1187;
	//Sprite_Info power_up[7];
	//power_up[0] = help_set_rect(16, bottom_height, 87, 44);//49
	//power_up[1] = help_set_rect(70, bottom_height, 87, 44);//47
	//power_up[2] = help_set_rect(123, bottom_height, 87, 70);//73
	//power_up[3] = help_set_rect(203, bottom_height, 87, 82);//80
	//power_up[4] = help_set_rect(296, bottom_height, 87, 92);//85
	//power_up[5] = help_set_rect(397, bottom_height, 87, 96);
	//power_up[6] = help_set_rect(506, bottom_height, 87, 44);//48
	//unstandardSprite(6, power_up);

	//int bottom_y = 855;
	//Sprite_Info k_o[11];
	//k_o[0] = help_set_rect(16, bottom_y, 56, 60);//35
	//k_o[1] = help_set_rect(90, bottom_y, 56, 60);//37
	//k_o[2] = help_set_rect(158, bottom_y, 56, 58);//31
	//k_o[3] = help_set_rect(227, bottom_y, 56, 63);//31
	//k_o[4] = help_set_rect(301, bottom_y, 56, 63);//45
	//k_o[5] = help_set_rect(374, bottom_y, 56, 48);//39
	//k_o[6] = help_set_rect(430, bottom_y, 56, 67);//20
	//k_o[7] = help_set_rect(504, bottom_y, 56, 32);//38
	//k_o[8] = help_set_rect(545, bottom_y, 56, 59);//32
	//k_o[9] = help_set_rect(613, bottom_y, 56, 45);
	//k_o[10] = help_set_rect(667, bottom_y, 56, 47);//35
	//unstandardSprite(10, k_o);

}	
void Goku::standardAttack()
{
	Image::setFrames(0, 8);
	Image::setWidth(43);

	Sprite_Info kame[9];
	kame[0] = help_set_rect(15,535,64,43);//43
	kame[1] = help_set_rect(68, 535, 64, 46);//46
	kame[2] = help_set_rect(124, 535, 64, 46);//49
	kame[3] = help_set_rect(181, 535, 64, 46);//52
	kame[4] = help_set_rect(237, 535, 64, 86);//54
	kame[5] = help_set_rect(332, 535, 64, 93);//54
	kame[6] = help_set_rect(436, 535, 64, 99);//58
	kame[7] = help_set_rect(542, 535, 64, 103);
	kame[8] = help_set_rect(711, 535, 64, 172);//48
	unstandardSprite(7, kame);

}
