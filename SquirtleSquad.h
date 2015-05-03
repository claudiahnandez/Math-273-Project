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
    TextureManager menuTexture_, backgroundTexture_; // textures
    Image   menu_;               // menu image
    Image   background_;         // background image

	//Fighter* player1_;
	Fighter* player2_;



	//stretch goals
	//Fighter* player3_;
	//Fighter* player4_;

    TextDX  *dxFont_;            // DirectX font
    std::string  message_;
    float messageY_;
};


#endif
