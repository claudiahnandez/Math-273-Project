#pragma once
#include "Fighter.h"

class Size
{
public:
	Size();
	Size(int w, int h);
	Size(Fighter_State state, Character ch);
	int width() const;
	int height() const;
private:
	int width_;
	int height_;
};

class Frame
{
public:
	Frame();
	Frame(int s, int e);
	Frame(Fighter_State state, Character ch);
	int start() const;
	int end() const;
private:
	int start_;
	int end_;
};