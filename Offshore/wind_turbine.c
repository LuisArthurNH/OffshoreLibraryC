#include <math.h>
#define M_PI 3.14159265358979323846

void wind_turbine_(double *pPb, double *pwrm_b, double *pGR, double *pR, double *pro, double *pvw, \
                   double *pwrm, double *pcp, double *pP, double *pP_pu, double *pTm, double *pTm_pu, \
                   double *pTSR){



double P_b, wrm_b, GR, v_wind, wrm, cp;
double P, Tm, R, ro, Tm_b, A, wtur;

P_b    = *pPb;
wrm_b  = *pwrm_b;
GR     = *pGR;
R      = *pR;
ro     = *pro;
v_wind = *pvw;
wrm    = *pwrm;
cp     = *pcp;


A = M_PI*R*R;

wtur = wrm/GR;



*pTSR = (wtur*R)/(v_wind);

Tm_b = P_b/wrm_b;



P = 0.5*A*ro*v_wind*v_wind*v_wind*cp;
Tm = P/wtur;


// International Units
*pP = P;
*pTm = Tm;

// PU system
*pP_pu= P/P_b;
*pTm_pu = Tm/Tm_b;




}
