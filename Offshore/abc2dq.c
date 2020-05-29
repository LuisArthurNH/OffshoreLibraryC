#include <math.h>
#include <stdio.h>
#define M_PI 3.14159265358979323846

void abc2dq_(double *pa, double *pb, double *pc, double *ptheta, double *pthetazero, double *psignal, double *pd, double *pq, double *pzero){

double a,b,c, theta, thetazero, phi;

a = *pa;
b = *pb;
c = *pc;

theta = *ptheta;
thetazero = *pthetazero;

phi = (2*M_PI)/3;

if (*psignal == 0 ){
*pd =    (2./3.)*(a*cos(theta + thetazero) + b*cos(theta + thetazero - phi) + c*cos(theta + thetazero + phi));
*pq =   -(2./3.)*(a*sin(theta + thetazero) + b*sin(theta + thetazero - phi) + c*sin(theta + thetazero + phi));
*pzero = (2./3.)*(a*(0.5)                  + b*(0.5)                        + c*(0.5));
}
else{
*pd =    (2./3.)*(a*cos(theta + thetazero) + b*cos(theta + thetazero - phi) + c*cos(theta + thetazero + phi));
*pq =    (2./3.)*(a*sin(theta + thetazero) + b*sin(theta + thetazero - phi) + c*sin(theta + thetazero + phi));
*pzero = (2./3.)*(a*(0.5)                  + b*(0.5)                        + c*(0.5));

}
}
