#include <raylib.h>

#include "snake.h"
#include "globals.h"

void draw_snake(snake_t *snake, Vector2 snake_size)
{
  for(int i = 0; i < snake->length; i++)
  {
    Vector2 vec;

    vec.x = snake->segments[i].x;
    vec.y = snake->segments[i].y;

    DrawRectangleV(vec, snake_size, MAROON);
  }
}

void check_edges(snake_t *snake)
{
  // If the player reach the end teleport to the bottom
  // or top of the screen
  if (snake->segments[0].x > SCREEN_WIDTH) {
    snake->segments[0].x = 0;
  }

  if (snake->segments[0].x < 0) {
    snake->segments[0].x = SCREEN_WIDTH;
  }

  if (snake->segments[0].y > SCREEN_HEIGHT) {
    snake->segments[0].y = 0;
  }

  if (snake->segments[0].y < 0) {
    snake->segments[0].y = SCREEN_HEIGHT;
  }

}

void update_snake_position(snake_t *snake)
{
  // Update player position
  check_edges(snake);

  if (IsKeyDown(KEY_D)){
    for(int i = snake->length; i >= 0; i--){
      if(i == 0){
        snake->segments[i].x += 2.0f;
      }
      snake->segments[i] = snake->segments[i - 1];
    }
  }

  if (IsKeyDown(KEY_A))
    snake->segments[0].x -= 2.0f;
  if (IsKeyDown(KEY_S))
    snake->segments[0].y += 2.0f;
  if (IsKeyDown(KEY_W))
    snake->segments[0].y -= 2.0f;
}

bool check_collision(fruit_t *fruit, snake_t *snake)
{
  Vector2 center = {.x = fruit->posX, .y = fruit->posY};
  Rectangle rec = { .x = snake->segments[0].x, .y = snake->segments[0].y,
    .width = snake->width, .height = snake->height};

  bool snake_fruit_collision = CheckCollisionCircleRec( center , FRUIT_RADIUS, rec);
  return snake_fruit_collision;
}

void init_snake(snake_t *snake)
{
  snake->height = SNAKE_SIZE;
  snake->width = SNAKE_SIZE;
  snake->length = 1;

  snake->segments[0].x = (float)SCREEN_WIDTH/2;
  snake->segments[0].y = (float)SCREEN_HEIGHT/2;
  snake->snake_size.x = 15;
  snake->snake_size.y = 15;

}

void increase_snake_length(snake_t *snake)
{
  snake->length += 1;
}
