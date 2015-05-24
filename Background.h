#pragma once
#include <string>
#include "entity.h"
#include "constants.h"
#include "Fighter.h"

class Background :public Entity
{
public:
	Background();
	//Background(COLOR_ARGB transcolor_, std::string bk);
	//must be included in SquirtleSquad::initialize()
	void initialize(HWND hwnd, Graphics*& graphics);
	//Include in SquirtlSquad::render()
	void draw(Graphics*& graphic);
	void update(float frameTime);
	virtual void set_image() = 0;
	void set_animation(Sprite_Info animation[]);
	int get_floor();
	
protected:
	TextureManager texture_;
	int floor_;
	std::string background_location_;
};

