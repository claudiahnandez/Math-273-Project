#include "Swamp.h"


Swamp::Swamp()
{
	spriteData.width = 800;
	spriteData.height = 336;
	background_location_ = SWAMP;
	spriteData.scale = 1;
	endFrame = 6;
}

void Swamp::set_image()
{
	RECT swamp[7];
	swamp[0] = help_set_rect(0, 336, 336, 800);
	swamp[1] = help_set_rect(0, 672, 336, 800);
	swamp[2] = help_set_rect(0, 1008, 336, 800);
	swamp[3] = help_set_rect(0, 1344, 336, 800);
	swamp[4] = help_set_rect(0, 1680, 336, 800);
	swamp[5] = help_set_rect(0, 2016, 336, 800);
	swamp[6] = help_set_rect(0, 2352, 336, 800);

	set_animation(swamp);

}
