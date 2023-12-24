#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "raymath.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define NUMBER_OF_POINTS 10000
#define STEP_SIZE 5

typedef struct {
  int x;
  int y;
} Point;

Point *random_walk(int number_of_points) {
  Point *points = malloc(number_of_points * sizeof(Point));
  points[0] = (Point){0, 0};

  Point previous_point = points[0];
  for (size_t i = 1; i < number_of_points; i++) {
    int random_value = GetRandomValue(0, 3);

    switch (random_value) {
    case 0:
      previous_point.y -= 1;
      break;
    case 1:
      previous_point.x += 1;
      break;
    case 2:
      previous_point.y += 1;
      break;
    case 3:
      previous_point.x -= 1;
      break;
    }

    points[i] = previous_point;
  }

  return points;
}

void draw(Point *points, Color color) {
  for (int i = 0; i < NUMBER_OF_POINTS - 1; i++) {
    Point p1 = points[i];
    Point p2 = points[i + 1];

    DrawLine(SCREEN_WIDTH / 2 + p1.x * STEP_SIZE,
             SCREEN_HEIGHT / 2 + p1.y * STEP_SIZE,
             SCREEN_WIDTH / 2 + p2.x * STEP_SIZE,
             SCREEN_HEIGHT / 2 + p2.y * STEP_SIZE, color);
  }
}

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Random walk");
  SetTargetFPS(60);

  int initial_x = SCREEN_WIDTH / 2;
  int initial_y = SCREEN_HEIGHT / 2;

  Point *points1 = random_walk(NUMBER_OF_POINTS);
  Point *points2 = random_walk(NUMBER_OF_POINTS);
  Point *points3 = random_walk(NUMBER_OF_POINTS);
  Point *points4 = random_walk(NUMBER_OF_POINTS);

  while (!WindowShouldClose()) {
    BeginDrawing();
    {
      ClearBackground(DARKGRAY);
      draw(points1, RED);
      draw(points2, GREEN);
      draw(points3, BLUE);
      draw(points4, GOLD);
    }
    EndDrawing();
  }

  // Next I could add keyboard controls for zooming in and zooming out

  free(points1);
  free(points2);
  free(points3);
  free(points4);
  CloseWindow();

  return 0;
}
