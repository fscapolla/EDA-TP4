#include <iostream>
#include "EventGen.h"
#include "Simulation.h"
#include <ctime>

using namespace std;

int main(int argc, char* argv[]) {

	// Se crean los objetos para manejar eventos.
	bool res = true;

	Simulation* simPtr = new (nothrow) Simulation();
	res = simPtr->initSim(X_DISPLAY, Y_DISPLAY);

	if (!res)
	{
		cout << "No se pudo asignar memoria." << endl;
		res = false;
	}

	srand(time(NULL));

	// Se verifica que los objetos anteriores se hayan podido crear. 
	EventGen* generator = new (nothrow) EventGen(simPtr->grapher);



	if ((simPtr == nullptr) || (generator == nullptr))
	{
		cout << "No se pudo asignar memoria." << endl;
		res = false;
	}
	
	simPtr->assignKeys();	//Se asigna las teclas a cada worm.

	if (res)
	{
		while (generator->getAllegroEvent().type != ALLEGRO_EVENT_DISPLAY_CLOSE)	//Si el evento no es de finalizaci�n de juego, �ste contin�a
		{

			if (generator->getAllegroEvent().type != ALLEGRO_EVENT_DISPLAY_CLOSE && generator->nextEvent())	//Revisa si hay eventos para atender.
			{
				generator->dispatch(simPtr);
				al_flip_display();
			}
		}
	}

	delete generator;
	delete simPtr;

	return 0;
}
