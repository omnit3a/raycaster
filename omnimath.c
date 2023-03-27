#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <omnimath.h>
#include <math.h>

/* Basically copied from Quake III's algorithm */
float fast_rsqrt(float number){
  const float three_halfs = 1.5F;
  const float half = 0.5F;
  const uint32_t what_the_fuck = 0x5F3759DF;
  const uint8_t reps = 5;

  float inter = number * half;
  float result = number;
  int64_t iterator = * (long *) &result;
  
  iterator = what_the_fuck - (iterator >> 1);
  result = * (float *) &iterator;
  for (int loop = 0 ; loop < reps ; loop++){
    result = result * (three_halfs - (inter * result * result));
  }
  return result;
}

/* Just multiply an inverse sqrt by the number being calculated */
float fast_sqrt(float number){
  float result = fast_rsqrt(number) * number;
  return result;
}

void rotate_point_2d(point_2d_t * origin, point_2d_t * point, float angle){
  const double radian_angle = -(angle * (M_PI / 180));
  const float sin_angle = sin(radian_angle);
  const float cos_angle = cos(radian_angle);

  const float x_pos = point->x_pos;
  const float y_pos = point->y_pos;
  const float x_center = origin->x_pos;
  const float y_center = origin->y_pos;
  
  float result_x = (((x_pos - x_center) * cos_angle) - ((y_pos - y_center) * sin_angle)) + x_center;
  float result_y = (((x_pos - x_center) * sin_angle) + ((y_pos - y_center) * cos_angle)) + y_center;

  /* Set new position */
  point->x_pos = result_x;
  point->y_pos = result_y;
  /* Set direction of rotation */
  point->rot.x_rot = cos_angle;
  point->rot.y_rot = sin_angle;
}
