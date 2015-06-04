#include "Goku.h"


Goku::Goku()
{
	sprite_location_ = GOKU_SPRITE;
	spriteData.scale = 2;

	state_ = STANDING;
	
	transcolor_ = GOKU_TRANSCOLOR;
	character_ = GOKU;

	velocity.y = 0;
	velocity.x = 0;
	setGravity(10);
	setMass(1);

	collisionType = entityNS::BOX;
	radius = 20;
	//edge.left = -100;
	//edge.top = -100;
	//edge.right = 20;
	//edge.bottom = 20;
	active = true;
}


void Goku::standing()
{
	//use spritecow.com to get coordinates
	int bottom_y = 149;
	spriteData.height = 49;
	spriteData.width = 47;
	RECT standing[4];
	standing[0] = help_set_rect(25, bottom_y, spriteData.height, 46);//49
	standing[1] = help_set_rect(88, bottom_y, spriteData.height, 47);//49
	standing[2] = help_set_rect(152, bottom_y, spriteData.height, 46);//48
	standing[3] = help_set_rect(216, bottom_y, spriteData.height, 47);//49

	unstandardSprite(3, standing);
}
void Goku::walking()
{
	spriteData.height = 39;
	spriteData.width = 53;
	int bottom_y = 227;
	RECT walking[4];
	walking[0] = help_set_rect(19,bottom_y, spriteData.height, 54);//39
	walking[1] = help_set_rect(112,bottom_y,spriteData.height,52);//39
	walking[2] = help_set_rect(200,bottom_y,spriteData.height,52);//37
	walking[3] = help_set_rect(273,bottom_y,spriteData.height,53);//37
	unstandardSprite(3, walking);


	//setStandardSprite(3, 39, 55, 9, 65);
}
void Goku::running()
{
	spriteData.height = 38;
	spriteData.width = 63;
	int bottom_y = 230;
	RECT sprinting[2];
	sprinting[0] = help_set_rect(356, bottom_y, 38, 60);
	sprinting[1] = help_set_rect(439, bottom_y, 38, 63);
	unstandardSprite(1, sprinting);
}
void Goku::falling()
{

	int bottom_y=614;
	spriteData.height = 57;
	spriteData.width = 43;
	//getting punched
	RECT punched[4];
	punched[0] = help_set_rect(35, bottom_y, spriteData.height, 50);//51
	punched[1] = help_set_rect(92, bottom_y, spriteData.height, 44);//51
	punched[2] = help_set_rect(144, bottom_y, spriteData.height, 41);//55
	punched[3] = help_set_rect(193, bottom_y, spriteData.height, 43);//57
	unstandardSprite(3, punched);

}
void Goku::jumping()
{
	int bottom_y =321 ;
	spriteData.height =62 ;
	spriteData.width =41 ;
	RECT jumping[7];
	jumping[0] = help_set_rect(20, bottom_y, spriteData.height, 44);//41 abaout to jump
	jumping[1] = help_set_rect(76, bottom_y, spriteData.height, 40);//57 going up
	jumping[2] = help_set_rect(131, bottom_y, spriteData.height, 36);//40 reached highest point
	jumping[3] = help_set_rect(177, bottom_y, spriteData.height, 40);//62 coming down
	jumping[4] = help_set_rect(224, bottom_y, spriteData.height, 44);//41 REACHED BUTTOM
	jumping[5] = help_set_rect(284, bottom_y, spriteData.height, 47);//35
	jumping[6] = help_set_rect(345, bottom_y, spriteData.height, 44);//41
	unstandardSprite(6, jumping);
	
}
void Goku::blocking()
{
	int bottom_y = 515;
	spriteData.height = 49;
	spriteData.width = 43;

	RECT shield[3];
	shield[0] = help_set_rect(275, bottom_y, spriteData.height, 44);//49
	shield[1] = help_set_rect(336, bottom_y, spriteData.height, 43);//47
	shield[2] = help_set_rect(390, bottom_y, spriteData.height, 43);//49
	unstandardSprite(2, shield);

}
void Goku::neutralA()
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
	unstandardSprite(14,gtfo);

}
void Goku::neutralB()
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
void Goku::sideB()
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
void Goku::upB()
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
void Goku::downB()
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
void Goku::standardAttack()
{
	int bottom_y = 2799;
	spriteData.height = 64;
	spriteData.width = 42;

	RECT kame[9];
	kame[0] = help_set_rect(13, bottom_y, spriteData.height, 42);//51,46
	kame[1] = help_set_rect(67, bottom_y, spriteData.height, 44);//48,46
	kame[2] = help_set_rect(121, bottom_y, spriteData.height, 46);//52,46
	kame[3] = help_set_rect(177, bottom_y, spriteData.height, 86);//54,46
	kame[4] = help_set_rect(272, bottom_y, spriteData.height, 93);//54,86
	kame[5] = help_set_rect(376, bottom_y, spriteData.height, 99);//58,93
	kame[6] = help_set_rect(482, bottom_y, spriteData.height, 103);//64,99
	kame[7] = help_set_rect(596, bottom_y, spriteData.height, 171);//,51
	kame[8] = help_set_rect(13, bottom_y, spriteData.height, 42);//,51

	
	unstandardSprite(8, kame);

}
