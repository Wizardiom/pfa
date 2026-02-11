



#define INTEGRATION_C

#include "integration.h"

bool setQuadFormula(QuadFormula* qf, char* name)
{
  if (strcmp(name, "left") != 0 && strcmp(name, "right") != 0 && strcmp(name, "middle") != 0 && strcmp(name, "trapezes") != 0 && strcmp(name, "simpson") != 0 && strcmp(name, "gauss2") != 0 && strcmp(name, "gauss3") != 0)
    return false;
  int len = strlen(name);
  for (int i = 0; i < len; i++)
     qf->name[i] = name[i];

  qf->name[len] = '\0';
  return true;
}
/* This function is not required ,but it may useful to debug */
void printQuadFormula(QuadFormula* qf)
{
  printf("Quadratic formula: %s\n", qf->name);
  /* Print everything else that may be useful */
}


/* Approximate the integral of function f from a to b.
   - f is a pointer to a function pointer
   - a and b are the integration bounds
   - Interval [a,b] is split in N subdivisions [ai,bi]
   - Integral of f on each subdivision [ai,bi] is approximated by the quadrature formula qf.
*/
double integrate(double (*f)(double), double a, double b, int N, QuadFormula* qf)
{
  if (!strcmp(qf->name, "left")){
    double *A = malloc (N * sizeof(double));
    double *B = malloc (N * sizeof(double));
    double *Q = malloc (N * sizeof(double));
    double res = 0.0;
    for (int i = 0; i < N; i++){
      A[i] = a + i*((b-a)/N);
      B[i] = a + (i+1)*((b-a)/N);
      Q[i] = (B[i] - A[i]) * (*f)(A[i]);
      res += Q[i];
    }
    free(A);
    free(B);
    free(Q);
    return res;
  }
  else if (!strcmp(qf->name, "right")){
    double *A = malloc (N * sizeof(double));
    double *B = malloc (N * sizeof(double));
    double *Q = malloc (N * sizeof(double));
    double res = 0.0;
    for (int i = 0; i < N; i++){
      A[i] = a + i*((b-a)/N);
      B[i] = a + (i+1)*((b-a)/N);
      Q[i] = (B[i] - A[i]) * (*f)(B[i]);
      res += Q[i];
    }
    free(A);
    free(B);
    free(Q);
    return res;
  }
  else if (!strcmp(qf->name, "middle")){
    double *A = malloc (N * sizeof(double));
    double *B = malloc (N * sizeof(double));
    double *Q = malloc (N * sizeof(double));
    double res = 0.0;
    for (int i = 0; i < N; i++){
      A[i] = a + i*((b-a)/N);
      B[i] = a + (i+1)*((b-a)/N);
      Q[i] = (B[i] - A[i]) * (*f)((A[i]+B[i])/2.0);
      res += Q[i];
    }
    free(A);
    free(B);
    free(Q);
    return res;
  }
  else if (!strcmp(qf->name, "trapezes")){
    double *A = malloc (N * sizeof(double));
    double *B = malloc (N * sizeof(double));
    double *Q = malloc (N * sizeof(double));
    double res = 0.0;
    for (int i = 0; i < N; i++){
      A[i] = a + i*((b-a)/N);
      B[i] = a + (i+1)*((b-a)/N);
      Q[i] = (B[i] - A[i]) * (*f)(A[i]);
      res += Q[i];
    }
    free(A);
    free(B);
    free(Q);
    return res;
  }
  else
    return 0.0;
}

double integrate_dx(double (*f)(double), double a, double b, double dx, QuadFormula* qf)
{
  return 0.0;
}


