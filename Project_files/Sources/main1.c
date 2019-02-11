#ifndef TEST_UART_H_
#define TEST_UART_H_

#include "Util.h"
#include "string.h"
#include "CLK/CLK.h"

#include "UART/UART.h"
#include "UART/UART.c"

int test_UART(void)
{
	uint8_t uartChannel = 2u;

	/* CLK Init */
	Clk_Init(CLK_FREQUENCY_16_MHZ);

	/* UART2 Init */
	Uart_Init( uartChannel, CLK_FREQUENCY_8_MHZ, UART_BAUDRATE_9600 );

	uint8_t counter = 0;
	char recvBytes[16];
	memset( recvBytes, '\0', 16 );

	char *sendMe = "Hello world!\r\n";
	Uart_Write(uartChannel, sendMe, strlen(sendMe), &counter);

#if 0
	while ( 1 )
	{
		//if ( Uart_GetRxQueueLevel(uartChannel) >= 10 )
		{
			Uart_Read( uartChannel, recvBytes, 10, &counter );
			//++counter;
			//if ( counter >= 10 )

				//counter = 0;
				Uart_Write( uartChannel, recvBytes, 10, &counter );
				//Uart_Write( uartChannel, "\r\n", 2, &counter );

				//memset( recvBytes, '\0', 16 );
				//counter = 0;

		}
=======

		echo();

//		if ( Uart_GetRxQueueLevel(uartChannel) >= 10 )
//		{
//			Uart_Read( uartChannel, recvBytes, 10, &counter );
//			if ( counter >= 10 )
//			{
//				counter = 0;
//				Uart_Write( uartChannel, recvBytes, 10, &counter );
//				Uart_Write( uartChannel, "\r\n", 2, &counter );
//
//				memset( recvBytes, '\0', 16 );
//				counter = 0;
//			}
//		}
>>>>>>> master
	}
#endif
	return 0;
}

#endif /* TEST_UART_H_ */
