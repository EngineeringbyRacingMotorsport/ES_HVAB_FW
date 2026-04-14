#include <can.h>


void CAN_Msg_Maker(SIGNAL_dicc *DICCP, uint8_t *Msg1)
{

	/* ================ MISSATGE 1 ================ */
    //byte 0 (valor directo 8 bits)
	Msg1[0] |= (DICCP->ApTHRhv & 0xFF);
	//byte 1 (8 bits de la derecha)
	Msg1[1] |= (DICCP->ApSHU   & 0x00FF);  /* Desplazamiento de bits */
	//byte 2 (8 bits de la izquierda)
	// Primero movemos los de la izquierda a la derecha (>> 8) y luego filtramos
	Msg1[2] |= ((DICCP->ApSHU   & 0xFF00) >> 8);


}

// Les teves funcions d'enviament i creació (CAN_Send, CAN_Msg_Maker...)
HAL_StatusTypeDef CAN_Send(FDCAN_HandleTypeDef *hfdcan, uint32_t id, uint8_t *data, uint32_t len) {

    FDCAN_TxHeaderTypeDef txHeader;

    txHeader.Identifier = id;
    txHeader.IdType = FDCAN_STANDARD_ID;
    txHeader.TxFrameType = FDCAN_DATA_FRAME;
    txHeader.DataLength = len;
    txHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    txHeader.BitRateSwitch = FDCAN_BRS_OFF;
    txHeader.FDFormat = FDCAN_CLASSIC_CAN;
    txHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    txHeader.MessageMarker = 0;

    return HAL_FDCAN_AddMessageToTxFifoQ(hfdcan, &txHeader, data);
}
// Inicialització completa: Filtres + Notificacions + Start
void CAN_Init_Custom(FDCAN_HandleTypeDef *hfdcan) {
    FDCAN_FilterTypeDef sFilterConfig;

    // 1. Configuració de filtre per acceptar-ho TOT
    sFilterConfig.IdType = FDCAN_STANDARD_ID;
    sFilterConfig.FilterIndex = 0;
    sFilterConfig.FilterType = FDCAN_FILTER_RANGE;
    sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    sFilterConfig.FilterID1 = 0x000;
    sFilterConfig.FilterID2 = 0x7FF;

    if (HAL_FDCAN_ConfigFilter(hfdcan, &sFilterConfig) != HAL_OK) Error_Handler();

    // 2. Activar la interrupció de la FIFO 0
    if (HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK) Error_Handler();
    // 3. Arrencar el perifèric
    if (HAL_FDCAN_Start(hfdcan) != HAL_OK) Error_Handler();
}



