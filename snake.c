#include <raylib.h>

#include "snake.h"
#include "globals.h"

void draw_snake(snake_t *snake)
{
  Vector2 snake_position = {.x = snake->posX, .y = snake->posY};
  Vector2 snake_size = {.x = 15, .y = 15};
  DrawRectangleV(snake_position, snake_size, MAROON);
}

void update_snake_position(snake_t *snake)
{
  // Update player position

  if (IsKeyDown(KEY_D))
    snake->posX += 2.0f;
  if (IsKeyDown(KEY_A))
    snake->posX -= 2.0f;
  if (IsKeyDown(KEY_S))
    snake->posY += 2.0f;
  if (IsKeyDown(KEY_W))
    snake->posY -= 2.0f;

  // If the player reach the end teleport to the bottom
  // or top of the screen
  if (snake->posX > SCREEN_WIDTH) {
    snake->posX = 0;
  }

  if (snake->posX < 0) {
    snake->posX = SCREEN_WIDTH;
  }

  if (snake->posY > SCREEN_HEIGHT) {
    snake->posY = 0;
  }

  if (snake->posY < 0) {
    snake->posY = SCREEN_HEIGHT;
  }

}

bool check_collision(fruit_t *fruit, snake_t *snake)
{
  Vector2 center = {.x = fruit->posX, .y = fruit->posY};
  Rectangle rec = { .x = snake->posX, .y = snake->posY,
    .width = snake->width, .height = snake->height};

  bool snake_fruit_collision = CheckCollisionCircleRec( center , FRUIT_RADIUS, rec);
  return snake_fruit_collision;
}

void init_snake(snake_t *snake)
{
  
  snake->posX = (float)SCREEN_WIDTH/2;
  snake->posY = (float)SCREEN_HEIGHT/2;
  snake->height = SNAKE_SIZE;
  snake->width = SNAKE_SIZE;
  snake->length = 1;
}


void increase_snake_length(snake_t *snake)
{
    snake->length += 1;
}
