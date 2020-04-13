#pragma once
#include "Evento.h"
#include "random.h"
#include <cmath>

#define JUMPINGSPEED 4.5
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
#define FULLMOVEFRAME (3*(MOVINGFRAMES+1))
#define CYCLEFRAMES (FULLMOVEFRAME+5)
#define IDLEFRAMES 4
#define ONESTEP		9
#define RESETCYCLE 3
#define WALKINGSPEED 0,54	// Debe moverse 27 píxeles en 50 ciclos, de donde la velocidad es de 0,54 píxeles/ciclo.
#define FIRSTFALLFRAME 5
#define LASTFALLFRAME 10

typedef enum {LEFT=-1, RIGHT=1} dir_n;
typedef enum { BEGIN_MOVING, IDLE, MOVING, STOP_MOVING, BEGIN_JUMPING, JUMPING, LANDING } wormStates_n;





class Worm
{
public:
	Worm();
	~Worm();

	void increaseWalkFrameCounter(void);
	void increaseJumpFrameCounter(void);
	void wormWalk(void);	//Mueve al worm 9 píxeles en alguna de las 2 direcciones posibles.
	void wormJump(void);	//Mueve al worm durante el salto.
	void setWormKeys(int jumpKey_, int rightKey_, int leftKey_);
	void moveWorm(int keyCode_);
	void stopWorm(int keyCode_);
	void refresh_worm(void);
	void jumpWarmUp(void);
	void turnWorm(int keyCode_);
	void updateWorm(void);

	//Getters
	double getX(void);
	double getY(void);
	dir_n getDirection(void);
	wormStates_n getState(void);
	double getJumpingSpeed(void);
	double getGravity(void);
	double getAngle(void);
	double getWalkingSpeed(void);
	int getJumpKey(void);
	int getLeftKey(void);
	int getRightKey(void);
	int getWalkFrameCounter(void);
	int getJumpFrameCounter(void);


	//Setters
	void setX(double x_);
	void setY(double y_);
	void set_keys(char ku, char kl, char kr);
	void setDirection(dir_n d);
	void setState(wormStates_n newState);
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
	dir_n direction;
	unsigned int jumpDuration;
	double x, y;
	double g;
	double angle;
	double jumpingSpeed;
	double walkingSpeed;
	wormStates_n currentState;
	int walkFrameCounter;
	int jumpFrameCounter;
	int preWalkFrameCounter;
	int preJumpFrameCounter;
	int frameCounter;
	int cycleCounter;
};

