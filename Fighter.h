struct Position
{
	int x;
	int y;
};

enum  Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

enum Fighter_State
{
	STANDING,
	WALKING,
	RUNNING,
	JUMPING,
	FALLING
};

class Fighter
{
public:
	Fighter();
	void move(Direction direction);
	//Pure virtual functions
	//All characters must have these functions
	virtual void neutralB() = 0;
	virtual void sideB() = 0;//<B>
	virtual void upB() = 0;  //^B
	virtual void downB() = 0;//vB
	virtual void standardAttack() = 0;//A 

protected:
	Position position_;
	Fighter_State state_;
	int HealthPoints_;
};

