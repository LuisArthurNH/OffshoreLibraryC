#include <stdio.h>
#include <stdlib.h>
#include "header_functions.h"

/* TO DO:

How to use a function inside another function using PSCAD
How to code ref zone4
Value of lambda

*/



int main(){

    // Create variables that will be INPUTS and OUTPUTS in the PSCAD model
    double vw,wrm,Te_out,beta_out;
    double Te_calc, beta_calc;
    char name[] = "name";
    vw = 9.96;
    wrm = 19.0066;
    Te_calc = 50000;
    beta_calc = 0;



    checkzone_(name, &vw, &wrm);
    select_output_(&vw,&Te_calc,&beta_calc,&Te_out,&beta_out);

    printf("beta %f e Te_ref %f \n", beta_out, Te_out );


    return 0;
}


