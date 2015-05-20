#include "Fighter.h"

Fighter::Fighter()
{
	position_.x = GAME_WIDTH/2;
	position_.y = GAME_HEIGHT/2;

	state_ = STANDING;
	jumping_ = false;

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
	collisionType = entityNS::BOX;
	mass = 5;

}//comit

void Fighter::move(const Input* input, float frameTime)
{
	//Move Right;
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

		velocity.x = 100;
	}

	//Move Left
	else if (input->isKeyDown(VK_LEFT))	// If move left
	{
		//changes to walking
		state_ = WALKING;
		//makes sure is facing the right direction
		mirror_ = true;
		Image::flipHorizontal(mirror_);

		Image::setX(Image::getX() - frameTime * SPEED_);
		if (Image::getX() < -Image::getWidth()) // If offscreen left
			Image::setX((float)GAME_WIDTH); // Position offscreen right
		velocity.x = -100;
	}

	//Jump
	else if (input->isKeyDown(VK_UP) )
	{
		if (!jumping_)
		{
			jumping_ = true;
			velocity.y = -2*Image::getHeight()*frameTime;
		}
	}

	//Crouch or Fall quick
	else if (input->isKeyDown(VK_DOWN))
	{
		state_ = BLOCKING;
		if (velocity.x > 0)
		{
			velocity.x -= 10;
		}

	}
	else if (input->isKeyDown(VK_SPACE))
	{
		state_ = NEUTRAL_B;
	}
	// bottom
	else if (!input->isKeyDown(VK_LEFT) && !input->isKeyDown(VK_RIGHT) && !input->isKeyDown(VK_DOWN))
	{
		state_ = STANDING;
	}


}

void Fighter::setPosition(int x, int y)
{
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
	Image::setX(position_.x);
	Image::setY(position_.y);
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

	//Walls

	//Stop at Right edge of screen
	if (spriteData.x > GAME_WIDTH - 50)  
	{
		spriteData.x = GAME_WIDTH-50;  // position at right screen edge
		//velocity.x = -velocity.x;        // reverse X direction
	}

	//Stop at Left edge of screen
	else if (spriteData.x < 0)
	{
		spriteData.x = 0;               // position at left screen edge
		velocity.x = -velocity.x;       // reverse X direction
	}

	//Stop at Bottom edge of screen
	if (spriteData.y > GAME_HEIGHT - getHeight() - 50)
	{
		//spriteData.y = GAME_HEIGHT - 2 * getHeight()-50; // position at bottom screen edge
		jumping_ = false;
		state_ = STANDING;
		velocity.y = 0;
		spriteData.y = GAME_HEIGHT - getHeight() - 50;
	}

	//Stop Top edge of screen
	else if (spriteData.y < 0)
	{
		spriteData.y = 0;                           // position at top screen edge
		velocity.y = -0.1*velocity.y;               // reverse  and reduce Y velocity
	}

	//gravity
	if (spriteData.y < GAME_HEIGHT - getHeight()-50)
	{
		velocity.y += frameTime*GRAVITY;
		Image::setY(Image::getY() + (velocity.y));
	}

	//slowdown after running
	if (velocity.x > 0)
	{
		velocity.x--;
	}
	if (velocity.x < 0)
	{
		velocity.x++;
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
	case BLOCKING:
		blocking();
		break;
	case JUMPING:
		jumping();
		break;
	case FALLING:
		falling();
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

Sprite_Info help_set_rect(int left, int bottom_y, int height, int width)
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