// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// createThisClass.h

#ifndef _CREATETHIS_H           // Prevent multiple definitions if this 
#define _CREATETHIS_H           // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <string>
#include <sstream>
#include "game.h"
#include "textureManager.h"
#include "image.h"
#include "textDX.h"
#include "Fighter.h"
#include "Mario.h"
#include "Goku.h"
#include "Piccolo.h"
#include "Luffy.h"
#include "Platform.h"
#include "Background.h"
#include "Swamp.h"
#include "Magma.h"
#include "Energy_Attack.h"
#include "Naruto.h"
#include "Training_Stage.h"
#include "Kenshin_Stage.h"
#include "Budakai.h"
#include "Character_Menu.h"


const char FONT[] = "Arial Bold";  // font
const COLOR_ARGB FONT_COLOR = graphicsNS::YELLOW;

//=============================================================================
// This class is the core of the game
//=============================================================================
class SquirtleSquad : public Game
{
public:
    // Constructor
	SquirtleSquad();
    // Destructor
	virtual ~SquirtleSquad();
    // Initialize the game
    void initialize(HWND hwnd);
    void update();      // must override pure virtual from Game
    void ai();          // "
    void collisions();  // "
    void render();      // "
    void releaseAll();
    void resetAll();

private:
    // game items
	TextureManager s_menuTexture_, backgroundTexture_, gameTextures; // textures
	Image s_menuImage;
    Image   menu_;               // menu image
	bool    musicOff;           // true to turn music off
	bool menuOn=false;
	bool char_select = true;
	bool play1_selected = true;
	bool play2_selected = true;

    //Image   background_;         // background image

	Fighter* player1_;
	Fighter* player2_;
	Fighter* player3_;
	Fighter* player4_;

	Platform hitbox1_;
	Platform hitbox2_;
	Platform hitbox3_;
	Platform hitbox4_;

	Background* stage_;
	Character_Menu play1_select;
	Character_Menu play2_select;

	Character player1=GOKU;
	Character player2=PICCOLO;

	TextureManager platformTexture_;   //platform texture
	Platform platform1_;
	Platform platform2_;
	Platform platform3_;
	Platform platform4_;
	Platform platform5_;

	Enery_Attack Energy_Attack_1_;
	Enery_Attack Energy_Attack_2_;
	Enery_Attack Energy_Attack_3_;
	Enery_Attack Energy_Attack_4_;

	//Bar     healthBar;          // health bar for ships
	//Bar     healthBar;          // health bar for ships


    TextDX  *dxFont_;            // DirectX font
    std::string  message_;
    float messageY_;
};
#endif