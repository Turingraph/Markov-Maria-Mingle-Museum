#ifndef STATS_H
# define STATS_H

# include <stdlib.h>

// math.c

float	f_abs(float x);
float	f_max(float a, float b);
float	f_floor(float num);
float	f_interval(float num, float min, float max);
float	f_round(float num);

// normal.c

float	normal_distribution_function(float std, float means, float x);
float	f_std(const float *vec_v, size_t dim);
float	f_sum(const float *vec_v, size_t dim);

// taylor.c

float	f_pow(float x, size_t a);
float	f_root_finding(float x, size_t a);
float	f_sin(float x);
float	f_cos(float x);
float	f_exp(float x);

#endif
