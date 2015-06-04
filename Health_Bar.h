#pragma once
#include "Entity.h"

const char GOKU_BAR[] = "pictures//Health bar//GokuHP.png";
#define GOKU_BAR_TRANS SETCOLOR_ARGB(255,0,64,128)
const char PICCOLO_BAR[] = "pictures//Health bar//PiccoloHP.png";
#define PICCOLO_BAR_TRANS SETCOLOR_ARGB(255,57,115,255)
const char NARUTO_BAR[] = "pictures//Health bar//NarutoHP.png";
#define NARUTO_BAR_TRANS SETCOLOR_ARGB(255,0,128,0)
const char LUFFY_BAR[] = "pictures//Health bar//LuffyHP.png";
#define LUFFY_BAR_TRANS SETCOLOR_ARGB(255,0,128,0)

class Health_Bar
{
public:
	Health_Bar();
	void initialize(HWND hwnd, Graphics*& graphics, bool right, Character picked);
	void draw(Graphics*& graphic);
	void update(float frameTime);

private:
	Image image_;

	TextureManager texture_;
	
	bool right_;
	Character bar;
	COLOR_ARGB transcolor;
	std::string location_;
};

