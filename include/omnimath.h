#ifndef OMNIMATH_H_
#define OMNIMATH_H_

typedef struct vector_2d_s {
  double x_rot;
  double y_rot;
  double length; 
} vector_2d_t;

typedef struct point_2d_s {
  double x_pos;
  double y_pos;
  vector_2d_t rot;
} point_2d_t;

float fast_rsqrt(float number);
float fast_sqrt(float number);

void rotate_point_2d(point_2d_t * center, point_2d_t * point, float angle);

#endif
