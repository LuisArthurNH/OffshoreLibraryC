#include <math.h>
#define M_PI 3.14159265358979323846

void alphabeta2dq_(double *palpha, double *pbeta, double *ptheta, double *pthetazero, double *pd, double *pq){

double alpha, beta,thetazero, theta;

alpha     = *palpha;
beta      = *pbeta;
theta     = *ptheta;
thetazero = *pthetazero;

*pd =   alpha*cos(theta+thetazero) + beta*sin(theta+thetazero);
*pq = - alpha*sin(theta+thetazero) + beta*cos(theta+thetazero);

}
