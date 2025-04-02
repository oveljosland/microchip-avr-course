#include "usart3.h"

#define RECEIVE_ERROR_MASK 0x46


static void DefaultFramingErrorCallback(void);
static void DefaultOverrunErrorCallback(void);
static void DefaultParityErrorCallback(void);
void (*USART3_framing_err_cb)(void) = &DefaultFramingErrorCallback;
void (*USART3_overrun_err_cb)(void) = &DefaultOverrunErrorCallback;
void (*USART3_parity_err_cb)(void) = &DefaultParityErrorCallback;


void USART3_Initialize(void)
{
	// TX Out
	PORTB.DIRSET = PIN0_bm;
	//set baud rate register
	USART3.BAUD = (uint16_t)USART3_BAUD_RATE(115200);
	
	// TXEN enabled;
	USART3.CTRLB = USART_TXEN_bm;
	
	//  CHSIZE Character size: 8 bit;
	USART3.CTRLC = USART_CHSIZE_8BIT_gc;

}

void USART3_FramingErrorCallbackRegister(void* callbackHandler)
{
	USART3_framing_err_cb=callbackHandler;
}

void USART3_OverrunErrorCallbackRegister(void* callbackHandler)
{
	USART3_overrun_err_cb=callbackHandler;
}

void USART3_ParityErrorCallbackRegister(void* callbackHandler)
{
	USART3_parity_err_cb=callbackHandler;
}

static void DefaultFramingErrorCallback(void)
{
	/* Add your interrupt code here or use USART3.FramingCallbackRegister function to use Custom ISR */
}

static void DefaultOverrunErrorCallback(void)
{
	/* Add your interrupt code here or use USART3.OverrunCallbackRegister function to use Custom ISR */
}

static void DefaultParityErrorCallback(void)
{
	/* Add your interrupt code here or use USART3.ParityCallbackRegister function to use Custom ISR */
}

void USART3_Enable(void)
{
	USART3.CTRLB |= USART_RXEN_bm | USART_TXEN_bm;
}

void USART3_EnableRx(void)
{
	USART3.CTRLB |= USART_RXEN_bm;
}

void USART3_EnableTx(void)
{
	USART3.CTRLB |= USART_TXEN_bm;
}

void USART3_Disable(void)
{
	USART3.CTRLB &= ~(USART_RXEN_bm | USART_TXEN_bm);
}

uint8_t USART3_GetData(void)
{
	return USART3.RXDATAL;
}

bool USART3_IsTxReady(void)
{
	return (USART3.STATUS & USART_DREIF_bm);
}

bool USART3_IsRxReady(void)
{
	return (USART3.STATUS & USART_RXCIF_bm);
}

bool USART3_IsTxBusy(void)
{
	return (!(USART3.STATUS & USART_TXCIF_bm));
}

bool USART3_IsTxDone(void)
{
	return (USART3.STATUS & USART_TXCIF_bm);
}

void USART3_ErrorCheck(void)
{
	uint8_t errorMask = USART3.RXDATAH;
	if(errorMask & RECEIVE_ERROR_MASK)
	{
		if(errorMask & USART_PERR_bm)
		{
			USART3_parity_err_cb();
		}
		if(errorMask & USART_FERR_bm)
		{
			USART3_framing_err_cb();
		}
		if(errorMask & USART_BUFOVF_bm)
		{
			USART3_overrun_err_cb();
		}
	}
	
}

uint8_t USART3_Read(void)
{
	return USART3.RXDATAL;
}

void USART3_Write(const uint8_t data)
{
	USART3.TXDATAL = data;
}