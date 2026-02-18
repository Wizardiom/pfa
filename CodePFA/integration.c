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
    
    if (!strcmp(qf->name, "left")){
      res += h * (*f)(ai);
    }
    else if (!strcmp(qf->name, "right")){
      res += h * (*f)(bi);
    }
    else if (!strcmp(qf->name, "middle")){
      res += h * (*f)((ai + bi) / 2.0);
    }
    else if (!strcmp(qf->name, "trapezes")){
      res += h * ((*f)(ai) / 2.0 + (*f)(bi) / 2.0);
    }
    else
      return 0.0;
  }
  
  return res;
}

double integrate_dx(double (*f)(double), double a, double b, double dx, QuadFormula* qf)
{
  return 0.0;
}


