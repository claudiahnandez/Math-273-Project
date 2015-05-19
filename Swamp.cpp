#include "Swamp.h"


Swamp::Swamp()
{
	width_ = 800;
	height_ = 336;
	background_location_ = SWAMP;
	scale_ = 1;
	max_frames = 6;
	Image::setFrames(0, 6);
	

}

void Swamp::set_image()
{
	Sprite_Info swamp[7];
	swamp[0] = help_set_rect(0, 336, 336, 800);
	swamp[1] = help_set_rect(0, 672, 336, 800);
	swamp[2] = help_set_rect(0, 1008, 336, 800);
	swamp[3] = help_set_rect(0, 1344, 336, 800);
	swamp[4] = help_set_rect(0, 1680, 336, 800);
	swamp[5] = help_set_rect(0, 2016, 336, 800);
	swamp[6] = help_set_rect(0, 2352, 336, 800);

	set_animation(swamp);

}
