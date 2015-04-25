#pragma once
#include "Fighter.h"
#include "constants.h"
//
//enum Status
//{
//	HUMAN,
//	SUPER_SAIYAN
//};

class Goku :public Fighter
{
public:
	Goku();
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
};

