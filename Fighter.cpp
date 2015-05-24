#include "Fighter.h"

Fighter::Fighter()
{
	state_ = STANDING;
	startFrame = 0;
	jumping_ = false;

	spriteData.scale = 1;
	sprite_location_ = "";
	transcolor_ = TRANSCOLORR;
	direction_ = RIGHT;
	mirror_ = false;
	floor_ = GAME_HEIGHT;

	velocity.x = 0;                 // velocity X
	velocity.y = 0;                 // velocity Y
	frameDelay = 1;
	//startFrame = 0;                             // first frame of animation
	//endFrame = 0;                           // last frame of animation
	//currentFrame = startFrame;
	//radius = 50;
	collisionType = entityNS::BOX;
	mass = 5;

}//comit

void Fighter::move(const Input* input, float frameTime)
{
	//Move Right;
	if (input->isKeyDown(VK_RIGHT))	// If move right
	{
		//makes sure its facing the right direction
		mirror_ = false;
		Image::flipHorizontal(mirror_);

		//if not jumping
		if (!jumping_)
		{
			//change to walking state
			state_ = WALKING;
		}

		//increase velocity
		if (velocity.x < max_speed_)
		{
			//acceleration_+=100*frameTime;
			//deltaV.x = acceleration_;
			deltaV.x = 600;
		}

	}

	//Move Left
	else if (input->isKeyDown(VK_LEFT))	// If move left
	{
		//makes sure its facing the right direction
		mirror_ = true;
		Image::flipHorizontal(mirror_);

		//if not jumping
		if (!jumping_)
		{
			//change to walking state
			state_ = WALKING;
		}

		//increase velocity
		if (abs(velocity.x) < max_speed_)
		{
			//deltaV.x = -acceleration_;
			deltaV.x = -600;
		}
	}

	//Jump
	else if (input->isKeyDown(VK_UP) )
	{
		if (!jumping_)
		{
			jumping_ = true;
			state_ = JUMPING;
			//velocity.y = -2*Image::getHeight();
			velocity.y = -30;
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
		acceleration_ = 0;
		int deceleration = 4;

		if (velocity.x<500 && velocity.x >-500)
		{
			state_ = STANDING;
		}

		//slowdown
		if (velocity.x >= 10)
		{
			velocity.x -= deceleration;
		}
		else if (velocity.x <= -10)
		{
			velocity.x += deceleration;
		}
		else if (velocity.x<10 && velocity.x >-10)
		{
			velocity.x = 0;
		}

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
	Entity::update(frameTime);

	Entity::move(frameTime);

	//Walls

	//Stop at Right edge of screen
	if (spriteData.x > GAME_WIDTH - spriteData.width)  
	{
		spriteData.x = GAME_WIDTH - spriteData.width; // position at right screen edge
		velocity.x = 0;
	}

	//Stop at Left edge of screen
	else if (spriteData.x < 0)			
	{
		spriteData.x = 0;               // position at left screen edge
		velocity.x = 0;
	}

	//Stop at Bottom edge of screen
	if (spriteData.y > GAME_HEIGHT - getHeight() - 100)
	{
		jumping_ = false;
		velocity.y = 0;
	}

	//Stop Top edge of screen
	else if (spriteData.y < 0)                    
	{
		spriteData.y = 0;                           // position at top screen edge
	}

	//gravity
	if (spriteData.y < GAME_HEIGHT - getHeight()-100)
	{
		velocity.y += GRAVITY;
		Image::setY(Image::getY() + (velocity.y));
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

void Fighter::unstandardSprite(int max_frame, RECT animation[])
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

RECT help_set_rect(int left, int bottom_y, int height, int width)
{
	RECT sprite;
	sprite.top = bottom_y - height;
	sprite.left = left;
	sprite.bottom = bottom_y;
	sprite.right = left + width;

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

