#pragma once
#include "Entity.h"
#include "Fighter.h"

//player 1
const char GOKU_1[] = "pictures\\player 1\\goku.png";
const char PICCOLO_1[] = "pictures\\player 1\\piccolo.png";
const char NARUTO_1[] = "pictures\\player 1\\naruto.png";
const char LUFFY_1[] = "pictures\\player 1\\luffy.png";

//player 2
const char GOKU_2[] = "pictures\\player 2\\goku.png";
const char PICCOLO_2[] = "pictures\\player 2\\piccolo.png";
const char NARUTO_2[] = "pictures\\player 2\\naruto.png";
const char LUFFY_2[] = "pictures\\player 2\\luffy.png";


class Character_Menu 
{
public:
	Character_Menu();
	void initialize(HWND hwnd, Graphics*& graphics, bool right);
	void draw(Graphics*& graphic);
	void update(float frameTime);
	void left_change_character();//will switch between frames
	void right_change_character();
	void onLostDevice();
	Character chosen_character()const;
private:
	TextureManager goku_texture;
	TextureManager piccolo_texture;
	TextureManager naruto_texture;
	TextureManager luffy_texture;

	Image goku_image;
	Image piccolo_image;
	Image naruto_image;
	Image luffy_image;

	int frame_;//will determin what character your on
	bool right_;
	std::string goku_;
	std::string piccolo_;
	std::string naruto_;
	std::string luffy_;
};

