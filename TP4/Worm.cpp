#include "Worm.h"



Worm::Worm()	//Se inicializa el worm en reposo y mirando a la derecha por defecto. Aparecen en posiciones aleatorias. 
{
	currentState = idle;
	isJumping = false;
	isWalking = false;
	x = randBetweenReal((double)LEFT_EDGE, (double)RIGHT_EDGE);
	y = FLOOR;
	walkFrameCounter = 0;
	jumpFrameCounter = 0;
	direction = right;
	rightKey = NULL;
	leftKey = NULL;
	jumpKey = NULL;
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
		if (x > RIGHT_EDGE)
		{
			x -= ONESTEP;
		}

	}
	else
	{
		x -= ONESTEP;
		if (x < LEFT_EDGE)
		{
			x += ONESTEP;
		}
	}
}

void Worm::moveWormAir(void)
{
	if (direction == right)
	{
		x += (speed*cos(angle));
		if (x > RIGHT_EDGE)
		{
			x -= (speed*cos(angle));
		}
	}
	else
	{
		x -= (speed*cos(angle));
		if (x < LEFT_EDGE)
		{
			x += (speed*cos(angle));
		}
	}
	
	y = FLOOR - speed*sin(angle)*jumpFrameCounter + (g / 2)*pow(jumpFrameCounter, 2);
	if (y > FLOOR) { y = FLOOR; }
}

void Worm::turn_around(void)
{

}

void Worm::updateWorm(Evento *evento)	//Según el evento que llegó y el evento actual, llama a la función correcta
{
	int type = evento->getType;
	int keyCode = evento->getKeycode;

	switch (type)
	{
	case rightKeyDown:leftKeyDown:jumpKeyDown:
	moveWorm(keyCode);
	break;

	case moveKeyUp:jumpKeyUp:
	stopWorm();
	break;

	case newFrame:
		refresh_worm();
		break;

	default:
		break;
	}
}

void Worm::setWormKeys(int jumpKey_, int rightKey_, int leftKey_)
{
	jumpKey = jumpKey_;
	rightKey = rightKey_;
	leftKey = leftKey_;
}

void Worm::moveWorm(int keyCode)		//Analiza el estado actual del worm y procede acorde.
{
	if (currentState==idle)				//Si el worm está quieto, comienza a moverse o a saltar.
	{
		if (keyCode == jumpKey)
		{
			currentState = begin_jumping;
			jumpFrameCounter++;
		}
		if (keyCode == rightKey)
		{
			currentState = begin_moving;


		}
	}
}

void Worm::stopWorm(void)
{
}

void Worm::refresh_worm(void)
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
