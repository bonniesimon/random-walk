#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "raymath.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define NUMBER_OF_POINTS 10000
#define JUMP_VALUE 8

typedef struct {
  size_t x;
  size_t y;
} Point;

random_walk(Point *points, int number_of_steps) {
  Point previous_point = points[0];
  for (size_t i = 1; i < number_of_steps; i++) {
    int random_value = GetRandomValue(0, 3);

    switch (random_value) {
      case 0:
        previous_point.y -= JUMP_VALUE;
        break;
      case 1:
        previous_point.x += JUMP_VALUE;
        break;
      case 2:
        previous_point.y += JUMP_VALUE;
        break;
      case 3:
        previous_point.x -= JUMP_VALUE;
        break;
    }

    points[i] = previous_point;
  }
}

void draw(Point *points) {
  for (int i = 0; i < NUMBER_OF_POINTS; i++) {
    Point point_to_be_drawn = points[i];
    DrawCircle(point_to_be_drawn.x, point_to_be_drawn.y, 2, GOLD);
  }
}

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Random walk");
  SetTargetFPS(60);

  int initial_x = SCREEN_WIDTH / 2;
  int initial_y = SCREEN_HEIGHT / 2;

  Point *points = malloc(NUMBER_OF_POINTS * sizeof(Point));
  points[0] = (Point){initial_x, initial_y};

  random_walk(points, NUMBER_OF_POINTS);

  while (!WindowShouldClose()) {
    BeginDrawing();
    {
      ClearBackground(DARKGRAY);
      draw(points);
    }
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
