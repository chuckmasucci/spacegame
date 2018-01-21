/*
 * =====================================================================================
 *
 *       Filename:  enemy.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/11/2018 10:56:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef enemy_h
#define enemy_h

#include <bezier.h>
#include <list.h>

#define ENEMY_SPRITE "gfx/sprites/enemy.proto1.png"
#define ENEMY_WIDTH 74
#define ENEMY_HEIGHT 95
#define ENEMY_COUNT 24
#define ENEMY_COLUMNS 6
#define ENEMY_ROWS (int)ceil((float)ENEMY_COUNT / (float)ENEMY_COLUMNS)

int addEnemy(Vector2 *animationPoints);
void positionEnemies(/* Node **enemyHead*/);

#endif