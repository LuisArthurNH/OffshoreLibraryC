
#include <math.h>
#define M_PI 3.14159265358979323846

void init_(double *time, double *pvw, double *pN, double *pro, double *plambda_opt, double *pDtur, double *pKsh, double *pcp, double *pwrm_ini, double *pTem_ini, double *ptheta_tur_rm_ini){

double vw_ini, vw_min, vw_max, v_nom, v_max;
double wrm_nom, wrm_min, wrm_max, wrm_ref;
double Tsh_ar, Dtur;
double lambda, alpha, beta;

double fe, Poles, ns, lambda_opt, R, A, Ptur, cp, ro;
double vw, Ttur, Ksh, N;

vw_ini     = 2.9588356510335516;
vw_min     = 6.13877710731;
vw_max     = 10.7651018838;
v_nom      = 11.46;
v_max      = 25;

const double c1 =  0.1828;
const double c2 =  176.7592;
const double c3 = -2.0587;
const double c4 =  1.8007;
const double c5 =  1.1989;
const double c6 =  9.1004;
const double c7 =  13.0017;
const double c8 = -0.0381;
const double c9 = -0.0340;

    fe    = 20;
    Poles = 16;
    R     = 90;

    ns         = 120*fe/Poles;
    wrm_nom    = ns*M_PI/30;
    wrm_min    = 0.69*wrm_nom;
    wrm_max    = 1.21*wrm_nom;

    vw         = *pvw;
    lambda_opt = *plambda_opt;
    N          = *pN;
    Dtur       = *pDtur;
    Ksh        = *pKsh;
    ro         = *pro;

    lambda_opt = 10.5934727377;

    if(*time < 0.00001){

        if(vw >= vw_ini && vw < vw_min){
            wrm_ref  = wrm_min;
        }
        // região 2
        else if(vw >= vw_min && vw < vw_max){
            wrm_ref =  N*(vw*lambda_opt)/(R);
        }
        // região 3
        else if(vw >= vw_max && vw <= v_nom){
            wrm_ref = wrm_max;
        }
        // região 4
        else if(vw > v_nom && vw <= v_max ){
            wrm_ref = wrm_max;
        }


        /////////////////////////////////////////////////////////////
        // CP
        /////////////////////////////////////////////////////////////
        beta = 0;
        lambda = R*wrm_ref/(vw*N);
        alpha  = 1 / ( 1/(lambda - c8*beta) - c9/(pow(beta, 3) + 1) );
        cp     = c1*(c2/alpha - c3*beta - c4*pow(beta, c5) - c6)*exp(-c7/alpha);




        /////////////////////////////////////////////////////////////
        // Tem_ini, Wrm_ini e theta_ini
        /////////////////////////////////////////////////////////////
        A = M_PI*R*R;
        Ptur = 0.5*A*ro*vw*vw*vw*cp;
        Ttur = Ptur/(wrm_ref/N);

         Tsh_ar             = (Ttur - Dtur*(wrm_ref/N))/N;
        *ptheta_tur_rm_ini  =  Tsh_ar/Ksh;
        *pTem_ini           = - Tsh_ar;

        *pwrm_ini  =  wrm_ref;
        *pcp = cp;

    }

}
