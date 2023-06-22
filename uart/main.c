#include "stm8s.h"
#include "stm8s103_serial.h"

#define test_LED GPIOB, GPIO_PIN_5

main()
{
	char ch;
	
	GPIO_Init(test_LED, GPIO_MODE_OUT_PP_LOW_SLOW);
	
	Serial_begin(9600);
	Serial_print_string("Enter command");
	Serial_newline();
	
	while (1) {
		if (Serial_available()) {
			Serial_print_string("You have pressed: ");
			ch = Serial_read_char();
			Serial_print_char(ch);
			Serial_newline();
			
			if (ch == '0') {
				GPIO_WriteHigh(test_LED);
			}
			
			if (ch == '1') 
			{
				GPIO_WriteLow(test_LED);
			}
		}
	}
}