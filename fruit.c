#include <raylib.h>
#include <time.h>
#include <stdlib.h>

#include "globals.h"
#include "fruit.h"

void draw_fruit(fruit_t *fruit)
{
  Vector2 fruit_position = {.x = fruit->posX, .y = fruit->posY};
  DrawCircleV(fruit_position, FRUIT_RADIUS, RED);
}

void spawn_random_fruit(fruit_t *fruit)
{
  srand(time(NULL));

  int pos_x = rand() % SCREEN_WIDTH;
  int pos_y = rand() % SCREEN_HEIGHT;

  fruit->posX = pos_x;
  fruit->posY = pos_y;
 
 
}

void init_fruit(fruit_t *fruit)
{
  fruit->posX = (float)SCREEN_WIDTH/3;
  fruit->posY = (float)SCREEN_HEIGHT/3;
}
