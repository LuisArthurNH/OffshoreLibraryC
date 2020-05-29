#include <math.h>
#define M_PI 3.14159265358979323846

void dq2alphabeta_(double *pd, double *pq, double *ptheta, double *pthetazero, double *palpha, double *pbeta){

double d,q,thetazero, theta;

d = *pd;
q = *pq;
theta = *ptheta;
thetazero = *pthetazero;

*palpha = d*cos(theta+thetazero) - q*sin(theta+thetazero);
*pbeta  = d*sin(theta+thetazero) + q*cos(theta+thetazero);

}
