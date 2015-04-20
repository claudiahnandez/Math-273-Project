#include "Fighter.h"

Fighter::Fighter()
{
	position_.x = GAME_WIDTH/2;
	position_.y = GAME_HEIGHT / 2;
	state_ = STANDING;
	HP_ = 100;
}

void Fighter::move(Direction direction)
{
	switch (direction)
	{
	case LEFT:
		break;
	case UP:
		break;
	case RIGHT:
		break;
	case DOWN:
		break;
	}
}