#pragma once

#include "Fighter.h"

/*
* width x height
* Stand:	27 x 54 
* Walk:		49 x 47
* Block:	39 x 42
*/
class Luffy : public Fighter
{
public:
	Luffy();
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
	//helper
	void fixSprite();
};
