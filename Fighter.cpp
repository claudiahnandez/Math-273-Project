#include "Fighter.h"

Fighter::Fighter()
{
	position_.x = GAME_WIDTH / 3;
	position_.y = GAME_HEIGHT - 50;

	state_ = STANDING;

	max_frame_ = 0;
	min_frame_ = 3;
	width_ = 0;
	height_ = 0;
	scale_ = 3;
	images_per_column_ = 0;
	sprite_location_ = "";
	transcolor_ = TRANSCOLORR;
	direction_ = RIGHT;
	mirror_ = false;

	velocity.x = 10;                 // velocity X
	velocity.y = 10;                 // velocity Y
	frameDelay = 1;
	startFrame = 0;                             // first frame of animation
	endFrame = 0;                           // last frame of animation
	currentFrame = startFrame;
	radius = 50;
	collisionType = entityNS::CIRCLE;
	mass = 5;

}//comit


void Fighter::move(const Input* input, float frameTime)
{
	if (input->isKeyDown(VK_RIGHT))	// If move right
	{
		//changes to walking state
		state_ = WALKING;

		//makes sure is facing the right direction
		mirror_ = false;
		image_.flipHorizontal(mirror_);

		image_.setX(image_.getX() + frameTime * SPEED_);
		if (image_.getX() > GAME_WIDTH) // If offscreen right
			image_.setX((float)-image_.getWidth()); // Position offscreen left
		//state_ = 
	}
	if (input->isKeyDown(VK_LEFT))	// If move left
	{
		//changes to walking
		state_ = WALKING;
		//makes sure is facing the right direction
		mirror_ = true;
		image_.flipHorizontal(mirror_);

		image_.setX(image_.getX() - frameTime * SPEED_);
		if (image_.getX() < -image_.getWidth()) // If offscreen left
			image_.setX((float)GAME_WIDTH); // Position offscreen right
	}
	if (input->isKeyDown(VK_UP))	// If move up
	{
		image_.setY(image_.getY() - frameTime * SPEED_);
		if (image_.getY() < -image_.getHeight()) // If offscreen top
			image_.setY((float)GAME_HEIGHT); // Position offscreen
	}
		// bottom
	if (!input->isKeyDown(VK_LEFT )&& !input->isKeyDown(VK_RIGHT))
	{
		state_ = STANDING;
	}
	

}


void Fighter::initialize(HWND hwnd, Graphics*& graphics)
{
	setPose();

	//TEXTURE

	//texture=save the image
	//Testing a back ground and transperancy
	if (!background_.initialize(graphics, BACKGROUND_IMAGE,TRANSCOLORR))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));

	//will initialize the texture og the fighter
	if (!texture_.initialize(graphics, sprite_location_, transcolor_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Fighter texture"));

	//IMAGE
	// background image
	if (!background_draw_.initialize(graphics, 0,0, 0, &background_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background"));

	// test image 2 (mario)
	//width and height are marios height
	if (!image_.initialize(graphics, width_, height_, images_per_column_, &texture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));

	
	setPose();
	background_draw_.setScale(3);
	image_.setScale(scale_);
	image_.setFrames(min_frame_, max_frame_);
	image_.setX(200);
	image_.setY(400);
	//marioWalkRunImage_.setCurrentFrame(0);
	image_.setFrameDelay(0.2);
	

	return;
}


void Fighter::draw(Graphics*& graphics)
{
	setPose();
	//background_draw_.draw();
	image_.draw();
}

void Fighter::update(float frameTime)
{
	//will need to be changed due to position
	image_.update(frameTime);

	//Gravity
	//velocity.y = frameTime * GRAVITY;

	//image_.setX(image_.getX() + frameTime * MARIO_SPEED); // Move mario right
	//if (image_.getX() > GAME_WIDTH) // If offscreen right
	//{
	//	image_.setX((float)-image_.getWidth());// Position off screen left
	//}
	//	image_.setY(image_.getY() + frameTime * SPEED_);
	//	if (image_.getY() > GAME_HEIGHT) // If offscreen bottom
	//		image_.setY((float)-image_.getHeight());// Position offscreen top
	//

	Entity::update(frameTime);
	spriteData.x += frameTime * velocity.x;         // move along X 
	spriteData.y += frameTime * velocity.y;         // move along Y

	// Bounce off walls
	if (spriteData.x > GAME_WIDTH - 50)  // if hit right screen edge
	{
		spriteData.x = GAME_WIDTH - 50;  // position at right screen edge
		velocity.x = -velocity.x;                   // reverse X direction
	}
	else if (spriteData.x < 0)                    // else if hit left screen edge
	{
		spriteData.x = 0;                           // position at left screen edge
		velocity.x = -velocity.x;                   // reverse X direction
	}
	if (spriteData.y > GAME_HEIGHT - 50) // if hit bottom screen edge
	{
		spriteData.y = GAME_HEIGHT - 50; // position at bottom screen edge
		velocity.y -= 100;
		if (velocity.y < 1)            // if ball has small bounce
		{
			spriteData.y = GAME_HEIGHT / 4;
			velocity.x = 10;
		}
		velocity.y = -velocity.y;                   // reverse Y direction
	}
	else if (spriteData.y < 0)                    // else if hit top screen edge
	{
		spriteData.y = 0;                           // position at top screen edge
		velocity.y = -velocity.y;                   // reverse Y direction
	}

	velocity.y += frameTime * GRAVITY;              // gravity
}

void Fighter::setPose()
	{
	switch (state_)
	{
	case STANDING:
		standing();
		break;
	case WALKING:
		walking();
		break;
	case RUNNING:
		running();
		break;
	case JUMPING:
		jumping();
		break;
	case FALLING:
		falling();
		break;
	case CROUCHING:
		crouching();
		break;
	case NEUTRAL_B:
		neutralB();
		break;
	case SIDE_B:
		sideB();
		break;
	case UP_B:
		upB();
		break;
	case DOWN_B:
		downB();
		break;
	case STANDARD:
		standardAttack();
		break;
	}
}

void Fighter::mirror(bool state)
{
	image_.flipHorizontal(state);
}

void Fighter::setStandardSprite(int max_frame, int height, int width, int width_gap, int height_gap)
{
	animation_.clear();
	max_frame_ = max_frame;

	image_.setWidth(width);
	image_.setHeight(height);

	RECT temp;

	temp.left = width_gap - 1;
	temp.top = height_gap;
	temp.right = temp.left + width;
	temp.bottom = temp.top + height;
	animation_.push_back(temp);

	//the rest of the frames are drawn based on the width
	for (int i = 1; i <= max_frame; i++)
	{
		RECT temp;
		animation_.push_back(temp);
		animation_[i].left = animation_[i - 1].right + width_gap;
		animation_[i].top = animation_[i - 1].top;
		animation_[i].right = animation_[i].left + width;
		animation_[i].bottom = animation_[i - 1].bottom;
		if (i == 1)
		{
			animation_[i].left += 1;
			animation_[i].right += 1;
		}
		if (i == 2)
		{
			animation_[i].left -= 1;
			animation_[i].right -= 1;
		}
	}

	image_.setVector(animation_);
}

void Fighter::setPosition(int x, int y)
{
	image_.setX(x);
	image_.setY(y);
}
