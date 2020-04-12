#pragma once
#include "Evento.h"
#include "random.h"
#include <cmath>

#define SPEED 4.5
#define G 0.24
#define MAXWORMS 10
#define PLAYERWORMS 2
#define PI 3.14159265359
#define ANGLE (PI/3)
#define X_DISPLAY	1920
#define Y_DISPLAY	696
#define LEFT_EDGE	680
#define RIGHT_EDGE	1175
#define FLOOR		616
#define WAITINGFRAMES 8
#define MOVINGFRAMES 14
#define JUMPINGFRAMES 9
#define ONESTEP		9
#define RESETCYCLE 3

typedef enum {left,right} dir;
typedef enum { begin_moving, idle, moving, Stop_moving, begin_jumping, jumping, landing } wormStates;
typedef enum { rightKeyDown, leftKeyDown, moveKeyUp, jumpKeyDown, jumpKeyUp, newFrame } wormEvents;





class Worm
{
public:
	Worm();
	~Worm();

	void increaseWalkFrameCounter(void);
	void increaseJumpFrameCounter(void);
	void moveWorm(void);	//Mueve al worm 9 píxeles en alguna de las 2 direcciones posibles.
	bool moveWormAir(void);	//Mueve al worm durante el salto.
	void turn_around(void);	//Da la vuelta al worm para que quede mirando en la dirección opuesta
	void setWormKeys(int jumpKey_, int rightKey_, int leftKey_);
	void updateWorm(int keyCode_);
	void stopWorm(void);
	void refresh_worm(void);

	//Getters
	double getX(void);
	double getY(void);
	dir getDirection(void);
	wormStates getState(void);
	double getSpeed(void);
	double getGravity(void);
	double getAngle(void);
	int getJumpKey(void);
	int getLeftKey(void);
	int getRightKey(void);
	int getWalkFrameCounter(void);
	int getJumpFrameCounter(void);


	//Setters
	void setX(double x_);
	void setY(double y_);
	void set_keys(char ku, char kl, char kr);
	void setDirection(dir d);
	void setState(wormStates newState);
	void setJumpKey(int jumpKey_);
	void setRightKey(int rightKey_);
	void setLeftKey(int leftKey_);
	void setWalkFrameCounter(int walkFrame);
	void setJumpFrameCounter(int jumpFrame);

private:	//Escribo todas las variables que se me ocurren pueden resultar útiles. Después vemos cuáles usamos.
	bool isWalking, isJumping;
	int jumpKey;
	int leftKey;
	int rightKey;
	bool isRightKeyPressed;
	bool isLeftKeyPressed;
	dir direction;
	unsigned int jumpDuration;
	double x, y;
	double g;
	double angle;
	double speed;
	wormStates currentState;
	int walkFrameCounter;
	int jumpFrameCounter;
	int preWalkFrameCounter;
	int preJumpFrameCounter;
	int frameCounter;
	int cycleCounter;
};

