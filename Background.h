#pragma once
#include <string>
#include "entity.h"
#include "constants.h"

class Background :public Entity
{
public:
	Background();
	//must be included in SquirtleSquad::initialize()
	void initialize(HWND hwnd, Graphics*& graphics);
	//Include in SquirtlSquad::render()
	void draw(Graphics*& graphic);
	
protected:
	TextureManager texture_;
	int width_;
	int height_;
	int floor_;
	std::string background_location_;

	
};

