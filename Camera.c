#include "vec3f.h"
#include "Player.h"

#define DISTANCE_FROM_PLAYER 6.3


#define HEIGHT_ABOVE_PLAYER 1

typedef struct Camera {
	Vector3f position;
	float pitch;
	float yaw;
	float roll;
	Player* player;
} Camera;

void moveCamera(Camera* c) {
	(*c).position.x = 3*(*(*c).player).position.x/6;
	(*c).position.y = (*(*c).player).position.y/2 + HEIGHT_ABOVE_PLAYER;
	(*c).position.z = (*(*c).player).position.z - DISTANCE_FROM_PLAYER;
	
	if(isDoingBarrelRoll() == 0) {
		(*c).roll = -(*(*c).player).roll/2;
	} else {
		(*c).roll = 0;
	}
	
	(*c).pitch = (*(*c).player).pitch/4;
	(*c).yaw = -(*(*c).player).yaw/3;
}

Camera newCamera(Player* p) {
	Camera out = {{0,0.5,0.5}, 0, 0, 0, p};
	return out;
}
