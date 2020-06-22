#include <math.h>
#include <stdio.h>

void te_control_(double *pTe_ref,double *pP, double *plambda_m, double *pIq_ref)
{

double Te_ref, P, lambda_m;

Te_ref = *pTe_ref;
P = *pP;
lambda_m = *plambda_m;

*pIq_ref = (Te_ref*4)/(3*P*lambda_m);

}
