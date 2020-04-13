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
	jumpingSpeed = JUMPINGSPEED;
	walkingSpeed = WALKINGSPEED;

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

void Worm::wormWalk(void)
{
	if (frameCounter >= MOVINGFRAMES)
	{
		frameCounter = 0;
	}

	x += walkingSpeed*direction;
	if (x > RIGHT_EDGE)
	{
		x -= RIGHT_EDGE;
	}
	if (x <= LEFT_EDGE)
	{
		x += LEFT_EDGE;
	}

	walkFrameCounter++;
}

void Worm::wormJump(void)
{
	x += (direction*jumpingSpeed*cos(angle));
	if (x > RIGHT_EDGE)
	{
		x -= RIGHT_EDGE;
	}
	if (x < LEFT_EDGE)
	{
		x += LEFT_EDGE;
	}
	
	y += ((-1)*jumpingSpeed*sin(angle)*jumpFrameCounter + (g / 2)*pow(jumpFrameCounter, 2));
}


void Worm::setWormKeys(int jumpKey_, int rightKey_, int leftKey_)
{
	jumpKey = jumpKey_;
	rightKey = rightKey_;
	leftKey = leftKey_;
}



void Worm::moveWorm(int keyCode_)		//Analiza el estado actual del worm y procede acorde. Actúa cuando llega un evento de tipo key_Down
{
	switch (currentState)
	{
	case idle:
		if (keyCode_ == jumpKeyUp)	
		{
			currentState = begin_jumping;
			frameCounter = 0;
			jumpWarmUp();
		}
		else if (keyCode_ = rightKey || keyCode_ == leftKey)
		{
			currentState = begin_moving;
			direction = ((keyCode_ == rightKey) ? right : left);
			preWalkFrameCounter = 0;
			frameCounter = 0;
		}
		break;

	case begin_moving:
		if (keyCode_ == jumpKey)
		{
			frameCounter = 0;
			currentState = begin_jumping;
			jumpWarmUp();
		}
		else if (keyCode_ == rightKey || keyCode_ == leftKey)
		{
			if (preWalkFrameCounter >= IDLEFRAMES)
			{
				currentState = moving;
				preWalkFrameCounter = 0;
				frameCounter = 0;
			}
		}
		break;

	case moving:
		if (keyCode_ == jumpKey)
		{
			currentState = begin_jumping;
			frameCounter = 0;
			jumpWarmUp();
		}
		else if (keyCode_ == rightKey || keyCode_ == leftKey)
		{
			wormWalk();
			if (walkFrameCounter >= FULLMOVEFRAME)
			{
				preWalkFrameCounter++;
			}
			if (walkFrameCounter >= CYCLEFRAMES)
			{
				walkFrameCounter = 0;
			}
		}
		break;

	case begin_jumping:
		jumpWarmUp();
		break;

	case jumping:
		if(y<=FLOOR)		//Si toadavía no aterrizo actualiza la posición y los contadores.
			wormJump();
		else {
			frameCounter = FIRSTFALLFRAME;		//Una vez que aterriza se pasa a dibujar los frames de aterrizaje.
			jumpFrameCounter = 0;
			currentState = landing;
			y = FLOOR;
		}
		break;

	case landing:
		if (frameCounter >= FIRSTFALLFRAME && frameCounter <= LASTFALLFRAME) //Mientras está descendiendo no se modifica el estado.
		{
		}
		else
		{
			currentState = idle;		//Worm has landed.
			frameCounter = 0;
			y = FLOOR;
		}
		break;

	default:
		break;
	}
}

	void Worm::stopWorm(int keyCode_)	//Según el estado del worm actúa acorde. Se llama cuando llega un evento de tipo KEY_UP
	{
		switch (currentState)
		{
		case moving:
			if (keyCode_ == rightKey || keyCode_ == leftKey)
			{
				if (walkFrameCounter <= FULLMOVEFRAME)		//Si está en la sección de warm up deja de moverse inmediatamente
				{
					currentState = idle;
				}
				if (walkFrameCounter >= FULLMOVEFRAME)		//si pasaron los 100 ms completa el ciclo y luego se detiene
				{
					currentState = begin_moving;
					frameCounter = 0;
					preWalkFrameCounter = 0;
				}
				walkFrameCounter = 0;
			}
			break;

		case begin_moving:
			if (keyCode_ == rightKey || keyCode_ == leftKey)		//Como no pasaron los primeros 100ms y no está en estado moving, se quedará quieto o cambiará de dirección.
			{
				preWalkFrameCounter = 0;
				currentState = idle;
				turnWorm(keyCode_);	//Revisa si es necesario cambiar la dirección de worm.
			}
			break;

		default:
			break;
		}
	}


	void Worm::refresh_worm(void)		//Se encarga de actualizar los contadores de los worms.
{
		switch (currentState)
		{
		case idle:
			frameCounter = 0;
			break;
		case begin_moving:
			if (preWalkFrameCounter >= IDLEFRAMES)
			{
				currentState = moving;
				preWalkFrameCounter = 0;
				frameCounter = 0;
			}
			break;
			
		case moving:
			wormWalk();
			if (walkFrameCounter >= FULLMOVEFRAME)
			{
				preWalkFrameCounter++;
			}
			if (walkFrameCounter >= CYCLEFRAMES)
			{
				walkFrameCounter = 0;
			}
			break;

		default:
			break;
		}
}

	void Worm::jumpWarmUp(void)		//Lleva a cabo el las animaciones de warm up antes del salto.
	{
		if (frameCounter >= 0 && frameCounter <= IDLEFRAMES)	//Warmup.
		{
		}	
		else
		{
			currentState = jumping;		//Una vez que finalizó el warm up comienza a moverse.
		}
	}


	void Worm::turnWorm(int keyCode_)
	{
		if ((keyCode_ == leftKey && direction == right) || (keyCode_ == rightKey && direction == left))	//Se debe invertir
		{
			direction = ((direction == right) ? left : right);
		}
	}

	void Worm::updateWorm(void)		//Incrementa el contador de la acción que corresponda.
	{
		switch (currentState)
		{
		case begin_moving:			//Si todavía está en la etapa de warm up, actualiza sólo el contador temporario. (no el de frames de la caminata)
			preWalkFrameCounter++;
			break;

		case begin_jumping:
		case jumping:
			jumpFrameCounter++;
			break;

		default:
			break;
		}
		frameCounter++;
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

double Worm::getJumpingSpeed(void)
{
	return jumpingSpeed;
}

double Worm::getGravity(void)
{
	return g;
}

double Worm::getAngle(void)
{
	return angle;
}

double Worm::getWalkingSpeed(void)
{
	return walkingSpeed;
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
