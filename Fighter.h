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
	virtual void neutralB();
	virtual void sideB();
	virtual void upB();
	virtual void downB()
	virtual void standardAttack

private:
	Position position_;
	Fighter_State fighter_state_;
};

