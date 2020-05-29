void init_cond_(double *pin, double *time, double *pt_init, double *pinit, double *pout){


if(*time <= *pt_init){

    *pout = *pinit;
}
else {
    *pout = *pin;
}




}
