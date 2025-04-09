/*
 * USART3.h
 *
 * Created: 05.07.2022 10:32:42
 *  Author: Microchip Technology
 */ 


#ifndef USART3_H_
#define USART3_H_
#include <xc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "../clk/clk.h"

/* Normal Mode, Baud register value */
#define USART3_BAUD_RATE(BAUD_RATE) (((float)F_CPU * 64 / (16 * (float)BAUD_RATE)) + 0.5)


/**
 * @ingroup USART3
 * @brief Initialize USART3 interface.
 * @param none
 * @retval 0 - the USART3 init was successful
 * @retval 1 - the USART3 init was not successful
 */ 
void USART3_Initialize(void);

/**
 * @ingroup USART3
 * @brief API to Enable RX and TX in USART3 interface.
 * @param none
 * @return none
 */
void USART3_Enable(void);

/**
 * @ingroup USART3
 * @brief APi to Enable RX in USART3 interface.
 * @param none
 * @return none
 */ 
void USART3_EnableRx(void);

/**
 * @ingroup USART3
 * @brief API to Enable TX in USART3 interface.
 * @param none
 * @return none
 */
void USART3_EnableTx(void);

/**
 * @ingroup USART3
 * @brief API to Disable USART3 interface.
 * @param none
 * @return none
 */
void USART3_Disable(void);

/**
 * @ingroup USART3
 * @brief API to Get recieved data from USART3 interface.
 * @param none
 * @return uint8_t - Data register from USART3 module
 */
uint8_t USART3_GetData(void);

/**
 * @ingroup USART3
 * @brief API to check if the USART3 can accept data to be transmitted.
 * @param none
 * @retval false - the USART3 transmitter is not ready
 * @retval true  - the USART3 transmitter is ready
 */ 
bool USART3_IsTxReady(void);

/**
 * @ingroup USART3
 * @brief API to check if the USART3 has received data.
 * @param none
 * @retval false - the USART3 has not received data
 * @retval true  - the USART3 has received data
 */
bool USART3_IsRxReady(void);

/**
 * @ingroup USART3
 * @brief API to check if the USART3 has transmitter is Busy.
 * @param none
 * @retval true  - the USART3 transmitter is busy
 * @retval false - the USART3 transmitter is free
 */
bool USART3_IsTxBusy(void);

/**
 * @ingroup USART3
 * @brief API to check if the USART3 data is transmitted.
 * @param none
 * @retval false - Data completely shifted out of the USART shift register
 * @retval true  - Data is not completely shifted out of the shift register
 */
bool USART3_IsTxDone(void);

/**
 * @ingroup USART3
 * @brief API to Read one character from USART3. Function will block if a character is not available.
 * @param none
 * @return uint8_t - Data read from the USART3 module
 */
uint8_t USART3_Read(void);

/**
 * @ingroup USART3
 * @brief API to Write one character from USART3. Function will block if a character can be accepted.
 * @param const uint8_t data - The character to write to the USART
 * @return none
 */
void USART3_Write(const uint8_t data);

/**
 * @ingroup USART3
 * @brief API for ErrorCheck USART3 interface. Checks the Recieve Error for Parity, Framing, OverRun
 * @param none
 * @return none
 */
void USART3_ErrorCheck(void);

/**
 * @ingroup USART3
 * @brief Callback function to be called if the Framing Error is occured.
 * @param void* callbackHandler - A pointer to the function to be set as framing error interrupt handler
 * @return none
 */
void USART3_FramingErrorCallbackRegister(void* callbackHandler);

/**
 * @ingroup USART3
 * @brief Callback function to be called if the Overrun Error is occured.
 * @param void* callbackHandler - A pointer to the function to be set as Overrun error interrupt handler
 * @return none
 */
void USART3_OverrunErrorCallbackRegister(void* callbackHandler);

/**
 * @ingroup USART3
 * @brief Callback function to be called if the Parity check Error is occured.
 * @param void* callbackHandler - A pointer to the function to be set as Parity error interrupt handler
 * @return none
 */
void USART3_ParityErrorCallbackRegister(void* callbackHandler);

#endif /* USART3_H */