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
int Size::width() const
{
	return width_;
}
int Size::height() const
{
	return height_;
}