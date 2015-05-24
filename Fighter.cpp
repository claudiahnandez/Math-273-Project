#include "Fighter.h"

Fighter::Fighter()
{
	state_ = STANDING;
	startFrame = 0;

	spriteData.scale = 1;
	sprite_location_ = "";
	transcolor_ = TRANSCOLORR;
	direction_ = RIGHT;
	mirror_ = false;
	floor_ = GAME_HEIGHT;

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
	else if (input->isKeyDown(VK_UP) )	// If move up
	{
		if (state_ == STANDING)
		{
			//Image::setY(Image::getY() + velocity.y);

			state_ = JUMPING;
			//Image::setY(Image::getY() - frameTime * SPEED_);
			//if (Image::getY() < -Image::getHeight()) // If offscreen top
			//Image::setY(Image::getY()-100); // Position offscreen
			velocity.y = -15;
		}
	}
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

void Fighter::initialize(HWND hwnd, Graphics*& graphics, int floor)
{
	setPose();
	
	floor_ = floor;
	stick_to_floor();

	//will initialize the texture og the fighter
	if (!texture_.initialize(graphics, sprite_location_, transcolor_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Fighter texture"));

	//IMAGE
	// test image 2 (mario)
	//width and height are marios height
	if (!Image::initialize(graphics, spriteData.width, spriteData.height, 0, &texture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));

	
	spriteData.x = GAME_WIDTH / 2;
	frameDelay=0.2;

	return;
}

void Fighter::draw(Graphics*& graphics)
{
	setPose();
	stick_to_floor();
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

	// if hit right screen edge
	if (spriteData.x > GAME_WIDTH - 50)  
	{
		spriteData.x = GAME_WIDTH-50;  // position at right screen edge
		//velocity.x = -velocity.x;        // reverse X direction
	}
	// else if hit left screen edge
	else if (spriteData.x < 0)			
	{
		spriteData.x = 0;               // position at left screen edge
		velocity.x = -velocity.x;       // reverse X direction
	}
	// if hit bottom screen edge
	if (spriteData.y > GAME_HEIGHT - getHeight()-50) 
	{
		//spriteData.y = GAME_HEIGHT - 2 * getHeight()-50; // position at bottom screen edge
		state_ = STANDING;
		velocity.y = 0;
		spriteData.y = GAME_HEIGHT - getHeight() - 50;

		//if (velocity.y < 1)            // if ball has small bounce
		//{
		//	spriteData.y = GAME_HEIGHT / 4;
		//	velocity.x = 10;
		//}
	}
	// else if hit top screen edge
	else if (spriteData.y < 0)                    
	{
		spriteData.y = 0;                           // position at top screen edge
		velocity.y = -0.1*velocity.y;               // reverse  and reduce Y velocity
	}

	//gravity
	if (spriteData.y < GAME_HEIGHT - getHeight()-50)
	{
		velocity.y += 1;
		Image::setY(Image::getY() + velocity.y);
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

void Fighter::unstandardSprite(int max_frame, Sprite_Info animation[])
{
	animation_.clear();
	endFrame = max_frame;
	startFrame = 0;

	//will set the rects
	for (int i = 0; i <= max_frame; i++)
	{
		animation_.push_back(animation[i]);
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

void Fighter::stick_to_floor()
{
	//if the fighter is not jumping then it has to stick to the floor
	if (state_ != JUMPING)
	{
		spriteData.y = floor_ - (spriteData.height*spriteData.scale);
	}
}

