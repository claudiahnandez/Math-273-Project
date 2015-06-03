#include "Character_Menu.h"


Character_Menu::Character_Menu()
{
	frame_ = GOKU;
}

void Character_Menu::initialize(HWND hwnd, Graphics*& graphics, bool right)
{
	if (right)//PLAYER 2
	{
		goku_ = GOKU_2;
		piccolo_ = PICCOLO_2;
		naruto_ = NARUTO_2;
		luffy_ = LUFFY_2;
	}
	else//player 1
	{
		goku_ = GOKU_1;
		piccolo_ = PICCOLO_1;
		naruto_ = NARUTO_1;
		luffy_ = LUFFY_1;
	}

	//initializing goku menu
	if (!goku_image.initialize(graphics,GAME_WIDTH,GAME_HEIGHT,0,&goku_texture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing GOKU menu"));

	if (!goku_texture.initialize(graphics,goku_,TRANSCOLORR))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing GOKU menu texture"));

	//initializing piccolo menu
	if (!piccolo_image.initialize(graphics, GAME_WIDTH, GAME_HEIGHT, 0, &piccolo_texture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing PICCOLO menu"));

	if (!piccolo_texture.initialize(graphics, piccolo_, TRANSCOLORR))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing start PICCOLO texture"));
	
	//initilaizing naruto menu
	if (!naruto_image.initialize(graphics, GAME_WIDTH, GAME_HEIGHT, 0, &naruto_texture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing naruto menu"));

	if (!naruto_texture.initialize(graphics, naruto_, TRANSCOLORR))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing start naruto texture"));
	
	//initialize luffy menu
	if (!luffy_image.initialize(graphics, GAME_WIDTH, GAME_HEIGHT, 0, &luffy_texture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing luffy menu"));

	if (!luffy_texture.initialize(graphics, luffy_, TRANSCOLORR))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing start luffy texture"));
	
	//place player 2 on the other side of screem
	if (right)
	{
		goku_image.setX(GAME_WIDTH / 2);
		piccolo_image.setX(GAME_WIDTH / 2);
		naruto_image.setX(GAME_WIDTH / 2);
		luffy_image.setX(GAME_WIDTH / 2);
	}

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

Character Character_Menu::chosen_character()const
{
	Character player_;
	switch (frame_)
	{
	case 0:
		player_ = GOKU;
		break;
	case 1:
		player_ = PICCOLO;
		break;
	case 2:
		player_ = NARRUTO;
		break;
	case 3:
		player_ = LUFFY;
		break;
	}
	return player_;
}