#include <f2p.h>

void DMA2DICCF(DICCF_t *DICCF, uint32_t *buffer){
	DICCF->ApSHU = buffer[0];
}

void DIG2DICCF(DICCF_t *DICCF){
	DICCF->ApTHRhv      = HAL_GPIO_ReadPin(GPIOC, ApTHRhv_Pin    );
	DICCF->ApSHU        = HAL_GPIO_ReadPin(GPIOA, ApSHU_Pin      );
};

void DICCF2DICCP(DICCF_t *DICCF, DICCP_t *DICCP) {
	DICCP->ApTHRhv      = DICCF->ApTHRhv ;
	DICCP->ApSHU        = DICCF->ApSHU ;

};
