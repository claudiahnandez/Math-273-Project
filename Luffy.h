#pragma once

#include "Fighter.h"

class Luffy : public Fighter
{
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

};