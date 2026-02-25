#include <raylib.h>

#include "snake.h"
#include "globals.h"

void draw_snake(snake_t *snake, Vector2 snake_position, Vector2 snake_size)
{
    DrawRectangleV(snake_position, snake_size, MAROON);
}

void check_edges(snake_t *snake)
{
  // If the player reach the end teleport to the bottom
  // or top of the screen
  if (snake->snake_position.x > SCREEN_WIDTH) {
    snake->snake_position.x = 0;
  }

  if (snake->snake_position.x < 0) {
    snake->snake_position.x = SCREEN_WIDTH;
  }

  if (snake->snake_position.y > SCREEN_HEIGHT) {
    snake->snake_position.y = 0;
  }

  if (snake->snake_position.y < 0) {
    snake->snake_position.y = SCREEN_HEIGHT;
  }

}

void update_snake_position(snake_t *snake)
{
  // Update player position

  check_edges(snake);

  if (IsKeyDown(KEY_D))
    snake->snake_position.x += 2.0f;
  if (IsKeyDown(KEY_A))
    snake->snake_position.x -= 2.0f;
  if (IsKeyDown(KEY_S))
    snake->snake_position.y += 2.0f;
  if (IsKeyDown(KEY_W))
    snake->snake_position.y -= 2.0f;
}

bool check_collision(fruit_t *fruit, snake_t *snake)
{
  Vector2 center = {.x = fruit->posX, .y = fruit->posY};
  Rectangle rec = { .x = snake->snake_position.x, .y = snake->snake_position.y,
    .width = snake->width, .height = snake->height};

  bool snake_fruit_collision = CheckCollisionCircleRec( center , FRUIT_RADIUS, rec);
  return snake_fruit_collision;
}

void init_snake(snake_t *snake)
{
  snake->height = SNAKE_SIZE;
  snake->width = SNAKE_SIZE;
  snake->length = 1;

  snake->snake_position.x = (float)SCREEN_WIDTH/2;
  snake->snake_position.y = (float)SCREEN_HEIGHT/2;
  snake->snake_size.x = 15;
  snake->snake_size.y = 15;

}

void increase_snake_length(snake_t *snake)
{
  snake->length += 1;
}
