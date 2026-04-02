/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include "pfa.h"

/* Code here anything you want to test your pfa functions and to show your numerical results */
int main()
{
  if (!init_integration("gauss3", 0.01))
  {
    return 0;
  }

  Option callOpt={
    .type = CALL,
    .S0 = 100.0,
    .K = 100.0,
    .T = 2.0,
    .mu = 0.05,
    .sig = 0.02
  };

  double callPrice = optionPrice(&callOpt);
  double callRef = 10.5172;
  printf("Call K=100 -> computed: %.6f, reference: %.6f\n",
	 callPrice, callRef);

  Option putOpt={
    .type = PUT,
    .S0 = 100.0,
    .K = 115.0,
     .T = 2.0,
    .mu = 0.05,
    .sig = 0.02
  };

  double putPrice = optionPrice(&putOpt);
  double putRef = 4.59834;
  printf("Put  K=115 -> computed: %.6f, reference: %.6f\n",
	 putPrice, putRef);

  printf("\nK variation (CALL and PUT, S0=100, T=2, mu=0.05, sigma=0.02)\n");
  printf("K\tCall\t\tPut\n");
  for (double K = 80.0; K <= 130.0; K += 5.0)
  {
    callOpt.K = K;
    putOpt.K = K;
    printf("%.2f\t%.6f\t%.6f\n", K, optionPrice(&callOpt), optionPrice(&putOpt));
  }


  printf("\n=== Insurance tests ===\n");

  double p[3] = {0.9, 0.05, 0.05};
  InsuredClient client={
    .m = 1.0,
    .s = 1.0,
    .p = p
  };
    double x = 1.0;
    double pdfX1X2 = clientPDF_X1X2(&client, x);
    double cdfX1X2 = clientCDF_X1X2(&client, x);
    double cdfS = clientCDF_S(&client, x);
    printf("For x=%.2f, PDF_X1X2=%.6f, CDF_X1X2=%.6f, CDF_S=%.6f\n",
     x, pdfX1X2, cdfX1X2, cdfS);
  printf("\nx variation (m=s=1, p0=0.9, p1=p2=0.05)\n");
  printf("x\tPDF_X1X2\tCDF_X1X2\tCDF_S\n");
  for (double xv = 0.0; xv <= 10.0; xv += 0.5)
  {
    printf("%.2f\t%.6f\t%.6f\t%.6f\n",
     xv,
     clientPDF_X1X2(&client, xv),
     clientCDF_X1X2(&client, xv),
     clientCDF_S(&client, xv));
  }

  return 0;
}
