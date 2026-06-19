#include <f2p.h>

void DIG2DICCF(DICCF_t *DICCF){
	DICCF->AfTHRhv      = HAL_GPIO_ReadPin(GPIOC, AfTHRhv_Pin    );
};

void DICCF2DICCP(DICCF_t *DICCF, DICCP_t *DICCP) {
	DICCP->ApTHRhv      = !DICCF->AfTHRhv ;
	DICCP->ApSHU        = ((DICCF->AfSHU*3.3)/4095)/(0.130*100)  ;
};
