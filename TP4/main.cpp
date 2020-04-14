#include <iostream>
#include "EventGen.h"
#include "Simulation.h"
#include <ctime>

using namespace std;

int main(int argc, char* argv[]) {

	bool res = true;

	srand(time(NULL));

	Simulation* simPtr = new (nothrow) Simulation();		//Simulation is initialized.
	if (simPtr == nullptr)
		res = false;
	else res = simPtr->initSim(X_DISPLAY, Y_DISPLAY);			//Graphing requirements are initialized and worms are assigned their game keys.
	EventGen* generator = new (nothrow) EventGen(simPtr->grapher);		//Event generator is created.
	if (generator == nullptr)
		res = false;
															
	if (!res)								//Assuming no errors, the game begins.
	{
		cout << "No se pudo asignar memoria." << endl;
	}
	

	if (res)
	{
		while (generator->getAllegroEvent().type != ALLEGRO_EVENT_DISPLAY_CLOSE)	//Checks whether the user wants to close the display or not.
		{

			if (generator->getAllegroEvent().type != ALLEGRO_EVENT_DISPLAY_CLOSE && generator->nextEvent())	//Checks if there are events in the queue
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
