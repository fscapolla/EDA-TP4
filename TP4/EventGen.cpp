#include "EventGen.h"

using namespace std;


EventGen::EventGen(Graph*graph) {

	// CREO E INICIALIZO TIMER
	if (!(timer = al_create_timer(1.0 / FPS)))
		cout << "Error al inicializar timer de allegro" << endl;
	else
		al_start_timer(timer);

	// CREO E INICIALIZO COLA
	if (!(eventQueue = al_create_event_queue()))
		cout << "Error al inicializar la cola de eventos de Alegro" << endl;



	// FALTA REGISTRAR DISPLAY
	if (!al_install_keyboard())
		cout << "Error al inicializar el teclado" << endl;

	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	// Registro el timer en la queue
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));

	al_register_event_source(eventQueue, al_get_display_event_source(graph->getDisplay()));

}

EventGen::~EventGen()
{
	if (eventQueue)
		al_destroy_event_queue(eventQueue);
	if (timer)
		al_destroy_timer(timer);
	al_uninstall_keyboard();	
}

ALLEGRO_EVENT EventGen::getAllegroEvent(void) {
	return alEvent;
}

int EventGen::nextEvent(void) {
	int res = 1;
	if (!al_get_next_event(eventQueue, &alEvent))
		res = 0; // si no hay eventos no hace nada
	return res;
}


ALLEGRO_EVENT_QUEUE* EventGen::getQueue(void)
{
	return eventQueue;
}

void EventGen::dispatch(Simulation* simPtr) {
	cout << alEvent.type << endl;
	switch (alEvent.type) {
	case ALLEGRO_EVENT_KEY_UP:
		for (int i = 0; i < 2; i++) {
			simPtr->wormPtr[i]->stopWorm(alEvent.keyboard.keycode);
		}
		break;
	case ALLEGRO_EVENT_KEY_DOWN:
		for (int i = 0; i < 2; i++) {
			cout << "debug" << endl;
			simPtr->wormPtr[i]->moveWorm(alEvent.keyboard.keycode);
		}
		break;
	case ALLEGRO_ALPHA_SHIFT:
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_set_target_backbuffer(simPtr->grapher->getDisplay());
		al_draw_bitmap(simPtr->grapher->getBackground(), 0, 0, 0);
		for (int i = 0; i < 2; i++) {
			simPtr->wormPtr[i]->updateWorm();
			simPtr->wormPtr[i]->refresh_worm();
			cout << "worm " << i<< " X " << simPtr->wormPtr[i]->getX() << endl;
			cout << "worm " << i << " Y " << simPtr->wormPtr[i]->getY() << endl;
			cout << "worm " << i << " frame " << simPtr->wormPtr[i]->getWalkFrameCounter() << endl;
			simPtr->grapher->drawFrame(
				simPtr->wormPtr[i]->getX(),
				simPtr->wormPtr[i]->getY(),
				simPtr->grapher->walkingFrames,
				simPtr->wormPtr[i]->getWalkFrameCounter(),
				-1
			);
		}
		break;
	}
}
