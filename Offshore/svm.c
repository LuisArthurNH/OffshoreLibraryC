#include <math.h>
#define M_PI 3.14159265358979323846

void svm_(double *pvalpha, double *pvbeta, double *pvcc, double *ptri, double *ps1, double *ps2, double *ps3, double *pS)
{

// Variaveis auxiliares
double v_ref;
double T1, T2, T3, Ts;
double delta1, delta2, delta3;
double m;
double theta, phi;
double S;
double Valpha_ref, Vbeta_ref, Vtri, Vcc, S1, S2, S3;
//
// Parametros
double fs = 5000;
Ts = 1/fs;
//
//
Valpha_ref = *pvalpha;
Vbeta_ref  = *pvbeta;
Vcc        = *pvcc;
Vtri       = *ptri;
//
//
theta = atan2(Vbeta_ref, Valpha_ref);
v_ref = sqrt(Valpha_ref*Valpha_ref + Vbeta_ref*Vbeta_ref);
m     = sqrt(3.0)*Ts*v_ref/Vcc;
//
//================================================================================//
//                              Setor 1
//================================================================================//
if((theta >= 0) & (theta < M_PI/3.0))
{

S = 1;

phi = theta - (S-1)*(M_PI/3.0);

T1 = m*sin((M_PI/3.0)-phi);
T2 = m*sin(phi);
T3 = Ts - T2 - T1;

delta1 = T1/Ts;
delta2 = T2/Ts;
delta3 = 1 - delta1 - delta2;

	if(delta1 > Vtri)
	{
	S1 = 1;
	S2 = 0;
	S3 = 0;
	}
	else if(delta1+delta2 > Vtri)
	{
	S1 = 1;
	S2 = 1;
	S3 = 0;
	}
	else
	{
	S1 = 1;
	S2 = 1;
	S3 = 1;
	}
}

//================================================================================//
//                              Setor 2
//================================================================================//
else if((theta >= M_PI/3.0) & (theta < 2*M_PI/3))
{

S = 2;

phi = theta - (S-1)*(M_PI/3);

T1 = m*sin((M_PI/3.0)-phi);
T2 = m*sin(phi);
T3 = Ts - T2 - T1;

delta1 = T1/Ts;
delta2 = T2/Ts;
delta3 = 1 - delta1 - delta2;

	if(delta1 > Vtri)
	{
	S1 = 1;
	S2 = 1;
	S3 = 0;
	}
	else if(delta1 + delta2 > Vtri)
	{
	S1 = 0;
	S2 = 1;
	S3 = 0;
	}
	else
	{
	S1 = 0;
	S2 = 0;
	S3 = 0;
	}
}

//================================================================================//
//                              Setor 3
//================================================================================//
else if((theta >= 2*M_PI/3) & (theta <= M_PI))
{

S = 3;

phi = theta - (S-1)*(M_PI/3);

T1 = m*sin((M_PI/3.0)-phi);
T2 = m*sin(phi);
T3 = Ts - T2 - T1;

delta1 = T1/Ts;
delta2 = T2/Ts;
delta3 = 1 - delta1 - delta2;

	if(delta1 > Vtri)
	{
	S1 = 0;
	S2 = 1;
	S3 = 0;
	}
	else if(delta1 + delta2 > Vtri)
	{
	S1 = 0;
	S2 = 1;
	S3 = 1;
	}
	else
	{
	S1 = 1;
	S2 = 1;
	S3 = 1;
	}
}

//================================================================================//
//                              Setor 4
//================================================================================//
else if((theta >= (-M_PI)) & (theta < (-2*M_PI/3)))
{

S = 4;

phi = theta - (S-1)*M_PI/3;

T1 = m*sin((M_PI/3.0)-phi);
T2 = m*sin(phi);
T3 = Ts - T2 - T1;

delta1 = T1/Ts;
delta2 = T2/Ts;
delta3 = 1 - delta1 - delta2;

	if(delta1 > Vtri)
	{
	S1 = 0;
	S2 = 1;
	S3 = 1;
	}
	else if(delta1 + delta2 > Vtri)
	{
	S1 = 0;
	S2 = 0;
	S3 = 1;
	}
	else
	{
	S1 = 0;
	S2 = 0;
	S3 = 0;
	}

}

//================================================================================//
//                              Setor 5
//================================================================================//
else if((theta >= - 2*M_PI/3) & (theta < -M_PI/3))
{

S = 5;

phi = theta - (S-1)*M_PI/3;

T1 = m*sin((M_PI/3.0)-phi);
T2 = m*sin(phi);
T3 = Ts - T2 - T1;

delta1 = T1/Ts;
delta2 = T2/Ts;
delta3 = 1 - delta1 - delta2;

	if(delta1 > Vtri)
	{
	S1 = 0;
	S2 = 0;
	S3 = 1;
	}
	else if(delta1 + delta2 > Vtri)
	{
	S1 = 1;
	S2 = 0;
	S3 = 1;
	}
	else
	{
	S1 = 1;
	S2 = 1;
	S3 = 1;
	}
}

//================================================================================//
//                              Setor 6
//================================================================================//
else if((theta >= -M_PI/3) & (theta < 0 ))
{

S = 6;

phi = theta - (S-1)*M_PI/3;

T1 = m*sin((M_PI/3.0)-phi);
T2 = m*sin(phi);
T3 = Ts - T2 - T1;

delta1 = T1/Ts;
delta2 = T2/Ts;
delta3 = 1 - delta1 - delta2;

	if(delta1 > Vtri)
	{
	S1 = 1;
	S2 = 0;
	S3 = 1;
	}
	else if(delta1 + delta2 > Vtri)
	{
	S1 = 1;
	S2 = 0;
	S3 = 0;
	}
	else
	{
	S1 = 0;
	S2 = 0;
	S3 = 0;
	}
}

//================================================================================//
//                              IF not
//================================================================================//


else{
S   = 0;
phi = 0;
T1  = 0;
T2  = 0;
T3  = 0;

delta1 = 0;
delta2 = 0;
delta3 = 0;

S1 = 0;
S2 = 0;
S3 = 0;


}

*ps1 = S1;
*ps2 = S2;
*ps3 = S3;
*pS  = S;

//*pS1 = delta1;
//*pS2 = delta2;
//*pS3 = delta3;

}
