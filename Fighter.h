#pragma once
#include <string>
#include <vector>
#include "constants.h"
#include "textureManager.h"
#include "image.h"
#include "entity.h"
#include "Size.h"



class Fighter : public Entity
{
public:
	Fighter();
	void move(const Input* input, float frameTime);

	// Pure virtual functions
	// All characters must have these functions
	void move(Direction direction);

	//Pure virtual functions
	//All characters must have these functions
	virtual void standing() = 0;
	virtual void walking() = 0;
	virtual void blocking() = 0;
	virtual void running()=0; 
	virtual void falling() = 0;
	virtual void jumping() = 0;
	virtual void neutralA() = 0;
	virtual void neutralB() = 0;
	virtual void sideB() = 0;			// <B>
	virtual void upB() = 0;				// ^B
	virtual void downB() = 0;			// vB
	virtual void standardAttack() = 0;	// A 
	//Include in SquirtlSquad::render()
	void draw(Graphics*& graphic);
	void setPose();
	//must be included in SquirtleSquad::initialize()
	void initialize(HWND hwnd, Graphics*& graphics, int floor);
	//include in SquirtleSquade::update();
	//will be need to be updated with movement
	void update(float frameTime);
	void setState(int state);
	//void setStandardSprite(int max_frame, int height, int width, int width_gap, int height_gap);
	void unstandardSprite(int max_frame,RECT animation[]);
	//used to make fighter stick to ground
	void stick_to_floor();
	//helper function
	friend RECT help_set_rect(int left, int bottom_y,int height, int width);



protected:
	Fighter_State state_;				// scene
	Direction direction_;
	bool jumping_;
	double acceleration_ = 100;
	double max_speed_ = 1000;

	TextureManager texture_;//saves image from sprite sheet
	Character character_;
	int floor_;
	std::string sprite_location_;
	//Option 2 get a vector of RECTS
	//Rect will be set within the state;
	std::vector<RECT> animation_;
	COLOR_ARGB transcolor_;
	Size spriteSize_;
	Frame interval_;
};
