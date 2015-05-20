#include "Piccolo.h"


Piccolo::Piccolo()
{
	sprite_location_ = PICCOLO_SPRITE;
	
	state_ = STANDING;

	scale_ = 1;
	min_frame_ = 0;

	position_.x = GAME_WIDTH/2;
	position_.y = GAME_HEIGHT/2;

	transcolor_ = PICCOLO_TRANSCOLOR;
	character_ = PICCOLO;
}
void Piccolo::standing()
{
	//settingStandardSprite(1, 5, 5, 1, 0);
	/*int bottom_y = 242;
	Sprite_Info standing[3];
	standing[0] = help_set_rect(9,bottom_y,101, 83);
	standing[1] = help_set_rect(98, bottom_y, 101, 84);
	standing[2] = help_set_rect(187, bottom_y, 101, 83);
	unstandardSprite(2, standing);*/

	int bottom_y = 242;
	Sprite_Info standing2[6];
	standing2[0] = help_set_rect(394, bottom_y, 103, 89);
	standing2[1] = help_set_rect(489, bottom_y, 103, 94);//102
	standing2[2] = help_set_rect(587, bottom_y, 103, 98);//100
	standing2[3] = help_set_rect(692, bottom_y, 103, 92);//100
	standing2[4] = help_set_rect(787, bottom_y, 103, 87);//100
	standing2[5] = help_set_rect(878, bottom_y, 103, 83);//101
	unstandardSprite(5, standing2);


}
void Piccolo::walking()
{
	int bottom_y = 356;
	Sprite_Info walking[3];
	walking[0] = help_set_rect(476, bottom_y, 93, 81);
	walking[1] = help_set_rect(567, bottom_y, 97, 110);
	walking[2] = help_set_rect(682, bottom_y, 92, 114);
	unstandardSprite(2, walking);
}
void Piccolo::running()
{
	int bottom_y =123;
	Sprite_Info cloak [6];
	cloak[0] = help_set_rect(1052, bottom_y, 126, 50);//124
	cloak[1] = help_set_rect(1106, bottom_y, 126, 71);//116
	cloak[2] = help_set_rect(1180, bottom_y, 126, 53);//124
	cloak[3] = help_set_rect(1236, bottom_y, 126, 55);
	cloak[4] = help_set_rect(1293, bottom_y, 126, 80);//125
	cloak[5] = help_set_rect(1374, bottom_y, 126, 85);//124
	unstandardSprite(5, cloak);


}
void Piccolo::falling()
{
	int bottom_y =1108;
	//Sprite_Info punched1[2];//
	//punched1[0] = help_set_rect(8, bottom_y, 95, 86);
	//punched1[punched1] = help_set_rect(96, bottom_y, 99, 72);
	//unstandardSprite(1, punched1);

	Sprite_Info punched2[2];//USE THIS ONE!!
	punched2[0] = help_set_rect(184, bottom_y, 103, 82);
	punched2[1] = help_set_rect(271, bottom_y, 102, 93);
	unstandardSprite(1, punched2);

	//Sprite_Info punched3[2];//kneeling
	//punched3[0] = help_set_rect(382, bottom_y, 89, 75);
	//punched3[1] = help_set_rect(463, bottom_y, 90, 92);
	//unstandardSprite(1, punched3);

	/*Sprite_Info punch4[2];
	punch4[0] = help_set_rect(573, bottom_y, 111, 82);
	punch4[1] = help_set_rect(659, bottom_y, 93, 81);
	unstandardSprite(1, punch4);*/

}
void Piccolo::jumping()
{
	//int bottom_y = 617;
	//Sprite_Info jumping[5];
	//jumping[0] = help_set_rect(74, bottom_y, 127, 81);//93
	//jumping[1] = help_set_rect(164, bottom_y, 127, 61);
	//jumping[2] = help_set_rect(229, bottom_y, 127, 54);//110
	//jumping[3] = help_set_rect(288, bottom_y, 127, 58);//117
	//jumping[4] = help_set_rect(350, bottom_y, 127, 81);//93
	//unstandardSprite(4, jumping);

	int bottom_y = 735;
	Sprite_Info jumping2[6]; //(right)
	jumping2[0] = help_set_rect(74, bottom_y, 93, 81);
	jumping2[1] = help_set_rect(163, bottom_y, 101, 104);
	jumping2[2] = help_set_rect(269, bottom_y, 97, 110);
	jumping2[3] = help_set_rect(382, bottom_y, 110, 54);
	jumping2[4] = help_set_rect(441, bottom_y, 117, 58);
	jumping2[5] = help_set_rect(503, bottom_y, 93, 81);
	unstandardSprite(5, jumping2);
	

}
void Piccolo::blocking()
{
	int bottom_y = 992;
	Sprite_Info crouching[2];
	crouching[0] = help_set_rect(198, bottom_y, 90, 64);//89
	crouching[1] = help_set_rect(263, bottom_y, 90, 64);
	unstandardSprite(1, crouching);
}
void Piccolo::neutralA()
{
	int bottom_y = 1890;
	//Sprite_Info punching[3];//facing back
	//punching[0] = help_set_rect(8, bottom_y, 98, 102);
	//punching[1] = help_set_rect(112, bottom_y, 95, 96);
	//punching[2] = help_set_rect(211, bottom_y, 97, 139);
	//unstandardSprite(2, punching);

	Sprite_Info punching2[3];//facing fron
	punching2[0] = help_set_rect(373, bottom_y, 99, 99);
	punching2[1] = help_set_rect(479, bottom_y, 98, 98);
	punching2[2] = help_set_rect(581, bottom_y, 99, 152);
	unstandardSprite(2, punching2);

	//Sprite_Info punching3[3];//punching up
	//punching3[0] = help_set_rect(753, bottom_y, 149, 85);//105
	//punching3[1] = help_set_rect(841, bottom_y, 149, 88);//110
	//punching3[2] = help_set_rect(931, bottom_y, 149, 94);
	//unstandardSprite(2, punching3);
}
void Piccolo::neutralB()
{
	int bottom_y = 2843;
	Sprite_Info kick[6];
	kick[0] = help_set_rect(777, bottom_y, 113, 66);
	kick[1] = help_set_rect(850, bottom_y, 122, 73);
	kick[2] = help_set_rect(931, bottom_y, 122, 139);
	kick[3] = help_set_rect(1076, bottom_y, 122, 73);
	kick[4] = help_set_rect(1157, bottom_y, 122, 73);
	kick[5] = help_set_rect(1238, bottom_y, 122, 139);
	unstandardSprite(5, kick);


}	// B
void Piccolo::sideB(){}		
void Piccolo::upB(){}			// ^B
void Piccolo::downB(){}		// vB
void Piccolo::standardAttack(){}
