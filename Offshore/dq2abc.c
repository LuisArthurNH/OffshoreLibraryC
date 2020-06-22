#include <math.h>
#include <stdio.h>
#define M_PI 3.14159265358979323846

void dq2abc_(double *pd, double *pq, double *pzero,double *ptheta, double *pa, double *pb, double *pc){

double d, q, zero, theta, phi;


d    = *pd;
q    = *pq;
zero = *pzero;

theta = *ptheta;

phi = (2*M_PI)/3;

*pa =    q*cos(theta)        + d*sin(theta)        + zero;
*pb =    q*cos(theta - phi)  + d*sin(theta - phi)  + zero;
*pc =    q*cos(theta + phi)  + d*sin(theta + phi)  + zero;

}
