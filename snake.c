#include <raylib.h>

#include "snake.h"
#include "globals.h"

void draw_snake(snake_t *snake, Vector2 snake_size)
{

  for(int i = 0; i < snake->length; i++)
  {
    float progress = snake->timer / snake->update_rate;
    
    float visualX = snake->previous_segments[i].x + (snake->segments[i].x - snake->previous_segments[i].x) * progress;
    float visualY = snake->previous_segments[i].y + (snake->segments[i].y - snake->previous_segments[i].y) * progress;
    
    Vector2 vec;

    vec.x = visualX;
    vec.y = visualY;

    DrawRectangleV(vec, snake_size, MAROON);
  }
}

void check_edges(snake_t *snake)
{



  // If the player reach the end reset the game
  if (snake->segments[0].x > SCREEN_WIDTH) {
    snake->is_dead = true;
  }

  if (snake->segments[0].x < 0) {
    snake->is_dead = true;

  }

  if (snake->segments[0].y > SCREEN_HEIGHT) {
    snake->is_dead = true;

  }

  if (snake->segments[0].y < 0) {
    snake->is_dead = true;

  }

}

void update_snake_position(snake_t *snake)
{
  if(snake->is_dead == false){
    // Update player position
    check_edges(snake);
    snake->timer += GetFrameTime();
    snake->update_rate = 0.2f; 


    if (IsKeyDown(KEY_D) && snake->position.x != -1){
      snake->position = (Vector2){1,0};
    }
    if (IsKeyDown(KEY_A) && snake->position.x != 1){
      snake->position = (Vector2){-1,0};
    }
    if (IsKeyDown(KEY_S) && snake->position.y != -1){
      snake->position = (Vector2){0,1};
    }
    if (IsKeyDown(KEY_W) && snake->position.y != 1){
      snake->position = (Vector2){0,-1};   
    }


    if (snake->timer >= snake->update_rate) {

      for (int i = snake->length - 1; i >= 0; i--) {
        snake->previous_segments[i] = snake->segments[i];
      }

      for (int i = snake->length - 1; i > 0; i--) {
        snake->segments[i] = snake->segments[i - 1];
      }
      snake->segments[0].x += snake->position.x * 20.0f;
      snake->segments[0].y += snake->position.y * 20.0f;
      if(snake->length != 1){
        for(int i = 1; i < snake->length; i++){
          if (snake->segments[0].x == snake->segments[i].x && snake->segments[0].y == snake->segments[i].y) {
            snake->is_dead = true;
          }
        } 
      }
  

      // Reset the timer
      snake->timer = 0.0f;
    }
  }
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
  snake->snake_size.x = 20;
  snake->snake_size.y = 20;
  snake->is_dead = false;

}

void increase_snake_length(snake_t *snake)
{  
  int new_segment = snake->length;

  snake->segments[new_segment] = snake->segments[new_segment - 1];
  snake->previous_segments[new_segment] = snake->segments[new_segment - 1];

  snake->length++;

}
