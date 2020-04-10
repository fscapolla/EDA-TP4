#include "Worm.h"



Worm::Worm()
{
}


Worm::~Worm()
{
}

void Worm::increaseWalkFrameCounter(void)
{
	walkFrameCounter++;
}

void Worm::increaseJumpFrameCounter(void)
{
	jumpFrameCounter++;
}

void Worm::moveWorm(void)
{
	if (direction = right)
	{
		x += ONESTEP;
	}
	else
	{
		x -= ONESTEP;
	}
}

void Worm::turn_around(void)
{

}

void Worm::updateWorm(Evento evento)
{
}





void Worm::setX(double x_)
{
	x = x_;
}

void Worm::setY(double y_)
{
	y = y_;
}

void Worm::set_keys(char ku, char kl, char kr)
{
}

void Worm::setDirection(dir d)
{
	direction = d;
}

void Worm::setState(wormStates nextState)
{
	currentState = nextState;
}

void Worm::setJumpKey(int jumpKey_)
{
	jumpKey = jumpKey_;
}

void Worm::setRightKey(int rightKey_)
{
	rightKey = rightKey_;
}

void Worm::setLeftKey(int leftKey_)
{
	leftKey = leftKey_;
}

void Worm::setWalkFrameCounter(int walkFrame)
{
	walkFrameCounter = walkFrame;
}

void Worm::setJumpFrameCounter(int jumpFrame)
{
	jumpFrameCounter = jumpFrame;
}

double Worm::getX(void)
{
	return x;
}

double Worm::getY(void)
{
	return y;
}

dir Worm::getDirection(void)
{
	return direction;
}

wormStates Worm::getState(void)
{
	return currentState;
}

double Worm::getSpeed(void)
{
	return speed;
}

double Worm::getGravity(void)
{
	return g;
}

double Worm::getAngle(void)
{
	return angle;
}

int Worm::getJumpKey(void)
{
	return jumpKey;
}

int Worm::getLeftKey(void)
{
	return leftKey;
}

int Worm::getRightKey(void)
{
	return rightKey;
}

int Worm::getWalkFrameCounter(void)
{
	return walkFrameCounter;
}

int Worm::getJumpFrameCounter(void)
{
	return jumpFrameCounter;
}
