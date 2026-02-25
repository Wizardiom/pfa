/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "pfa.h"

/* Code here anything you want to test your pfa functions and to show your numerical results */
int main()
{
  if(!init_integration("simpson", 0.01))
  {
    printf("Error in init_integration1\n");
    return 1;
  }
  else if (init_integration("unknown", 0.01))
  {
    printf("Error in init_integration2\n");
    return 1;
  }
  else if (init_integration("simpson", -0.01))
  {
    printf("Error in init_integration\n");
    return 1;
  }
  return 0;
}
