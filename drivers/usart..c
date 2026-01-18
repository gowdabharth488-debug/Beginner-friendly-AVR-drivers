/*
 * NOTE:
 * This code is designed ONLY for AVR microcontrollers.
 * It will NOT work on Windows, Linux, macOS, or other non-AVR platforms.
 * The examples provided in this code are for **learning and understanding purposes only**.
*/

#define F_CPU 16000000UL 
#include <avr/io.h> 
#include "uart.h" 

void UART_init(uint32_t baud) 
{ 
    uint16_t ubrr = (F_CPU / 16 * baud) - 1; //UBRR (Baud Rate Register)
	/*
	UBRR = (16000000 / (16 * 9600)) - 1  =>UBRR = 103
	The 16-bit UBRR value = 103 
	In binary it is split into: 
	UBRRL =  low 8 bits 
	UBRRH =  high 8 bits 
	For 103 (0x0067): 
	UBRRH = 0x00 
	UBRRL = 0x67 
	We will write this in code like: 
	UBRRH = (ubrr >> 8);   // high bits 
	UBRRL = ubrr;          // low  bits 
 	*/
    UBRRH = (ubrr >> 8); // >> 8 ,it set the upper bit
    UBRRL = ubrr; // it set the lower bit
	
    UCSRB = (1<<RXEN) | (1<<TXEN);       
	/*UCSRB is an 8-bit register that controls: 
	RXEN = Receive enable 
	TXEN = Transmit enable
	RXCIE = Receive complete interrupt enable 
	TXCIE = Transmit complete interrupt enable 
	UCSZ2 = part of character size (data bits) */
    UCSRC = (1<<UCSZ1) | (1<<UCSZ0);     // 8N1 (8bits, no parity, 1stop) UCSZ Bits settings
}  

 
char USART_Receive(void) 
{ 
    while (!(UCSRA & (1 << RXC)));   // Wait until data received 
	/*RXC = Receive Complete flag
	RXC = Becomes 1 when a full byte has been received.
	RXC = Becomes 0 when no new data is available.
	(1 << RXC) = makes a mask for the RXC bit.
	UCSRA & (1 << RXC) = Checks whether RXC bit in UCSRA register is 1.
	If data NOT received = result = 0
	If data received = result ≠ 0 
	!( ... ) = Negates the result.
	If RXC = 0 = !(0) = 1  true, keep waiting
	If RXC = 1 = !(1) = 0 false, stop waiting*/
    return UDR;  
	//It contains the received data when RXC = 1
	//Reading UDR automatically clears RXC flag and waiting for next data
} 

void USART_SendString(char *str) 
//Function takes a pointer to a string.
//Example: "HELLO" passes as str.
{ 
    while (*str) 
	//*str means current character in the string.
	//The loop continues until it reaches NULL ('\0').
	//'H' 'E' 'L' 'L' 'O' '\0'
	//When *str becomes '\0', loop stops.
    { 
        USART_Transmit(*str); //Sends the current character through UART, First loop: sends 'H', Second loop: sends 'E', And so on.
        str++; 
		/*Moves the pointer to the next character in the string. 
		str = 'H'
		str++ = 'E'
		str++ = 'L'
		str++ = 'L'
		str++ = 'O'
		str++ = '\0'  
		loop ends
		*/
    } 
} 

// Below two function are used for Unblocking the CPU  , 
// otherwise the cpu is continously checking the incoming data and it blocks the other oepration!
uint8_t UART_available() 
{ 
    return (UCSR0A & (1<<RXC0));   // 1 = Data available 
	/*It checks whether a byte has been received by the UART.
	(1<<RXC0) == RXC0 = Receive Complete flag
	When a new byte arrives = RXC0 becomes 1
	When no byte = RXC0 = 0
	(UCSR0A & (1 << RXC0)) = This performs a bit check:
	If data available = returns non-zero (1)
	If no data = returns 0
	*/
} 

char UART_read() 
{
    return UDR0;
	//UDR0 = the place where UART stores the incoming byte.
	//return UDR0; = takes that byte and gives it to your program.
}

