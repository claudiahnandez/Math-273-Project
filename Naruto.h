#pragma once
#include "Fighter.h"
class Naruto :
	public Fighter
{
public:
	Naruto();
	void standing();
	void walking();
	void blocking();
	void running();
	void falling();
	void jumping();
	void neutralA();	// A
	void neutralB();	// B
	void sideB();		// <B>
	void upB();			// ^B
	void downB();		// vB
	void standardAttack();
};

