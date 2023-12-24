#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "raymath.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define NUMBER_OF_POINTS 10000

typedef struct {
  int x;
  int y;
} Point;

void draw(int point_index, Point *points) {
  Point previous_point = *(points + (point_index - 1));
  Point *current_point = (points + point_index);

  int random_value = GetRandomValue(0, 3);

  int jump_value = 6;

  switch (random_value) {
    case 0:
      current_point->y = previous_point.y - jump_value;
      current_point->x = previous_point.x;
      break;
    case 1:
      current_point->x = previous_point.x + jump_value;
      current_point->y = previous_point.y;
      break;
    case 2:
      current_point->y = previous_point.y + jump_value;
      current_point->x = previous_point.x;
      break;
    case 3:
      current_point->x = previous_point.x - jump_value;
      current_point->y = previous_point.y;
      break;
  }

  for (int i = 0; i < point_index + 1; i++) {
    Point point_to_be_drawn = *(points + i);
    DrawCircle(point_to_be_drawn.x, point_to_be_drawn.y, 1, GOLD);
  }
}

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Random walk");

  int x = SCREEN_WIDTH / 2;
  int y = SCREEN_HEIGHT / 2;

  Point *points = (Point *)malloc(NUMBER_OF_POINTS * sizeof(Point));

  Point init_point = {.x = x, .y = y};
  *points = init_point;

  int point_index = 1;
  while (!WindowShouldClose()) {
    BeginDrawing();
    {
      ClearBackground(DARKGRAY);

      if (point_index < NUMBER_OF_POINTS) {
        draw(point_index, points);
        point_index++;
      }
    }
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
