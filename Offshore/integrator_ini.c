void integrator_ini_(double *pin, double *time, double *pt_ini, double *pini_value, double *pout){


if(*time == *pt_ini){
    *pout = (*pin)*(*pini_value);

}
else {
    *pout = *pin;
}



}
