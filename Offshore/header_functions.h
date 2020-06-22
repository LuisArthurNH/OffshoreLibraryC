#ifndef HEADER_FUNCTIONS_H_INCLUDED
#define HEADER_FUNCTIONS_H_INCLUDED

// Power Electronics FUNCTIONS
void abc2dq_(double *pa, double *pb, double *pc, double *ptheta, double *pthetazero, double *psignal, double *pd, double *pq, double *pzero);

void abc2alphabeta_(double *pfa, double *pfb, double *pfc, double *pAlpha, double *pBeta);

void alphabeta2abc_(double *pAlpha, double *pBeta, double *pfa, double *pfb, double *pfc);

void alphabeta2dq_(double *palpha, double *pbeta, double *ptheta, double *pthetazero, double *pd, double *pq);

void dq2alphabeta_(double *pd, double *pq, double *ptheta, double *pthetazero, double *palpha, double *pbeta);

void dq2abc_(double *pd, double *pq, double *pzero,double *ptheta, double *pa, double *pb, double *pc);

void svm_(double *pvalpha_ref, double *pvbeta_ref, double *pvcc, double *ptri, double *ps1, double *ps2, double *ps3, double *pS);

void te_control_(double *pTe_ref,double *pP, double *plambda_m, double *pIq_ref);

// Wind Turbine FUNCTIONS
void checkzone_(double *pvw, double *pwrm_ref, int *ctrl_mode);

void select_output_(double *pvwind, double *pTe_calc, double *pbeta_calc, double *pTe_out, double *pbeta_out);

void calc_cp_(double *pv_wind,  double *pw_tur, double *pbeta, double *pCp, double *pc1, double *pc2, double *pc3, double *pc4, \
                                double *pc5,   double *pc6, double *pc7, double *pc8, double *pc9, double *pl_opt);

void wind_turbine_(double *pPb, double *pwrm_b, double *pGR, double *pR, double *pro, double *pvw, \
                                double *pwrm, double *pcp, double *pP, double *pP_pu, double *pTm, double *pTm_pu, \
                                double *pTSR);

void init_(double *time, double *pvw, double *pN, double *pro, double *plambda_opt, double *pDtur, double *pKsh, double *pcp, \
                                double *pwrm_ini, double *pTem_ini, dou ble *ptheta_tur_rm_ini);

void ramp_(double *pt, double *pt_ini, double *pt_final, double *pv_ini, double *pv_final, double *pdy, double *pdt, \
                                double *pt_i2, double *pt_dur, double *pt_f2, double *pdt2, double *pv_f2, double *pdy2,  \
                                int *pch, double *pout);

void integrator_ini_(double *pin, double *time, double *pt_init, double *pini_value, double *pout);

void selector_(double *pa, double *pb, double *pctrl_sig, double *pctrl_v, double *pout);

void init_cond_(double *pin, double *time, double *t_init, double *pinit, double *pout);

#endif // HEADER_FUNCTIONS_H_INCLUDED
