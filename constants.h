// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Game Engine constants.h v4.0
// Last modification: Mar-1-2015

#pragma once
#ifndef _CONSTANTS_H            // Prevent multiple definitions if this 
#define _CONSTANTS_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

//=============================================================================
//                  Constants
//=============================================================================

//=============================================================================
//Useful Macros, TRANCPERANCY COLORS FOR SPRITES
#define GOKU_TRANSCOLOR SETCOLOR_ARGB(255,0,128,0)
#define ICHIAGO_TRANSCOLOR SETCOLOR_ARGB (255,0,128,0)
#define KENSHIN_TRANSCOLOR SETCOLOR_ARGB (255,115,57,132)
#define LUFFY_TRANSCOLOR SETCOLOR_ARGB (255,0,128,128)
#define FIRE_MARIO_TRANSCOLOR SETCOLOR_ARGB (255,130,192,255)
#define NARUTO_TRANSCOLOR SETCOLOR_ARGB (255,0,128,0)
#define PICCOLO_TRANSCOLOR SETCOLOR_ARGB(255,57,115,255)
#define SANJI_TRANSCOLOR SETCOLOR_ARGB (255,82,100,148)
#define TSUNA_TRANSCOLOR SETCOLOR_ARGB (255,82,100,148)
#define YUGI_TRANSCOLOR SETCOLOR_ARGB (255,0,102,0)
#define ZORO_TRANSCOLOR SETCOLOR_ARGB (255,10,114,108)
#define TRANSCOLORR SETCOLOR_ARGB(255, 255, 0, 255)
//=============================================================================


// window
const char CLASS_NAME[] = "whatever";
const char GAME_TITLE[] = "Game Engine v4.0 Demo";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH = 516;//640;               // width of game in pixels
const UINT GAME_HEIGHT = 400;//480;               // height of game in pixels
const int SPEED_ = 250;//pixels per second
const int MARIO_SPEED = 250;//changed MARIO_SPEED
 
// game
const bool VSYNC = false;                   // true locks display to vertical sync rate
const float FRAME_RATE = 240.0f;            // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f/FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f/MIN_FRAME_RATE; // maximum time used in calculations
const double PI = 3.14159265;
const float GRAVITY = 2; // Acceleration of gravity pixels/sec

// graphic images
//const char MENU_IMAGE[] =     "pictures\\extras\\menu.png";      // menu texture
const char BACKGROUND_IMAGE[] = "pictures\\backgrounds\\KanohaStage.png";  // background
//const char TEST_IMAGE1[] = "pictures\\test1.png";
const char GOKU_SPRITE[] = "pictures\\CharacterSprites\\Goku_2.png";
const char LUFFY_TEST[] = "pictures\\CharacterSprites\\testLuffyStrip.png";
const char PICCOLO_SPRITE[] = "pictures\\CharacterSprites\\Piccolo.png";
const char NARUTO_SPRITE[] = "pictures\\CharacterSprites\\Naruto(test).png";
const char PLATFORM_IMAGE[] = "pictures\\default_platform.png";
//const char TEXTURES_IMAGE[] = "pictures\\pictures\\textures.png";  // game textures
const char BALL[] = "pictures\\CharacterSprites\\ball_test.png"; 
const char START_MENU[] = "pictures\\start_menu.png";
//const char CHARACTER_SELECTION[] = "pictures\\Character Select.png";

//background images
//const char SWAMP[] = "pictures\\Swamp_.png";
const char MAGMA[] = "pictures\\Magma.png";
const char TRAINING_STAGE[] = "pictures\\backgrounds\\TrainingStage_.png";
const char KESHIN_STAGE[] = "pictures\\backgrounds\\KenshinStage.png";
const char BUDAKAI[] = "pictures\\backgrounds\\Budakai.png";


// audio files required by audio.cpp
// WAVE_BANK must be location of .xwb file.
const char WAVE_BANK[] = "audio\\Win\\waveBank.xwb";
// SOUND_BANK must be location of .xsb file.
const char SOUND_BANK[] = "audio\\Win\\soundBank.xsb";
// XGS_FILE must be location of .xgs file.
const char XGS_FILE[] = "audio\\Win\\SpaceWar.xgs";

// audio cues
const char CHEER[] = "cheer";
const char COLLIDE[] = "collide";
const char EXPLODE[] = "explode";
const char ENGINE1[] = "engine1";
const char ENGINE2[] = "engine2";
const char TORPEDO_CRASH[] = "torpedoCrash";
const char TORPEDO_FIRE[] = "torpedoFire";
const char TORPEDO_HIT[] = "torpedoHit";
const char ACTION_THEME[] = "actionTheme";
const char BOSS_BATTLE_THEME[] = "8-Bit_Boss_Battle4-ByEliteFerrex";
const char PACIFIC_THEME[] = "pacificTheme";
//test sync

// audio cues

// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR CONSOLE_KEY  = '`';         // ` key
const UCHAR ESC_KEY      = VK_ESCAPE;   // escape key
const UCHAR ALT_KEY      = VK_MENU;     // Alt key
const UCHAR ENTER_KEY    = VK_RETURN;   // Enter key

//=============================================================================
// Function templates for safely dealing with pointer referenced items.
// The functions defined by these templates may be called using a normal
// function call syntax. The compiler will create a function that replaces T
// with the type of the calling parameter.
//=============================================================================
// Safely release pointer referenced item
template <typename T>
inline void safeRelease(T& ptr)
{
    if (ptr)
    { 
        ptr->Release(); 
        ptr = NULL;
    }
}
#define SAFE_RELEASE safeRelease            // for backward compatiblility

// Safely delete pointer referenced item
template <typename T>
inline void safeDelete(T& ptr)
{
    if (ptr)
    { 
        delete ptr; 
        ptr = NULL;
    }
}
#define SAFE_DELETE safeDelete              // for backward compatiblility

// Safely delete pointer referenced array
template <typename T>
inline void safeDeleteArray(T& ptr)
{
    if (ptr)
    { 
        delete[] ptr; 
        ptr = NULL;
    }
}
#define SAFE_DELETE_ARRAY safeDeleteArray   // for backward compatiblility

// Safely call onLostDevice
template <typename T>
inline void safeOnLostDevice(T& ptr)
{
    if (ptr)
        ptr->onLostDevice(); 
}
#define SAFE_ON_LOST_DEVICE safeOnLostDevice    // for backward compatiblility

// Safely call onResetDevice
template <typename T>
inline void safeOnResetDevice(T& ptr)
{
    if (ptr)
        ptr->onResetDevice(); 
}
#define SAFE_ON_RESET_DEVICE safeOnResetDevice  // for backward compatiblility



/////enums
enum Character
{
	GOKU,
	PICCOLO,
	NARRUTO,
	LUFFY
};

//this does not compensate for all the moves
struct Position
{
	int x;
	int y;
};

struct Sprite_Info
{
	RECT rect;
	int height;
	int width;
};

enum  Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

enum Fighter_State
{
	STANDING,
	WALKING,
	RUNNING,
	JUMPING,
	FALLING,
	BLOCKING,
	NEUTRAL_A,
	NEUTRAL_B,
	SIDE_B,
	UP_B,
	DOWN_B,
	STANDARD,
	HIT,
	KNOCKED_OUT
};

// weapon types
enum WEAPON { ENERGY_ATTACK, PUNCH, BAT, TORPEDO,  SHIP, PLANET };
#endif