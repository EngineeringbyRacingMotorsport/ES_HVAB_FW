#ifndef CAN_h
#define CAN_h

#include "main.h"


typedef struct {

	uint8_t data[]; //de cuanto tiene que ser el array

}CAN_Msg;
typedef struct {
	/* ================ MISSATGE 1 ================ */
	uint8_t ASHU;    //byte 1 i 2 (mA)
	uint8_t ATHRhv;  //byte 0
	uint8_t StatusError;


} SIGNAL_dicc;

/* Prototips actualitzats per a FDCAN i amb la signatura correcta */
void CAN_Init_Custom(FDCAN_HandleTypeDef *hfdcan);
HAL_StatusTypeDef CAN_Send(FDCAN_HandleTypeDef *hfdcan, uint32_t id, uint8_t *data, uint32_t len);
void CAN_Msg_Maker(SIGNAL_dicc *DICCP, uint8_t *Msg1);

#endif
