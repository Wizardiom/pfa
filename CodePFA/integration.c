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
  if (strcmp(name, "left") == 0){
    qf->size = 1;
    qf->x = malloc(qf->size * sizeof(double));
    qf->w = malloc(qf->size * sizeof(double));
    qf->x[0] = 0;
    qf->w[0] = 1;
  }
  else if (strcmp(name, "right") == 0){
    qf->size = 1;
    qf->x = malloc(qf->size * sizeof(double));
    qf->w = malloc(qf->size * sizeof(double));
    qf->x[0] = 1;
    qf->w[0] = 1;
  }
  else if (strcmp(name, "middle") == 0){
    qf->size = 1;
    qf->x = malloc(qf->size * sizeof(double));
    qf->w = malloc(qf->size * sizeof(double));
    qf->x[0] = 0.5;
    qf->w[0] = 1;
  }
  else if (strcmp(name, "trapezes") == 0){
    qf->size = 2;
    qf->x = malloc(qf->size * sizeof(double));
    qf->w = malloc(qf->size * sizeof(double));
    qf->x[0] = 0;
    qf->x[1] = 1;
    qf->w[0] = 0.5;
    qf->w[1] = 0.5;
  }
  return true;
}

void printQuadFormula(QuadFormula* qf)
{
  printf("Quadratic formula: %s\n", qf->name);
}

double integrate(double (*f)(double), double a, double b, int N, QuadFormula* qf)
{
  double h = (b - a) / N;
  double res = 0.0;
  
  for (int i = 0; i < N; i++){
    double ai = a + i * h;
    double bi = ai + h;
    
    if (strcmp(qf->name, "left") == 0)
      res += qf->w[0] * f(ai);
    else if (strcmp(qf->name, "right") == 0)
      res += qf->w[0] * f(bi);
    else if (strcmp(qf->name, "middle") == 0)
      res += qf->w[0] * f((ai + bi) / 2);
    else if (strcmp(qf->name, "trapezes") == 0)
      res += qf->w[0] * f(ai) + qf->w[1] * f(bi);
    else
      return 0.0;
  }
  
  return res;
}

double integrate_dx(double (*f)(double), double a, double b, double dx, QuadFormula* qf)
{
  return 0.0;
}


