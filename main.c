#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#include "snake.h"
#include "globals.h"

int main(void)
{

  fruit_t *fruit = malloc(sizeof(fruit_t));
  init_fruit(fruit);

  snake_t *snake = malloc(sizeof(snake_t));
  init_snake(snake);


  SetTargetFPS(60);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] - snake game");

  while (!WindowShouldClose()) {
    // Draw
    BeginDrawing();
      ClearBackground(RAYWHITE);
      draw_snake(snake, snake->snake_size);
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
