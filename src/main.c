#include "raylib.h"
#include "raymath.h"
#include "stdio.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

void find_next_point_to_draw(int *x, int *y) {
  int random_value = GetRandomValue(0, 3);
  printf("random_value: %d\n", random_value);

  int jump_value = 3;

  switch (random_value) {
    case 0:
      *y = *y - jump_value;
      break;
    case 1:
      *x = *x + jump_value;
      break;
    case 2:
      *y = *y + jump_value;
      break;
    case 3:
      *x = *x - jump_value;
      break;
  }
}

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Random walk");

  int x = SCREEN_WIDTH / 2;
  int y = SCREEN_HEIGHT / 2;

  ClearBackground(DARKGRAY);
  while (!WindowShouldClose()) {
    BeginDrawing();
    DrawCircle(x, y, 3, GOLD);

    find_next_point_to_draw(&x, &y);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
