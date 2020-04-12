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
	preWalkFrameCounter = 0;
	preJumpFrameCounter = 0;
	frameCounter = 0;
	cycleCounter = 0;
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

bool Worm::moveWormAir(void)
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
	if (y > FLOOR) 
	{ 
		y = FLOOR; 
		return true;
	}
	else return false;
}

void Worm::turn_around(void)
{

}




void Worm::setWormKeys(int jumpKey_, int rightKey_, int leftKey_)
{
	jumpKey = jumpKey_;
	rightKey = rightKey_;
	leftKey = leftKey_;
}



void Worm::updateWorm(int keyCode_)		//Analiza el estado actual del worm y procede acorde.
{
	switch (currentState)
	{
	case idle:
		if (keyCode_ == jumpKeyUp)
		{
			currentState = jumping;
			jumpFrameCounter++;
		}
		else if (keyCode_ = rightKey || keyCode_ == leftKey)
		{
			currentState = moving;
			direction = ((keyCode_ == rightKey) ? right : left);
			walkFrameCounter = 0;
		}
		break;

	case moving:
		break;

	case jumping:
		break;

	case landing:
		break;
	default:
		break;
	}
}

	void Worm::stopWorm(void)
	{
		switch (currentState)
		{
		case moving:
			if (preWalkFrameCounter < WAITINGFRAMES)	//Si no pasaron los 100 ms se interpreta como que el usuario quiere dar vuelta al worm.
			{
				direction = ((direction == right) ? left : right);

			}

		default:
			break;
		}
	}


	void Worm::refresh_worm(void)		//Se encarga de actualizar los contadores de los worms.
{
		switch (currentState)
		{
		case moving:
			if (preWalkFrameCounter < WAITINGFRAMES)	//Hay una espera de 100 ms hasta que comienzan los ciclos de movimiento.
				preWalkFrameCounter++;
			else walkFrameCounter++;
			if (walkFrameCounter == MOVINGFRAMES)		//una vez que pasan los primeros 15 ciclos vuelve a el contador a 5 ciclos (No hace la espera de nuevo).
			{
				moveWorm();									//Se mueve al worm 9 píxeles.
				walkFrameCounter = WAITINGFRAMES-5;
				cycleCounter++;
			}
			if (cycleCounter>= RESETCYCLE)		//Una vez que se movió los 27 píxeles, comienza todo desde cero.
			{
				preWalkFrameCounter = 0;
				walkFrameCounter = 0;
				cycleCounter = 0;
			}
			break;
		
		case jumping:
						//Tiene cuatro partes, una de espera, otra de salto, una de aterrizaje, una que vuelve a lo normal.
		default:
			break;
		}
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
