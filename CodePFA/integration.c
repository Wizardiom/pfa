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
  else if (strcmp(name, "simpson") == 0){
    qf->size = 3;
    qf->x = malloc(qf->size * sizeof(double));
    qf->w = malloc(qf->size * sizeof(double));
    qf->x[0] = 0;
    qf->x[1] = 0.5;
    qf->x[2] = 1;
    qf->w[0] = 1.0/6.0;
    qf->w[1] = 4.0/6.0;
    qf->w[2] = 1.0/6.0;
  }
  else if (strcmp(name, "gauss2") == 0){
    qf->size = 2;
    qf->x = malloc(qf->size * sizeof(double));
    qf->w = malloc(qf->size * sizeof(double));
    qf->x[0] = 0.5 - sqrt(3.0)/6.0;
    qf->x[1] = 0.5 + sqrt(3.0)/6.0;
    qf->w[0] = 0.5;
    qf->w[1] = 0.5;
  }
  else if (strcmp(name, "gauss3") == 0){
    qf->size = 3;
    qf->x = malloc(qf->size * sizeof(double));
    qf->w = malloc(qf->size * sizeof(double));
    qf->x[0] = 0.5 - sqrt(15.0)/10.0;
    qf->x[1] = 0.5;
    qf->x[2] = 0.5 + sqrt(15.0)/10.0;
    qf->w[0] = 5.0/18.0;
    qf->w[1] = 8.0/18.0;
    qf->w[2] = 5.0/18.0;
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
  if(setQuadFormula(qf, qf->name) == false)
    return 0.0;
  for (int i = 0; i < N; i++){
    double ai = a + i * h;
    double bi = ai + h;
    double tempres = 0.0;
    for (int j = 0; j < qf->size; j++){
      double xj = ai + qf->x[j] * (bi - ai);
      tempres += qf->w[j] * f(xj);
    }
    res += tempres*(bi - ai);
  }
  
  return res;
}

double integrate_dx(double (*f)(double), double a, double b, double dx, QuadFormula* qf)
{
  int N = 
  double res = integrate(f, a, b, N, qf);
  return res;
}


