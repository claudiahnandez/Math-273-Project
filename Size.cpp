#include "Size.h"

Size::Size()
{
	width_ = 0;
	height_ = 0;
}
Size::Size(int w, int h)
{
	width_ = w;
	height_ = h;
}
Size::Size(Fighter_State state, Character ch)
{
	switch (ch)
	{
	case GOKU:
		switch (state)
		{
		case STANDING:
			break;
		case WALKING:
			break;
		case RUNNING:
			break;
		case JUMPING:
			break;
		case FALLING:
			break;
		case NEUTRAL_A:
			break;
		case NEUTRAL_B:
			break;
		case SIDE_B:
			break;
		case UP_B:
			break;
		case DOWN_B:
			break;
		case STANDARD:
			break;
		}
		break;
	case LUFFY:
		switch (state)
		{
		case STANDING:
			width_ = 27;
			height_ = 54;
			break;
		case WALKING:
			width_ = 49;
			height_ = 47;
			break;
		case RUNNING:
			break;
		case JUMPING:
			break;
		case FALLING:
			break;
		case BLOCKING:
			width_ = 39;
			height_ = 42;
			break;
		case NEUTRAL_A:
			break;
		case NEUTRAL_B:
			break;
		case SIDE_B:
			break;
		case UP_B:
			break;
		case DOWN_B:
			break;
		case STANDARD:
			break;
		}
		break;
	case MARIO:
		switch (state)
		{
		case STANDING:
			break;
		case WALKING:
			break;
		case RUNNING:
			break;
		case JUMPING:
			break;
		case FALLING:
			break;
		case NEUTRAL_A:
			break;
		case NEUTRAL_B:
			break;
		case SIDE_B:
			break;
		case UP_B:
			break;
		case DOWN_B:
			break;
		case STANDARD:
			break;
		}
		break;
	case PICCOLO:
		switch (state)
		{
		case STANDING:
			break;
		case WALKING:
			break;
		case RUNNING:
			break;
		case JUMPING:
			break;
		case FALLING:
			break;
		case NEUTRAL_A:
			break;
		case NEUTRAL_B:
			break;
		case SIDE_B:
			break;
		case UP_B:
			break;
		case DOWN_B:
			break;
		case STANDARD:
			break;
		}
		break;
	}
}
int Size::width() const
{
	return width_;
}
int Size::height() const
{
	return height_;
}

Frame::Frame()
{
	start_ = 0; 
	end_ = 0;
	width_Start_ = 0;
	height_Start_ = 0;
}
Frame::Frame(int s, int e)
{
	start_ = s;
	end_ = e;
	width_Start_ = 0;
	height_Start_ = 0;
}
Frame::Frame(Fighter_State state, Character ch)
{
	switch (ch)
	{
	
	case GOKU:
		switch (state)
		{
		case STANDING:
			break;
		case WALKING:
			break;
		case RUNNING:
			break;
		case JUMPING:
			break;
		case FALLING:
			break;
		case NEUTRAL_A:
			break;
		case NEUTRAL_B:
			break;
		case SIDE_B:
			break;
		case UP_B:
			break;
		case DOWN_B:
			break;
		case STANDARD:
			break;
		}
		break;
	case LUFFY:
		switch (state)
		{
		case STANDING:
			start_ = 0;
			end_ = 3;
			width_Start_ = 0;
			height_Start_ = 0;
			break;
		case WALKING:
			start_ = 7;
			end_ = 14;
			width_Start_ = 232;
			height_Start_ = 7;
			break;
		case RUNNING:
			break;
		case JUMPING:
			break;
		case FALLING:
			break;
		case BLOCKING:
			start_ = 4;
			end_ = 6;
			width_Start_ = 112;
			height_Start_ = 12;
			break;
		case NEUTRAL_A:
			break;
		case NEUTRAL_B:
			break;
		case SIDE_B:
			break;
		case UP_B:
			break;
		case DOWN_B:
			break;
		case STANDARD:
			break;
		}
		break;
	case MARIO:
		switch (state)
		{
		case STANDING:
			break;
		case WALKING:
			break;
		case RUNNING:
			break;
		case JUMPING:
			break;
		case FALLING:
			break;
		case NEUTRAL_A:
			break;
		case NEUTRAL_B:
			break;
		case SIDE_B:
			break;
		case UP_B:
			break;
		case DOWN_B:
			break;
		case STANDARD:
			break;
		}
		break;
	case PICCOLO:
		switch (state)
		{
		case STANDING:
			break;
		case WALKING:
			break;
		case RUNNING:
			break;
		case JUMPING:
			break;
		case FALLING:
			break;
		case NEUTRAL_A:
			break;
		case NEUTRAL_B:
			break;
		case SIDE_B:
			break;
		case UP_B:
			break;
		case DOWN_B:
			break;
		case STANDARD:
			break;
		}
		break;
	}
}
int Frame::start() const
{
	return start_;
}
int Frame::end() const
{
	return end_;
}
int Frame::getLeft() const
{
	return width_Start_;
}
int Frame::getTop() const
{
	return height_Start_;
}