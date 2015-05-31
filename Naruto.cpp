#include "Naruto.h"


Naruto::Naruto()
{
	sprite_location_ = NARUTO_SPRITE;
	spriteData.scale = 2;

	state_ = STANDING;

	transcolor_ = NARUTO_TRANSCOLOR;
	character_ = NARRUTO;

	// Set collision type (NONE, CIRCLE, BOX, ROTATED_BOX)
	setCollisionType(entityNS::BOX);
	velocity.y = 0;
	velocity.x = 0;
	setGravity(10);
	setMass(1);
}

void Naruto::standing()
{
	//use spritecow.com to get coordinates
	int bottom_y = 176;
	spriteData.height = 52;
	spriteData.width = 35;
	RECT standing[4];
	standing[0] = help_set_rect(9, bottom_y, spriteData.height, 37);//52
	standing[1] = help_set_rect(58, bottom_y, spriteData.height, 37);//52
	standing[2] = help_set_rect(109, bottom_y, spriteData.height, 37);//50
	standing[3] = help_set_rect(161, bottom_y, spriteData.height, 37);//51

	unstandardSprite(3, standing);
}
void Naruto::walking()
{
	spriteData.height = 47;
	spriteData.width = 32;
	int bottom_y = 254;
	RECT walking[8];
	walking[0] = help_set_rect(9, bottom_y, spriteData.height, 37);//47
	walking[1] = help_set_rect(66, bottom_y, spriteData.height, 40);//46
	walking[2] = help_set_rect(122, bottom_y, spriteData.height, 38);//46
	walking[3] = help_set_rect(180, bottom_y, spriteData.height, 32);//46
	walking[4] = help_set_rect(229, bottom_y, spriteData.height, 38);//47
	walking[5] = help_set_rect(284, bottom_y, spriteData.height, 39);//46
	walking[6] = help_set_rect(345, bottom_y, spriteData.height, 38);//46
	walking[7] = help_set_rect(400, bottom_y, spriteData.height, 32);//46
	unstandardSprite(7, walking);


	//setStandardSprite(3, 39, 55, 9, 65);
}
void Naruto::running()
{
	spriteData.height = 38;
	spriteData.width = 63;
	int bottom_y = 254;
	RECT sprinting[2];
	sprinting[0] = help_set_rect(528, bottom_y, 41, 47);//41
	sprinting[1] = help_set_rect(594, bottom_y, 41, 48);
	unstandardSprite(1, sprinting);
}
void Naruto::falling()
{

	int bottom_y = 429;
	spriteData.height = 51;
	spriteData.width = 36;
	//getting punched
	RECT punched[4];
	punched[0] = help_set_rect(9, bottom_y, spriteData.height, 37);//51
	punched[1] = help_set_rect(68, bottom_y, spriteData.height, 38);//47
	punched[2] = help_set_rect(130, bottom_y, spriteData.height, 42);//44
	punched[3] = help_set_rect(202, bottom_y, spriteData.height, 36);//45
	unstandardSprite(3, punched);

}
void Naruto::jumping()
{
	int bottom_y = 345;
	spriteData.height = 65;
	spriteData.width = 33;
	RECT jumping[8];
	jumping[0] = help_set_rect(9, bottom_y, spriteData.height, 33);//43 abaout to jump
	jumping[1] = help_set_rect(54, bottom_y, spriteData.height, 39);//51 going up
	jumping[2] = help_set_rect(107, bottom_y, spriteData.height, 39);//51 reached highest point
	jumping[3] = help_set_rect(167, bottom_y, spriteData.height, 34);//52 coming down
	jumping[4] = help_set_rect(216, bottom_y, spriteData.height, 34);//52 REACHED BUTTOM
	jumping[5] = help_set_rect(269, bottom_y, spriteData.height, 33);//43
	jumping[6] = help_set_rect(319, bottom_y, spriteData.height, 34);//35
	jumping[7] = help_set_rect(366, bottom_y, spriteData.height, 33);//43
	unstandardSprite(7, jumping);

}
void Naruto::blocking()
{
	int bottom_y = 345;
	spriteData.height = 50;
	spriteData.width = 34;

	RECT shield[3];
	shield[0] = help_set_rect(502, bottom_y, spriteData.height, 33);//50
	shield[1] = help_set_rect(554, bottom_y, spriteData.height, 32);//45
	shield[2] = help_set_rect(605, bottom_y, spriteData.height, 34);//48
	unstandardSprite(2, shield);

}
void Naruto::neutralA()
{
	int bottom_y = 1098;
	spriteData.height = 35;
	spriteData.width = 43;

	RECT gtfo[15];
	gtfo[0] = help_set_rect(15, bottom_y, spriteData.height, 41);
	gtfo[1] = help_set_rect(65, bottom_y, spriteData.height, 40);//44
	gtfo[2] = help_set_rect(115, bottom_y, spriteData.height, 40);//43
	gtfo[3] = help_set_rect(165, bottom_y, spriteData.height, 40);//44
	gtfo[4] = help_set_rect(215, bottom_y, spriteData.height, 40);//43
	gtfo[5] = help_set_rect(265, bottom_y, spriteData.height, 40);//44
	gtfo[6] = help_set_rect(315, bottom_y, spriteData.height, 84);//43
	gtfo[7] = help_set_rect(409, bottom_y, spriteData.height, 112);//43
	gtfo[8] = help_set_rect(533, bottom_y, spriteData.height, 148);//41
	gtfo[9] = help_set_rect(691, bottom_y, spriteData.height, 158);//41
	gtfo[10] = help_set_rect(861, bottom_y, spriteData.height, 168);//41
	gtfo[11] = help_set_rect(1040, bottom_y, spriteData.height, 166);//41
	gtfo[12] = help_set_rect(1215, bottom_y, spriteData.height, 165);//41
	gtfo[13] = help_set_rect(1392, bottom_y, spriteData.height, 51);//41
	gtfo[14] = help_set_rect(1453, bottom_y, spriteData.height, 43);//43
	unstandardSprite(14, gtfo);

}
void Naruto::neutralB()
{
	int bottom_y = 1658;
	spriteData.height = 52;
	spriteData.width = 43;
	RECT punch[6];
	punch[0] = help_set_rect(12, bottom_y, spriteData.height, 44);//50
	punch[1] = help_set_rect(72, bottom_y, spriteData.height, 43);//52
	punch[2] = help_set_rect(125, bottom_y, spriteData.height, 42);//48;
	punch[3] = help_set_rect(177, bottom_y, spriteData.height, 63);//48
	punch[4] = help_set_rect(250, bottom_y, spriteData.height, 63);//48
	punch[5] = help_set_rect(323, bottom_y, spriteData.height, 43);//50
	unstandardSprite(5, punch);
}
void Naruto::sideB()
{
	//RECT air_kick[13];
	//air_kick[0] = help_set_rect(14,470,45,42);
	//air_kick[1] = help_set_rect(66, 470, 52, 38);
	//air_kick[2] = help_set_rect(114, 470, 57, 52);
	//air_kick[3] = help_set_rect(176, 470, 51, 57);
	//air_kick[4] = help_set_rect(243, 470, 53, 63);
	//air_kick[5] = help_set_rect(316, 470, 55, 58);
	//air_kick[6] = help_set_rect(384, 470, 55, 57);
	//air_kick[7] = help_set_rect(451, 470, 51, 57);
	//air_kick[8] = help_set_rect(518, 470, 53, 63);
	//air_kick[9] = help_set_rect(591, 470, 55, 58);
	//air_kick[10] = help_set_rect(659, 470, 55, 57);
	//air_kick[11] = help_set_rect(730, 470, 48, 41);
	//air_kick[12] = help_set_rect(784, 470, 52, 43);


	int bottom_y = 408;
	spriteData.height = 41;
	spriteData.width = 44;
	RECT kick[11];
	kick[0] = help_set_rect(13, bottom_y, spriteData.height, 44);//49
	kick[1] = help_set_rect(67, bottom_y, spriteData.height, 43);//50
	kick[2] = help_set_rect(120, bottom_y, spriteData.height, 41);
	kick[3] = help_set_rect(171, bottom_y, spriteData.height, 59);//42
	kick[4] = help_set_rect(240, bottom_y, spriteData.height, 58);//44
	kick[5] = help_set_rect(308, bottom_y, spriteData.height, 63);//42
	kick[6] = help_set_rect(382, bottom_y, spriteData.height, 61);//44
	kick[7] = help_set_rect(453, bottom_y, spriteData.height, 59);//42
	kick[8] = help_set_rect(523, bottom_y, spriteData.height, 41);//51
	kick[9] = help_set_rect(574, bottom_y, spriteData.height, 43);//50
	kick[10] = help_set_rect(628, bottom_y, spriteData.height, 44);//49
	spriteData.height = 51;

	unstandardSprite(10, kick);

}
void Naruto::upB()
{
	//Image::setFrames(1, 1);
	RECT slash[5];
	slash[0] = help_set_rect(16, 1003, 64, 39);
	slash[1] = help_set_rect(65, 1003, 57, 43);//57
	slash[2] = help_set_rect(118, 1003, 61, 54);//61
	slash[3] = help_set_rect(182, 1003, 44, 54);//44
	slash[4] = help_set_rect(246, 1003, 46, 39);//46
	spriteData.height = 64;

	unstandardSprite(4, slash);

}
void Naruto::downB()
{
	int bottom_y = 2237;
	spriteData.height = 57;
	spriteData.width = 44;

	RECT ball[6];
	ball[0] = help_set_rect(6, bottom_y, spriteData.height, 38);//29
	ball[1] = help_set_rect(50, bottom_y, spriteData.height, 46);//55
	ball[2] = help_set_rect(117, bottom_y, spriteData.height, 49);//57
	ball[3] = help_set_rect(186, bottom_y, spriteData.height, 48);//29
	ball[4] = help_set_rect(250, bottom_y, spriteData.height, 46);//36
	ball[5] = help_set_rect(315, bottom_y, spriteData.height, 44);//35
	unstandardSprite(5, ball);

	//int bottom_height = 1187;
	//RECT power_up[7];
	//power_up[0] = help_set_rect(16, bottom_height, 87, 44);//49
	//power_up[1] = help_set_rect(70, bottom_height, 87, 44);//47
	//power_up[2] = help_set_rect(123, bottom_height, 87, 70);//73
	//power_up[3] = help_set_rect(203, bottom_height, 87, 82);//80
	//power_up[4] = help_set_rect(296, bottom_height, 87, 92);//85
	//power_up[5] = help_set_rect(397, bottom_height, 87, 96);
	//power_up[6] = help_set_rect(506, bottom_height, 87, 44);//48
	//unstandardSprite(6, power_up);

	//int bottom_y = 855;
	//RECT k_o[11];
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
void Naruto::standardAttack()
{
	int bottom_y = 2789;
	spriteData.height = 48;
	spriteData.width = 54;

	RECT kame[9];
	kame[0] = help_set_rect(18, bottom_y, spriteData.height, 32);//50
	kame[1] = help_set_rect(65, bottom_y, spriteData.height, 39);//48
	kame[2] = help_set_rect(117, bottom_y, spriteData.height, 39);//48
	kame[3] = help_set_rect(185, bottom_y, spriteData.height, 48);//43
	kame[4] = help_set_rect(248, bottom_y, spriteData.height, 49);//43
	kame[5] = help_set_rect(325, bottom_y, spriteData.height, 60);//41
	kame[6] = help_set_rect(398, bottom_y, spriteData.height, 57);//41
	kame[7] = help_set_rect(468, bottom_y, spriteData.height, 54);//40
	kame[8] = help_set_rect(534, bottom_y, spriteData.height, 54);//40


	unstandardSprite(8, kame);

}



