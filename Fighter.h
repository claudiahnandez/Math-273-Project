#pragma once

#include "constants.h"
#include "textureManager.h"
#include "image.h"
#include "entity.h"
#include "SquirtleSquad.h"

struct Position
{
	int x;
	int y;
};

enum  Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

enum Fighter_State
{
	STANDING,
	WALKING,
	RUNNING,
	JUMPING,
	FALLING, 
	CROUCHING,
};

class Fighter : public Entity
{
public:
	Fighter();
	void move(const Input* input, float frameTime);

	// Pure virtual functions
	// All characters must have these functions
	virtual void neutralB() = 0;		// B
	virtual void sideB() = 0;			// <B>
	virtual void upB() = 0;				// ^B
	virtual void downB() = 0;			// vB
	virtual void standardAttack() = 0;	// A 
	virtual void jump() = 0;

protected:
	Position position_;					// x and y top left of character
	Fighter_State state_;				// scene

	TextureManager texture_;			// 
	Image   image_;						
};
