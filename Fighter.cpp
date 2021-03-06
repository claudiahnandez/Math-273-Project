#include "Fighter.h"

Fighter::Fighter()
{
	state_ = STANDING;
	startFrame = 0;
	jumping_ = false;
	mirror_ = false;

	spriteData.scale = 1;
	spriteData.x = GAME_WIDTH / 2;
	sprite_location_ = "";
	transcolor_ = GOKU_TRANSCOLOR;
	direction_ = RIGHT;
	floor_ = GAME_HEIGHT;
	old_width_ = 0;

	velocity.x = 0;                 // velocity X
	velocity.y = 0;                 // velocity Y
	frameDelay = 1;
	//startFrame = 0;                             // first frame of animation
	//endFrame = 0;                           // last frame of animation
	//currentFrame = startFrame;
	//radius = 50;
	mass = 5;
	
	collisionType = entityNS::BOX;
	radius = 20;
	edge.left = -25;
	edge.top = -50;
	edge.right = 25;
	edge.bottom = 50;
	active = true;

}

void Fighter::move(const Input* input, float frameTime, const int controller)
{
	//Move Right;
	if (input->isKeyDown(VK_RIGHT) ^ const_cast<Input*>(input)->getGamepadDPadRight(controller))	// If move right
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
			deltaV.x = 50;
		}

	}

	//Move Left
	else if (input->isKeyDown(VK_LEFT) ^ const_cast<Input*>(input)->getGamepadDPadLeft(controller))	// If move left
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
			deltaV.x = -50;
		}
	}

	//Jump
	else if (input->isKeyDown(VK_UP) ^ const_cast<Input*>(input)->getGamepadDPadUp(controller))
	{
		if (!jumping_)
		{
			jumping_ = true;
			state_ = JUMPING;
			//velocity.y = -2*Image::getHeight();
			velocity.y = -10;
		}
	}

	//Crouch or Fall quick
	else if (input->isKeyDown(VK_DOWN) ^ const_cast<Input*>(input)->getGamepadDPadDown(controller))
	{
		state_ = BLOCKING;
		if (velocity.x > 0)
		{
			velocity.x -= 10;
		}
	}
	
	//Attack
	else if (input->isKeyDown(VK_SPACE) ^ const_cast<Input*>(input)->getGamepadA(controller))
	{
		state_ = STANDARD;
	}
	else if (const_cast<Input*>(input)->getGamepadB(controller))
	{
		state_ = NEUTRAL_B;
	}
	else if (const_cast<Input*>(input)->getGamepadY(controller))
	{
		state_ = NEUTRAL_A;
	} 

	// bottom
	else if (!input->isKeyDown(VK_LEFT) && !input->isKeyDown(VK_RIGHT) && !input->isKeyDown(VK_DOWN))
	{
		acceleration_ = 0;
		int deceleration = 5;

		if (velocity.x<500 && velocity.x >-500)
		{
			state_ = STANDING;
		}

		//Gradual Slowdown
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

		//if standing looping is true
		loop = true;
		}
		//Instant Stop
		//velocity.x = 0;

	}


}

//move function Version 2
void Fighter::move(const Input* input, float frameTime, const int controller, Platform &hitbox)
{
	//Move Right;
	if (input->isKeyDown(VK_RIGHT) ^ const_cast<Input*>(input)->getGamepadDPadRight(controller))	// If move right
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
			deltaV.x = 50;
		}

	}

	//Move Left
	else if (input->isKeyDown(VK_LEFT) ^ const_cast<Input*>(input)->getGamepadDPadLeft(controller))	// If move left
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
			deltaV.x = -50;
		}
	}

	//Jump
	else if (input->isKeyDown(VK_UP) ^ const_cast<Input*>(input)->getGamepadDPadUp(controller))
	{
		if (!jumping_)
		{
			jumping_ = true;
			state_ = JUMPING;
			//velocity.y = -2*Image::getHeight();
			velocity.y = -10;
		}
	}

	//Crouch or Fall quick
	else if (input->isKeyDown(VK_DOWN) ^ const_cast<Input*>(input)->getGamepadDPadDown(controller))
	{
		state_ = BLOCKING;
		if (velocity.x > 0)
		{
			velocity.x -= 10;
		}
	}

	//Attack
	else if (input->isKeyDown(VK_SPACE) ^ const_cast<Input*>(input)->getGamepadA(controller))
	{

		state_ = STANDARD;
		hitbox.activate();
		hitbox.makeVisible();
	}

	// bottom
	else if (!input->isKeyDown(VK_LEFT) && !input->isKeyDown(VK_RIGHT) && !input->isKeyDown(VK_DOWN))
	{
		acceleration_ = 0;
		int deceleration = 5;

		if (velocity.x<500 && velocity.x >-500)
		{
			state_ = STANDING;
		}

		//Gradual Slowdown
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

			//if standing looping is true
			loop = true;
		}
		//Instant Stop
		//velocity.x = 0;

	}

	//Disable hitbox
	if (state_ != STANDARD)
	{
		//hitbox.deactivate();
		//hitbox.makeInvisible();
	}

}

void Fighter::initialize(HWND hwnd, Graphics*& graphics, int floor)
{
	setPose();

	floor_ = floor;
	//stick_to_floor();

	//will initialize the texture og the fighter
	if (!texture_.initialize(graphics, sprite_location_, transcolor_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Fighter texture"));

	//IMAGE
	// test image 2 (mario)
	//width and height are marios height
	if (!Image::initialize(graphics, spriteData.width, spriteData.height, 0, &texture_))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing menu"));

	frameDelay=0.2;

	return;
}

void Fighter::draw(Graphics*& graphics)
{
	
	// fixes the looping of images
	if (currentFrame == endFrame && !(state_ == STANDING || state_ == WALKING || state_ == FALLING) && loop == true)
	{
		loop = false;
		//currentFrame = 0;
		state_ = STANDING;
	}

	setPose();


	if (mirror_ == true && flipped == false && !(state_ == STANDING || state_ == WALKING))
	{
 		spriteData.x -= spriteData.width;
		flipped = true;
	}
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
	if (spriteData.y >= GAME_HEIGHT - (spriteData.height*spriteData.scale) - floor_)
	{
		jumping_ = false;
		velocity.y = 0;
		//Image::setY(GAME_HEIGHT - getHeight() - floor_);
		spriteData.y = GAME_HEIGHT - (spriteData.height*spriteData.scale) - floor_;

	}

	//Stop Top edge of screen
	else if (spriteData.y < 0)                    
	{
		spriteData.y = 0;
	}

	//gravity
	if (spriteData.y < GAME_HEIGHT - (spriteData.height*spriteData.scale) - floor_)
	{
		velocity.y += .4;
		Image::setY(Image::getY() + (velocity.y));
	}

}

void Fighter::setPose()
{
	old_width_ = spriteData.width;
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
		//spriteData.y = floor_ - (spriteData.height*spriteData.scale);
		spriteData.y = GAME_HEIGHT - (spriteData.height*spriteData.scale)-floor_;
	}
}

void Fighter::damage(WEAPON weapon)
{
	if (shieldOn_)
		return;

	switch (weapon)
	{
	case TORPEDO:
		//audio->playCue(TORPEDO_HIT);
		// -= FighterNS::TORPEDO_DAMAGE;
		break;
	case SHIP:
		//audio->playCue(COLLIDE);    // play sound
		//health -= shipNS::SHIP_DAMAGE;
		break;
	case PLANET:
		health = 0;
		break;
	}
	if (health <= 0)
	{
		//explode();
	}
	else
		shieldOn_ = true;
}
