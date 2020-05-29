#include <math.h>

void select_output_(double *pvwind, double *pTe_calc, double *pbeta_calc, double *pTe_out, double *pbeta_out){

double vw_nom = 11.259845458589721;
double vwind, Te_calc, beta_calc, Te_out, beta_out, Te_nom;

Te_nom = 526132.043279;

vwind     = *pvwind;
Te_calc   = *pTe_calc;
beta_calc = *pbeta_calc;




// If wind velocity is lower than the turbine nominal speed,select velocity mode control
if(vwind <= vw_nom){

    Te_out = Te_calc;
    beta_out = 0;
}

// If wind velocity is greater than the turbine nominal speed,select pitch mode control

else {

    Te_out   = - Te_nom;
    beta_out =   beta_calc;
}



*pbeta_out = beta_out;
*pTe_out   = Te_out;

}





