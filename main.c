#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <omnimath.h>

int main(){

  /* Insert test code here */
  point_2d_t origin = {
    0,
    0,
    0,
    0,
  };

  point_2d_t test_point = {
    5,
    5,
    {0, 0, 1},
  };

  rotate_point_2d(&origin, &test_point, 0);
  printf("x: %.2f, y: %.2f\n", test_point.x_pos, test_point.y_pos);
  
  return 0;
}
