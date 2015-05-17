#pragma once
#include <string>
#include <vector>
#include "constants.h"
#include "textureManager.h"
#include "image.h"
#include "entity.h"
#include "Size.h"

//struct Position
//{
//	int x;
//	int y;
//};
//
//enum  Direction
//{
//	LEFT,
//	RIGHT,
//	UP,
//	DOWN
//};
//
////this does not compensate for all the moves
//enum Fighter_State
//{
//	STANDING,
//	WALKING,
//	RUNNING,
//	JUMPING,
//	FALLING,
//	CROUCHING,
//	NEUTRAL_B,
//	SIDE_B,
//	UP_B,
//	DOWN_B,
//	STANDARD
//};

class Fighter : public Entity
{
public:
	Fighter();
	void move(const Input* input, float frameTime);

	// Pure virtual functions
	// All characters must have these functions
	void move(Direction direction);
	void setPosition(int x, int y);

	//Pure virtual functions
	//All characters must have these functions
	virtual void standing() = 0;
	virtual void walking() = 0;
	virtual void running()=0; 
	virtual void falling() = 0;
	virtual void jumping() = 0;
	virtual void neutralA() = 0;
	virtual void crouching() = 0;
	virtual void neutralB() = 0;
	virtual void sideB() = 0;			// <B>
	virtual void upB() = 0;				// ^B
	virtual void downB() = 0;			// vB
	virtual void standardAttack() = 0;	// A 
	//Include in SquirtlSquad::render()
	void draw(Graphics*& graphic);
	void setPose();
	//must be included in SquirtleSquad::initialize()
	void initialize(HWND hwnd, Graphics*& graphics);
	//include in SquirtleSquade::update();
	//will be need to be updated with movement
	void update(float frameTime);
	void setState(int state);
	void mirror(bool state);
	void setStandardSprite(int max_frame, int height, int width, int width_gap, int height_gap);
	///Claudia's fancy function
	void settingStandardSprite(int max_frame, int height, int width, int gap, int x, int y);
	//
	void unstandardSprite(int max_frame,Sprite_Info animation[]);
	//helper function
	Sprite_Info help_set_rect(int left, int bottom_y,int height, int width);

protected:
	Position position_;					// x and y top left of character
	Fighter_State state_;				// scene
	Direction direction_;

	//picture width/height should be powers of 2
	TextureManager texture_;//saves image from sprite sheet
	int max_frame_;//up to what frame do you want to show
	int min_frame_;//from where do you want to start
	int images_per_column_;//the number of images per column
	int width_;//how wide the sprite is
	int height_;//how tall the sprite is
	int scale_;
	Character character_;
	bool mirror_;
	std::string sprite_location_;
	//Option 2 get a vector of RECTS
	//Rect will be set within the state;
	std::vector<RECT> animation_;
	COLOR_ARGB transcolor_;
	Size spriteSize_;
	Frame interval_;
};
