#include <stdio.h>

# define MAX 100
int main () {
  double x[ MAX ], y[ MAX ];
  double cx , cy ;
  int i , n;
  scanf ("%d", & n);
  for (i = 0; i < n; i ++)
    scanf ("%lf %lf", &x[i ], & y[i]) ;
  cx = cy = 0;
  for (i = 0; i < n; i ++) {
    cx += x[ i ]/ n;
    cy += y[ i ]/ n;
  }
  printf ("%f %f\n", cx , cy );
  return 0;
}
