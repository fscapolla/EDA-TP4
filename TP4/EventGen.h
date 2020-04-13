#pragma once
#include "Evento.h"
#include <iostream>
#include <allegro5/allegro.h>

#define FPS 50.0

typedef enum { 
	UP_ON,
	UP_OFF,
	LEFT_ON,
	LEFT_OFF,
	RIGHT_ON,
	RIGHT_OFF, 
	W_ON, 
	W_OFF, 
	A_ON, 
	A_OFF, 
	D_ON, 
	D_OFF, 
	TIME, 
	NOTHING, 
	QUIT 
} eventos;


class EventGen
{
public:
	EventGen();

	eventos nextEvent(void);	//Regresa el siguiente evento a ser atendido.

	//Getters
	ALLEGRO_EVENT_QUEUE* getQueue(void);

	eventos getKey(ALLEGRO_EVENT* eventNow);

	~EventGen();

private:
	ALLEGRO_EVENT_QUEUE * eventQueue;
	ALLEGRO_TIMER * timer;

	// ALLEGRO_DISPLAY * display;
};

