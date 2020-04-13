#include <iostream>
#include "EventGen.h"
#include "Simulation.h"
#include "Graph.h"
#include "Dispatcher.h"
#include "Worm.h"
#include <ctime>
#include <cstdlib>


using namespace std;

int main(int argc, char *argv[])
{
	//Se crean los objetos para manejar eventos.
	bool res = true;

	Simulation *simPtr = new (nothrow) Simulation();
	if (!(simPtr->initSim(X_DISPLAY, Y_DISPLAY)))
	{
		cout << "No se pudo asignar memoria." << endl;
		res = false;
	}
	// Dispatcher *dispatcher = new (nothrow) Dispatcher();
	EventGen* generator = new (nothrow) EventGen();
	res = generator->Init();
	
	srand(time(NULL));

	//Se verifica que los objetos anteriores se hayan podido crear. 
	if ((simPtr==nullptr) || (generator==nullptr))
	{
		cout << "No se pudo asignar memoria."<<endl;
		res = false;
	}

	//Se generan los dos objetos Worms que controlará el jugador y la parte gráfica.

	
	// simPtr->startSim();	//Incializa a los worms y le otorga a cada uno sus teclas.


	//Suponiendo que no hubo errores de inicialización, comienza el juego.
	if (res)
	{
		int i = 0;
		while (!(generator->quitEvent()))	//Si el evento no es de finalización de juego, éste continúa
		{
			if (generator->newEvent())	//Revisa si hay eventos para atender.
			{
				// dispatcher->dispatchEvent(generator->nextEvent(), simPtr);	//Procede según el tipo de evento recibido

				if (generator->getEvent() == ALLEGRO_EVENT_TIMER) {
					if (i >= 15) {
						i = 0;
					}
					simPtr->grapher->drawFrame(
						1212, 
						616, 
						simPtr->grapher->walkingFrames,
						1, 
						-1
					);
					al_flip_display();
					i++;
				}
			}
		}
	}

	//Se libera la memoria dinámica.
	delete generator;
	// delete dispatcher;
	delete simPtr;
}