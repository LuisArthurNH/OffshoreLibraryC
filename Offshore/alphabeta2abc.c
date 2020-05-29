#include <math.h>
#define M_PI 3.14159265358979323846

void alphabeta2abc_( double *pAlpha, double *pBeta, double *pfa, double *pfb, double *pfc){

double alpha, beta;

alpha = *pAlpha;
beta = *pBeta;

*pfa =  alpha;
*pfb = -alpha/2 +beta*sqrt(3)/2;
*pfc = -alpha/2 -beta*sqrt(3)/2;

}
