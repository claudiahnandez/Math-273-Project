#pragma once
#include <string>
#include "entity.h"
#include "constants.h"
#include "Fighter.h"

class Background :public Entity
{
public:
	Background();
	//must be included in SquirtleSquad::initialize()
	void initialize(HWND hwnd, Graphics*& graphics);
	//Include in SquirtlSquad::render()
	void draw(Graphics*& graphic);
	void update(float frameTime);
	virtual void set_image() = 0;
	void set_animation(Sprite_Info animation[]);
	
protected:
	TextureManager texture_;
	int width_;
	int height_;
	int floor_;
	int scale_;
	int max_frames;
	std::string background_location_;

	
};

