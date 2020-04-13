#include <iostream>
#include "EventGen.h"
#include "Simulation.h"
#include <ctime>

using namespace std;

void dispatchEvent(ALLEGRO_EVENT* eventPtr, Simulation *simPtr);

int main(int argc, char *argv[])
{
	//Se crean los objetos para manejar eventos.
	bool res = true;
	Simulation *simPtr = new (nothrow) Simulation();
	EventGen * generator= new (nothrow) EventGen();
	srand(time(NULL));

	//Se verifica que los objetos anteriores se hayan podido crear. 
	if ((simPtr==nullptr) || (generator==nullptr))
	{
		cout << "No se pudo asignar memoria."<<endl;
		res = false;
	}

	//Se generan los dos objetos Worms que controlará el jugador y la parte gráfica.
	if (!(simPtr->initSim(X_DISPLAY, Y_DISPLAY)))
	{
		cout << "No se pudo asignar memoria." << endl;
		res = false;
	}
	
	simPtr->assignKeys();	//Se asigna las teclas a cada worm.


	//Suponiendo que no hubo errores de inicialización, comienza el juego.
	if (res)
	{
		while (!(generator->quitEvent()))	//Si el evento no es de finalización de juego, éste continúa
		{
			if (generator->newEvent())	//Revisa si hay eventos para atender.
			{
				dispatchEvent(generator->nextEvent(), simPtr);	//Procede según el tipo de evento recibido
			}
		}
	}

	//Se libera la memoria dinámica.
	delete generator;
	delete dispatcher;
	delete simPtr;
}



void dispatchEvent(ALLEGRO_EVENT *eventPtr, Simulation * simPtr)
{
	{
		
		{
		case ALLEGRO_EVENT_KEY_DOWN:
			for (int i = 0; i < simPtr->getWormNum(); i++)
			{
				simPtr->wormPtr[i]->updateWorm(evento);
			}
			break;

		case ALLEGRO_EVENT_KEY_UP:
			for (int i = 0; i < simPtr->getWormNum; i++)
			{
				simPtr->wormPtr[i]->stopWorm();
			}
			break;

		case ALLEGRO_EVENT_TIMER:
			for (int i = 0; i < simPtr->getWormNum(); i++)
			{
				simPtr->wormPtr[i]->updateWorm(evento);
				simPtr->grapher->updateGrapher(simPtr->wormPtr, simPtr->getWormNum());
			}
			break;

		default:
			break;
		}
	}
}