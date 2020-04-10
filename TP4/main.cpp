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
	EventGen * generator= new (nothrow) EventGen();
	Dispatcher *dispatcher = new (nothrow) Dispatcher();
	srand(time(NULL));

	//Se verifica que los objetos anteriores se hayan podido crear. 
	if ((simPtr==nullptr) || (generator==nullptr) || (dispatcher==nullptr))
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
	
	simPtr->startSim();	//Incializa a los worms y le otorga a cada uno sus teclas.


	//Suponiendo que no hubo errores de inicialización, comienza el juego.
	if (res)
	{
		while (!(generator->quitEvent()))	//Si el evento no es de finalización de juego, éste continúa
		{
			if (generator->newEvent())	//Revisa si hay eventos para atender.
			{
				dispatcher->dispatchEvent(generator->nextEvent(), simPtr);	//Procede según el tipo de evento recibido
			}
		}
	}

	//Se libera la memoria dinámica.
	delete generator;
	delete dispatcher;
	delete simPtr;
}