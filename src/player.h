#ifndef player_h
#define player_h
#endif

#include <SDL2/SDL.h>
#include "sprite.h"

// Ship data
#define SHIP_SPRITE "gfx/sprites/ship.proto1.png"
#define SHIP_WIDTH 73
#define SHIP_HEIGHT 105

#define BULLET_SPRITE "gfx/sprites/bullet.proto1.png"
#define BULLET_WIDTH 10
#define BULLET_HEIGHT 80

// Declarations
Sprite playerSprite;
void initializePlayer();
void move(int direction, float delta);
void shoot();