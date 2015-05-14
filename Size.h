#pragma once

class Size
{
public:
	Size();
	Size(int w, int h);
	int width() const;
	int height() const;
private:
	int width_;
	int height_;
};