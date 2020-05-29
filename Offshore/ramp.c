#include <math.h>

void ramp_(double *pt, double *pt_ini, double *pt_final, double *pv_ini, double *pv_final, double *pdy, double *pdt, \
                       double *pt_i2, double *pt_dur, double *pt_f2, double *pdt2, double *pv_f2, double *pdy2,  \
                       int *pch, double *pout){

//int *pcrtl
double t, t_ini, t_final, t_i2, t_f2;
double  v_ini, v_final, v_f2;
double a, b , a2, b2;
double dy, dt, dy2, dt2, t_dur;
//int crtl;

t       = *pt;

// First Ramp variables
t_ini   = *pt_ini;                // start of ramping
t_final = *pt_final;              // stop of ramping
v_ini   = *pv_ini;                // first value of the ramp
v_final = *pv_final;              // last value of the ramp
dy      = *pdy;
dt      = *pdt;


// First Ramp
if (dy != 0){
    v_final = v_ini + dy;
}

if(dt != 0){
    t_final = t_ini + dt;
}

b = (v_ini*t_final - v_final*t_ini)/(t_final - t_ini);   // y = at+b -> ramp
a = (v_ini - b)/t_ini;

//t_final = *pt_final;                                    // in case of using delta, it is important to put the
//v_ini   = *pv_ini;
//v_final = *pv_final;



// Second Ramp variables
t_i2  = *pt_i2;
t_f2  = *pt_f2;
v_f2  = *pv_f2;
dy2   = *pdy2;
dt2   = *pdt2;
t_dur = *pt_dur;

// Second Ramp
if(dt2 != 0){                 // ramp time
    t_f2 = t_i2 + dt2;
}

if(t_dur != 0){              // initial time ramp
    t_i2 = t_final + t_dur;
}

if (dy2 != 0){                 // ramp height
    v_f2 = v_final + dy2;
}

b2 = (t_f2*v_final - t_i2*v_f2)/(t_f2 - t_i2);   // y = at+b -> ramp2
a2 = (v_f2 - b2)/t_f2;
//a2 = (v_final - v_f2)/(t_f2 - t_i2);



// before ramping
if(t < t_ini){
    *pout = v_ini;
}
// ramping 1
else if(t > t_ini && t < t_final){
    *pout = a*t+b;
}
// after ramping
else if(t >= t_final){
        if (*pch == 0) {
            *pout = v_final;
        }
        else if (t < t_i2){
            *pout = v_final;
        }
        // ramping 1
        else if(t > t_i2 && t < t_f2){
            *pout = a2*t+b2;
        }
        // after ramping
        else if (t >= t_f2)
        {
            *pout = v_f2;
        }

                }
}
