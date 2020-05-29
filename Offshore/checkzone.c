#include <math.h>
#define M_PI 3.14159265358979323846

void checkzone_(double *pvw, double *pwrm_ref, int *ctrl_mode){

double vw_ini, vw_min, vw_max, v_nom, v_max;
double lambda_opt, R;
double ns, fe, Poles;
double wrm_nom, wrm_min, wrm_max, wrm_ref,vw,N;

lambda_opt = 10.5934727377;
R          = 90;
Poles      = 16;
fe         = 20;
N          = 15;

vw_ini     = 2.9588356510335516;
vw_min     = 6.13877710731;
vw_max     = 10.7651018838;
v_nom      = 11.259845458589721;
v_max      = 25;

ns         = 120*fe/Poles;
wrm_nom    = ns*2*M_PI/60;
wrm_min    = 0.69*wrm_nom;
wrm_max    = 1.21*wrm_nom;

vw         = *pvw;

// região 0
//if(vw < vw_min){
//   wrm_ref = 0;
//  *ctrl_mode = 0;
//}

// região 1
if(vw >= vw_ini && vw < vw_min){
    wrm_ref = wrm_min;
    *ctrl_mode = 1;
}
// região 2
else if(vw >= vw_min && vw < vw_max){
    wrm_ref =  N*(vw*lambda_opt)/(R);
    *ctrl_mode = 2;
}
// região 3
else if(vw >= vw_max && vw < v_nom){
    wrm_ref = wrm_max;
    *ctrl_mode = 3;
}
// região 4
else if(vw > v_nom && vw <= v_max ){
    wrm_ref = wrm_max;
    //wrm_ref = 0;
    *ctrl_mode = 4;
}
// região 5
else if(vw > v_max)
{
    wrm_ref = 0;
    *ctrl_mode = 5;
}

*pwrm_ref = wrm_ref;

}
