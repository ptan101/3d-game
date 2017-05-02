#ifndef Enemy_h
#define Enemy_h

#include "stdint.h"
#include "vec3f.h"

enum enemyType {
	BASIC
};

typedef struct Enemy{
	enum enemyType type;
	Entity entity;
	Vector3f position;
	Vector3f velocity;
		
	float reloadTime;
	float reloadCounter;
	//float health;
	
} Enemy;

void moveEnemies(Player* player, Projectile_Collection* pCollection);

void renderEnemies(void);

#endif
