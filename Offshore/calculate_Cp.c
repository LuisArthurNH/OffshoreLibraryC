
#include <math.h>


void calc_cp_(double *pv_wind, double *pw_tur, double *pbeta, double *pCp, double *pc1, double *pc2, double *pc3, double *pc4, \
                                               double *pc5,   double *pc6, double *pc7, double *pc8, double *pc9, double *pl_opt)
{

// Variaveis auxiliares
double v_wind, w_tur, beta, lambda, alpha, Cp;
double c1, c2, c3, c4, c5, c6, c7,c8,c9;
double l_opt;

c1 = *pc1;
c2 = *pc2;
c3 = *pc3;
c4 = *pc4;
c5 = *pc5;
c6 = *pc6;
c7 = *pc7;
c8 = *pc8;
c9 = *pc9;

// Parameters
const double R  =  90;
//const double c1 =  0.1828;
//const double c2 =  176.7592;
//const double c3 = -2.0587;
//const double c4 =  1.8007;
//const double c5 =  1.1989;
//const double c6 =  9.1004;
//const double c7 =  13.0017;
//const double c8 = -0.0381;
//const double c9 = -0.0340;
//
// Associando as variaveis de ponteiro
v_wind = *pv_wind;
w_tur  = *pw_tur;
beta   = *pbeta;
//
//
lambda = R*w_tur/v_wind;
alpha  = 1 / ( 1/(lambda + c8*beta) - c9/(pow(beta, 3) + 1) );
Cp     = c1*(c2/alpha - c3*beta - c4*pow(beta, c5) - c6)*exp(-c7/alpha);


l_opt = (-pow(beta, 5)*c3*c7*c8 - pow(beta, 4)*c2*c8 - pow(beta, 4)*c6*c7*c8 + pow(beta, 3)*c2*c7 - pow(beta, 2)*c3*c7*c8 - \
          beta*c2*c7*c8*c9 - beta*c2*c8 - beta*c6*c7*c8 - pow(beta, c5 + 1)*c4*c7*c8 - pow(beta, c5 + 4)*c4*c7*c8 + c2*c7)/ \
  (pow(beta, 4)*c3*c7 + pow(beta, 3)*c2 + pow(beta, 3)*c6*c7 + beta*c3*c7 + pow(beta, c5)*c4*c7 + pow(beta, c5 + 3)*c4*c7 + \
  c2*c7*c9 + c2 + c6*c7);

*pl_opt = l_opt;
*pCp   = Cp;

}
