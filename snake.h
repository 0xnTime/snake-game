#include "fruit.h"

typedef struct
{
  float posX;
  float posY;  
  int width;
  int height;
  int length;
} snake_t;

int snake();
void draw_snake(snake_t *snake);
void update_snake_position(snake_t *snake);
bool check_collision(fruit_t *fruit, snake_t *snake);
void increase_snake_length(snake_t *snake);
