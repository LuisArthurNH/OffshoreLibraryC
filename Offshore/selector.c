// chave seletora entra entrada A ou B dependendo do valor de controle
void selector_(double *pa, double *pb, double *pctrl_sig, double *pctrl_v, double *pout){

if (*pctrl_sig == *pctrl_v )
{
    *pout = *pa;

}
else{

    *pout = *pb;
}

}

