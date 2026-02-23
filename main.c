#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

#include "snake.h"
#include "globals.h"

int main(void)
{

  fruit_t *fruit = malloc(sizeof(fruit_t));
  fruit->posX = (float)SCREEN_WIDTH/3;
  fruit->posY = (float)SCREEN_HEIGHT/3;

  snake_t *snake = malloc(sizeof(snake_t));
  snake->posX = (float)SCREEN_WIDTH/2;
  snake->posY = (float)SCREEN_HEIGHT/2;
  snake->height = SNAKE_SIZE;
  snake->width = SNAKE_SIZE;
  snake->length = 1;

  SetTargetFPS(60);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] - snake game");

  while (!WindowShouldClose()) {
    // Draw
    BeginDrawing();
      ClearBackground(RAYWHITE);
      draw_snake(snake);
      update_snake_position(snake);
      draw_fruit(fruit);
      if(check_collision(fruit,snake)) {
        spawn_random_fruit(fruit);
        increase_snake_length(snake);
        printf("Snake Lenght: %i\n", snake->length);
      }
    EndDrawing();
  }

  free(fruit);
  free(snake);

  CloseWindow();

  return 0;
}
