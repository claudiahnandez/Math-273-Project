#pragma once
#include <string>
#include <vector>
#include "constants.h"
#include "textureManager.h"
#include "image.h"
#include "entity.h"

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
	void move(Direction direction);
	//Pure virtual functions
	//All characters must have these functions
	virtual void run()=0; 
	virtual void neutralB() = 0;
	virtual void sideB() = 0;			// <B>
	virtual void upB() = 0;				// ^B
	virtual void downB() = 0;			// vB
	virtual void standardAttack() = 0;	// A 
	virtual void jump() = 0;

	//Include in SquirtlSquad::render()
	void draw(Graphics*& graphics);

	//must be included in SquirtleSquad::initialize()
	void initialize(HWND hwnd, Graphics*& graphics);

	//include in SquirtleSquade::update();
	//will be need to be updated with movement
	void update(float frameTime);

protected:
	Position position_;					// x and y top left of character
	Fighter_State state_;				// scene

	//picture width/height should be powers of 2
	TextureManager texture_;//saves image from sprite sheet
	TextureManager background_;
	Image   image_;//draws the actual image
	Image background_draw_;
	int max_frame_;//up to what frame do you want to show
	int min_frame_;//from where do you want to start
	int images_per_column_;//the number of images per column
	int width_;//how wide the sprite is
	int height_;//how tall the sprite is
	int scale_;
	int HP_;
	std::string sprite_location_;
	//Option 2 get a vector of RECTS
	//Rect will be set within the state;
	std::vector<RECT> animation_;
};
