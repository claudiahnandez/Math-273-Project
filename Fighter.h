#pragma once

#include "constants.h"
#include "textureManager.h"
#include "image.h"
#include "entity.h"
#include "SquirtleSquad.h"

namespace fighterNS
{

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

	//this does not compensate for all the moves
	enum State
	{
		STANDING,
		WALKING,
		RUNNING,
		JUMPING,
		FALLING,
		CROUCHING,
	};

}

class Fighter : public Entity
{
public:
	Fighter();
	void move(const Input* input, float frameTime);
	//
	// Pure virtual functions
	// All characters must have these functions
	virtual void neutralA() = 0;		// A
	virtual void neutralB() = 0;		// B
	virtual void sideB() = 0;			// <B>
	virtual void upB() = 0;				// ^B
	virtual void downB() = 0;			// vB
	virtual void jump() = 0;//do we need jump?

	//Include in SquirtlSquad::render()
	void draw(Graphics*& graphics);

	//must be included in SquirtleSquad::initialize()
	void initialize(HWND hwnd, Graphics*& graphics, const char sprite_location[] );

	//include in SquirtleSquade::update();
	//will be need to be updated with movement
	void update(float frameTime);

protected:
	fighterNS::Position position_;	// x and y top left of character
	fighterNS::State state_;		// scene

								//picture width/height should be powers of 2
	TextureManager texture_;	//saves image from sprite sheet
	Image image_;				//draws the actual image
	int image_width_;
	int image_height_;
	int num_cols_;//columns in image;
	int scale_;
	int first_frame_;
	int last_frame_;
	int animation_delay_;
};
