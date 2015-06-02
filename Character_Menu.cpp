#include "Character_Menu.h"


Character_Menu::Character_Menu()
{
	player1_ = GOKU;
	player2_ = GOKU;
	frame_ = GOKU;
}

void Character_Menu::initialize(HWND hwnd, Graphics*& graphics)
{
	//initializing goku menu
	if (!goku_image.initialize(graphics,GAME_WIDTH,GAME_HEIGHT,0,&goku_texture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing GOKU menu"));

	if (!goku_texture.initialize(graphics, SELECT_GOKU,TRANSCOLORR))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing GOKU menu texture"));

	//initializing piccolo menu
	if (!piccolo_image.initialize(graphics, GAME_WIDTH, GAME_HEIGHT, 0, &piccolo_texture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing PICCOLO menu"));

	if (!piccolo_texture.initialize(graphics, SELECT_PICCOLO, TRANSCOLORR))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing start PICCOLO texture"));
	
	//initilaizing naruto menu
	if (!naruto_image.initialize(graphics, GAME_WIDTH, GAME_HEIGHT, 0, &naruto_texture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing naruto menu"));

	if (!naruto_texture.initialize(graphics, SELECT_NARUTO, TRANSCOLORR))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing start naruto texture"));
	
	//initialize luffy menu
	if (!luffy_image.initialize(graphics, GAME_WIDTH, GAME_HEIGHT, 0, &luffy_texture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing luffy menu"));

	if (!luffy_texture.initialize(graphics, SELECT_LUFFY, TRANSCOLORR))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing start luffy texture"));


}

void Character_Menu::draw(Graphics*& graphic)
{
	switch (frame_)
	{
	case GOKU:
		goku_image.draw();
		break;
	case PICCOLO:
		piccolo_image.draw();
		break;
	case NARRUTO:
		naruto_image.draw();
		break;
	case LUFFY:
		luffy_image.draw();
		break;
	}

}

void Character_Menu::update(float frameTime)
{
	switch (frame_)
	{
	case GOKU:
		goku_image.update(frameTime);
		break;
	case PICCOLO:
		piccolo_image.update(frameTime);
		break;
	case NARRUTO:
		naruto_image.update(frameTime);
		break;
	case LUFFY:
		luffy_image.update(frameTime);
		break;
	}

}

void Character_Menu::right_change_character()
{
	frame_++;
	if (frame_ > LUFFY)
	{
		frame_ = GOKU;
	}

}

void Character_Menu::left_change_character()
{
	frame_--;
	if (frame_<GOKU)
	{
		frame_ = LUFFY;
	}

}

void Character_Menu::onLostDevice()
{
	goku_texture.onLostDevice();
	piccolo_texture.onLostDevice();
	naruto_texture.onLostDevice();
	luffy_texture.onLostDevice();
}