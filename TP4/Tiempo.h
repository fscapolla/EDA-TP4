#pragma once
#include <allegro5/allegro.h>

//Ac� ir�a todo lo que es con timer y separarlo de EventGen.
class Tiempo
{
public:
	Tiempo();
	~Tiempo();




private:
	ALLEGRO_TIMER timer;
};

