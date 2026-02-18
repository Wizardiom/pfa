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
  double I1,I2,I3,I4, I5,I6,I7;
  printf("Left : \n");
  setQuadFormula(&qf, "left");
  I1 = integrate_dx(f, 0, M_PI, 0.1, &qf);
  printf("%f\n", I1);
  printf("Right : \n");
  setQuadFormula(&qf, "right");
  I2 = integrate_dx(f, 0, M_PI, 0.1, &qf);
  printf("%f\n", I2);
  printf("Middle : \n");
  setQuadFormula(&qf, "middle");
  I3 = integrate_dx(f, 0, M_PI, 0.1, &qf);
  printf("%f\n", I3);
  printf("Trapezes : \n");
  setQuadFormula(&qf, "trapezes");
  I4 = integrate_dx(f, 0, M_PI, 0.1, &qf);
  printf("%f\n", I4);
  printf("Simpson : \n");
  setQuadFormula(&qf, "simpson");
  I5 = integrate_dx(f, 0, M_PI, 0.1, &qf);
  printf("%f\n", I5);
  printf("Gauss2 : \n");
  setQuadFormula(&qf, "gauss2");
  I6 = integrate_dx(f, 0, M_PI, 0.1, &qf);
  printf("%f\n", I6);
  printf("Gauss3 : \n");
  setQuadFormula(&qf, "gauss3");
  I7 = integrate_dx(f, 0, M_PI, 0.1, &qf);
  printf("%f\n", I7);
}
