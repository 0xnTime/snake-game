#include <raylib.h>
#include <stdlib.h>

#include "globals.h"
#include "snake.h"

int main(void) {

  fruit_t *fruit = malloc(sizeof(fruit_t));
  init_fruit(fruit);

  snake_t *snake = malloc(MAX_SNAKE_LENGTH * sizeof(snake_t));
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
    if (IsKeyPressed(KEY_C)) {
      spawn_random_fruit(fruit);
      increase_snake_length(snake);
    }

    if (check_collision(fruit, snake)) {
      spawn_random_fruit(fruit);
      increase_snake_length(snake);
    }
    EndDrawing();
  }

  free(fruit);
  free(snake);

  CloseWindow();

  return 0;
}
