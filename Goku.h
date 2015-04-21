#pragma once
#include "Fighter.h"
#include "constants.h"

class Goku :
	public Fighter
{
public:
	Goku();
	void run();
	void neutralA();	// A
	void neutralB();	// B
	void sideB();		// <B>
	void upB();			// ^B
	void downB();		// vB
	void jump();
};

