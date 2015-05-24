#include "Magma.h"


Magma::Magma()
{
	spriteData.width = 800;
	spriteData.height = 336;
	background_location_ = MAGMA;
	spriteData.scale = 1;
	endFrame = 7;
	floor_ = 310;
	frameDelay = 0.22;
}

void Magma::set_image()
{
	Sprite_Info magma[8];
	magma[0] = help_set_rect(0, 336, 336, 800);
	magma[1] = help_set_rect(0, 672, 336, 800);
	magma[2] = help_set_rect(0, 1008, 336, 800);
	magma[3] = help_set_rect(0, 1344, 336, 800);
	magma[4] = help_set_rect(0, 1680, 336, 800);
	magma[5] = help_set_rect(0, 2016, 336, 800);
	magma[6] = help_set_rect(0, 2352, 336, 800);
	magma[7] = help_set_rect(0, 2688, 336, 800);

	set_animation(magma);
}
