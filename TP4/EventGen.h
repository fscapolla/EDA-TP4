#pragma once
#include "Evento.h"
#include <iostream>
#include <allegro5/allegro.h>


class EventGen
{
public:
	~EventGen();

	EventGen(ALLEGRO_EVENT_QUEUE* Queue_ = nullptr, ALLEGRO_TIMER* timer = nullptr);
	bool Init(double fps = 20.0);
	bool newEvent(void);	//Revisa si hay un nuevo evento.
	Evento nextEvent(void);	//Regresa el siguiente evento a ser atendido.
	bool quitEvent(void);	//Verifica si se seleccionó el evento que finaliza el programa.

	//Getters
	ALLEGRO_EVENT_QUEUE* getQueue(void);
	ALLEGRO_EVENT_TYPE getEvent(void);

private:
	Evento evento;
	ALLEGRO_EVENT_QUEUE * eventQueue;
	ALLEGRO_TIMER * timer;
	ALLEGRO_EVENT alEvent;
};

