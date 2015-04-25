#pragma once
#include "Fighter.h"

class Mario;

namespace marioNS
{
	const int WIDTH = 20;//Mario Sprite Width
	const int HEIGHT = 32;//Mario Sprite Height
	const int SPEED = 250;//pixels per second
	const char MARIO_TEXTURE[] = "pictures\\Mario_Walk_Run_Test.png";
}

class Mario :public Fighter
{
public :
	Mario();
	Mario(Graphics*& graphics);
	void standing();
	void walking();
	void running();
	void falling();
	void jumping();
	void crouching();
	void neutralA();	// A
	void neutralB();	// B
	void sideB();		// <B>
	void upB();			// ^B
	void downB();		// vB
	void standardAttack();

private:

};

