#include <math.h>
#define M_PI 3.14159265358979323846

void abc2alphabeta_(double *pfa, double *pfb, double *pfc, double *pAlpha, double *pBeta){

double a,b,c;

a = *pfa;
b = *pfb;
c = *pfc;

*pAlpha = (2./3.)*(a    -(b/2)         -(c/2));
*pBeta  = (2./3.)*(0    +(b*sqrt(3)/2) -(c*sqrt(3)/2));


}
