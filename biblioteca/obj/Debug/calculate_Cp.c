
#include <math.h>


void calc_cp_(double *pv_wind, double *pw_tur, double *pbeta, double *pCp)
{

// Variaveis auxiliares
double v_wind, w_tur, beta, lambda, alpha, Cp;
//

// Parameters
const double R  =  90;
const double c1 =  0.1828;
const double c2 =  176.7592;
const double c3 = -2.0587;
const double c4 =  1.8007;
const double c5 =  1.1989;
const double c6 =  9.1004;
const double c7 =  13.0017;
const double c8 = -0.0381;
const double c9 = -0.0340;
//
// Associando as variaveis de ponteiro
v_wind = *pv_wind;
w_tur  = *pw_tur;
beta   = *pbeta;
//
//
lambda = R*w_tur/v_wind;
alpha  = 1 / ( 1/(lambda - c8*beta) - c9/(pow(beta, 3) + 1) );
Cp     = c1*(c2/alpha - c3*beta - c4*pow(beta, c5) - c6)*exp(-c7/alpha);
//
*pCp   = Cp;

}
