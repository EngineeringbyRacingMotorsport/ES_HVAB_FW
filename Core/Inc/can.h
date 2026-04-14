#ifndef can_h
#define can_h

#include "main.h"

/* Prototips actualitzats per a FDCAN i amb la signatura correcta */
void CAN_Init_Custom(FDCAN_HandleTypeDef *hfdcan);
HAL_StatusTypeDef CAN_Send(FDCAN_HandleTypeDef *hfdcan, uint32_t id, uint8_t *data, uint32_t len);
void CAN_Msg_Maker(SIGNAL_dicc *DICCP, uint8_t *Msg1);

#endif
