#pragma once
#include "Fighter.h"
class Mario :
	public Fighter
{
public:
	Mario();
	void run();
	void neutralB();
	void sideB();//<B>
	void upB();  //^B
	void downB();//vB
	void standardAttack();//A 
};

