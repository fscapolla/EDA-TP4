#include <iostream>
#include "EventGen.h"
#include "Simulation.h"
#include "Graph.h"
#include "Dispatcher.h"
#include "Worm.h"
#include <ctime>
#include <cstdlib>


using namespace std;
void dispatch(eventos eventNow, Simulation* simPtr);

int main(int argc, char* argv[]) {

	// Se crean los objetos para manejar eventos.
	bool res = true;

	Simulation* simPtr = new (nothrow) Simulation();
	if (!(simPtr->initSim(X_DISPLAY, Y_DISPLAY)))
	{
		cout << "No se pudo asignar memoria." << endl;
		res = false;
	}

	srand(time(NULL));

	// Se verifica que los objetos anteriores se hayan podido crear. 
	EventGen* generator = new (nothrow) EventGen();

	eventos eventNow = NOTHING;

	if ((simPtr == nullptr) || (generator == nullptr))
	{
		cout << "No se pudo asignar memoria." << endl;
		res = false;
	}

	if (res)
	{
		while (eventNow != QUIT)	//Si el evento no es de finalización de juego, éste continúa
		{
			eventNow = generator->nextEvent();

			if (eventNow != QUIT && eventNow != NOTHING)	//Revisa si hay eventos para atender.
			{
				dispatch(eventNow, simPtr);
			}
		}
	}

	delete generator;
	delete simPtr;

	return 0;
}


void dispatch(eventos eventNow, Simulation* simPtr) {
	switch (eventNow) { 
	// Analiza el evento recibido

		//Flechas que se aplican al worm1
	case UP_ON:
		//		worm1->jump();
		break;
	case UP_OFF:
		//		worm1->stopJumping();
		break;
	case LEFT_ON:
		//		worm1->left();
		break;
	case LEFT_OFF:
		//		worm1->stopLeft();
		break;
	case RIGHT_ON:
		//		worm1->goRight();
		break;
	case RIGHT_OFF:
		//		worm1->stopRight();
		break;

		//WASD que se aplican al worm2
	case W_ON:
		//		worm2->jump();
		break;
	case W_OFF:
		//		wormP2->stopJumping();
		break;
	case A_ON:
		//		wormP2->goLeft();
		break;
	case A_OFF:
		//		wormP2->stopLeft();
		break;
	case D_ON:
		//		wormP2->goRight();
		break;
	case D_OFF:
		//		wormP2->stopRight();
		break;

		//Caso TIMER, mira para ver si tiene que avanzar o no
	case TIME:
		//Se me ocurre que podriamos updeitear los worms dependiendo del 
		//estado en el que esten y lo que indique el contador de cada uno.
//		worm1->updateStatus();
//		worm2->updateStatus();
		break;
	}
	simPtr->grapher->drawFrame(
		/* worm->x*/
		1212,
		616,
		simPtr->grapher->walkingFrames,
		1,
		-1
	);
	al_flip_display();
	//		simulGraph(*wormP1, *wormP2);
}

