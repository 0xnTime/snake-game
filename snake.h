#include "fruit.h"
#include "raylib.h"

typedef struct
{
  int width;
  int height;
  int length;

  Vector2 snake_position;
  Vector2 snake_size;
} snake_t;

int snake();
void draw_snake(snake_t *snake, Vector2 snake_position, Vector2 snake_size);
void update_snake_position(snake_t *snake);
bool check_collision(fruit_t *fruit, snake_t *snake);
void increase_snake_length(snake_t *snake);
void init_snake(snake_t *snake);
