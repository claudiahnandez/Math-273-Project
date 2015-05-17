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
		Image::flipHorizontal(mirror_);

		Image::setX(Image::getX() + frameTime * SPEED_);
		if (Image::getX() > GAME_WIDTH) // If offscreen right
			Image::setX((float)-Image::getWidth()); // Position offscreen left
		//state_ = 
	}
	if (input->isKeyDown(VK_LEFT))	// If move left
	{
		//changes to walking
		state_ = NEUTRAL_B;
		//makes sure is facing the right direction
		mirror_ = true;
		Image::flipHorizontal(mirror_);

		Image::setX(Image::getX() - frameTime * SPEED_);
		if (Image::getX() < -Image::getWidth()) // If offscreen left
			Image::setX((float)GAME_WIDTH); // Position offscreen right
	}
	if (input->isKeyDown(VK_UP))	// If move up
	{
		state_ = JUMPING;
		Image::setY(Image::getY() - frameTime * SPEED_);
		if (Image::getY() < -Image::getHeight()) // If offscreen top
			Image::setY((float)GAME_HEIGHT); // Position offscreen
	}
	if (input->isKeyDown(VK_DOWN))
	{
		state_ = CROUCHING;
	}
	// bottom
	if (!input->isKeyDown(VK_LEFT) && !input->isKeyDown(VK_RIGHT) && !input->isKeyDown(VK_DOWN))
	{
		state_ = STANDING;
	}


}

void Fighter::setPosition(int x, int y)
{
	//Change so it  modifies the "internal" texture not the additional "image_"
	Image::setX(x);
	Image::setY(y);
}

void Fighter::initialize(HWND hwnd, Graphics*& graphics)
{
	setPose();

	//TEXTURE

	//texture=save the image
	//Testing a back ground and transperancy
	

	//will initialize the texture og the fighter
	if (!texture_.initialize(graphics, sprite_location_, transcolor_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Fighter texture"));

	//IMAGE
	// test image 2 (mario)
	//width and height are marios height
	if (!Image::initialize(graphics, width_, height_, images_per_column_, &texture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));


	setPose();
	
	Image::setScale(scale_);
	Image::setFrames(min_frame_, max_frame_);
	Image::setX(200);
	Image::setY(400);
	//marioWalkRunImage_.setCurrentFrame(0);
	Image::setFrameDelay(0.2);


	return;
}


void Fighter::draw(Graphics*& graphics)
{
	setPose();
	Image::draw();
}

void Fighter::update(float frameTime)
{
	//will need to be changed due to position
	Image::update(frameTime);

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
		//if (velocity.y < 1)            // if ball has small bounce
		//{
		//	spriteData.y = GAME_HEIGHT / 4;
		//	velocity.x = 10;
		//}
		velocity.y = -velocity.y;                   // reverse Y direction
	}
	else if (spriteData.y < 0)                    // else if hit top screen edge
	{
		spriteData.y = 0;                           // position at top screen edge
		velocity.y = -velocity.y;                   // reverse Y direction
	}

	velocity.y += frameTime * GRAVITY;              // gravity
	if (image_.getY() < GAME_HEIGHT-150)
	{
		image_.setY(image_.getY() + frameTime *GRAVITY);
	}
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
	case NEUTRAL_A:
		neutralA();
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
	Image::flipHorizontal(state);
}

void Fighter::setStandardSprite(int max_frame, int height, int width, int width_gap, int height_gap)
{
	animation_.clear();
	max_frame_ = max_frame;

	Image::setWidth(width);
	Image::setHeight(height);

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

	Image::setVector(animation_);
}

void Fighter::settingStandardSprite(int max_frame, int height, int width, int gap, int x, int y)
{
	animation_.clear();
	max_frame_ = max_frame;

	Image::setWidth(width);
	Image::setHeight(height);

	RECT temp;
	temp.top = y;
	temp.left = x;
	temp.bottom = temp.top + height;
	temp.right = temp.left + width;
	animation_.push_back(temp);

	for (int i = 1; i < max_frame; i++)
	{
		animation_.push_back(temp);
		animation_[i].top = animation_[0].top;
		animation_[i].left = animation_[i - 1].right + gap;
		animation_[i].bottom = animation_[0].bottom;
		animation_[i].right = animation_[i].left + width;
	}


	Image::setVector(animation_);
}

void Fighter::unstandardSprite(int max_frame, Sprite_Info animation[])
{
	animation_.clear();
	max_frame_ = max_frame;
	Image::setFrames(min_frame_, max_frame_);

	//will eventually be changed for collision purposes
	height_ = animation[0].height;
	width_ = animation[0].width;


	//will set the rects
	for (int i = 0; i <= max_frame; i++)
	{
		animation_.push_back(animation[i].rect);

	}

	Image::setVector(animation_);



}

Sprite_Info Fighter::help_set_rect(int left, int bottom_y, int height, int width)
{
	Sprite_Info sprite;
	sprite.rect.top = bottom_y - height;
	sprite.rect.left = left;
	sprite.rect.bottom = bottom_y;
	sprite.rect.right = left + width;
	sprite.width = width;
	sprite.height = height;

	return sprite;
}