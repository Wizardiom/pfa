/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "integration.h"

/* Code here everything you need to test the integration methods and show your numericzal results */
double f(double t){
return sin(t);
}
int main()
{
  QuadFormula qf;
  double I1,I2,I3,I4;
  printf("Left : \n");
  setQuadFormula(&qf, "left");
  I1 = integrate(f, 0, M_PI, 1, &qf);
  printf("%f\n", I1);
  printf("Right : \n");
  setQuadFormula(&qf, "right");
  I2 = integrate(f, 0, M_PI, 1, &qf);
  printf("%f\n", I2);
  printf("Middle : \n");
  setQuadFormula(&qf, "middle");
  I3 = integrate(f, 0, M_PI, 1, &qf);
  printf("%f\n", I3);
  printf("Trapezes : \n");
  setQuadFormula(&qf, "trapezes");
  I4 = integrate(f, 0, M_PI, 1, &qf);
  printf("%f\n", I4);
}
