/*
 * my_keypad.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ascom
 */
#include<avr/io.h>
#include<util/delay.h>
#include "my_keypad.h"


/*
 *       COL1  COL2   COL3
 * ROW1   1     2      3
 * ROW2   4     5      6
 * ROW3   7     8      9
 */

void keypad_init(void)
{
	clear_bit(Keypad_DDR,COL3); // make Keypad_Pin,5 input
	set_bit(Keypad_Port,COL3);  // Active pull up resistors
	clear_bit(Keypad_DDR,COL2); // make Keypad_Pin,6 input
	set_bit(Keypad_Port,COL2);  // Active pull up resistors
	clear_bit(Keypad_DDR,COL1); // make Keypad_Pin,4 input
	set_bit(Keypad_Port,COL1);  // Active pull up resistors
	set_bit(Keypad_DDR,ROW3); // make PORTA2 output
	set_bit(Keypad_DDR,ROW2); // make PORTA3 output
	set_bit(Keypad_DDR,ROW1); // make PORTA4 output
	set_bit(Keypad_Port,ROW3); // Deactive PORTA2 for the keypad
	set_bit(Keypad_Port,ROW2); // Deactive PORTA2 for the keypad
	set_bit(Keypad_Port,ROW1); // Deactive PORTA2 for the keypad
}

unsigned char keypad_scan(void)
{
	set_bit(Keypad_Port,ROW3);     // Deactive PORTA2 for the keypad
	clear_bit(Keypad_Port,ROW1); // active PORTA2 for the keypad
	set_bit(Keypad_Port,ROW2); 	// Deactive PORTA2 for the keypad


	if(read_pin(Keypad_Pin,COL3)==0)
	{
		_delay_ms(50);
		return 3;

	}
	else if(read_pin(Keypad_Pin,COL2)==0)
	{
		_delay_ms(50);
		return 2;


	}
	else if(read_pin(Keypad_Pin,COL1)==0)
	{
		_delay_ms(50);
		return 1;

	}

	set_bit(Keypad_Port,ROW1); // active PORTA2 for the keypad
	clear_bit(Keypad_Port,ROW2); // Deactive PORTA2 for the keypad
	set_bit(Keypad_Port,ROW3); // Deactive PORTA2 for the keypad

	if(read_pin(Keypad_Pin,COL3)==0)
	{
		_delay_ms(50);
		return 6;

	}
	else if(read_pin(Keypad_Pin,COL2)==0)
	{
		_delay_ms(50);
		return 5;

	}
	else if(read_pin(Keypad_Pin,COL1)==0)
	{
		_delay_ms(50);
		return 4;

	}

	set_bit(Keypad_Port,ROW2); // Deactive PORTA2 for the keypad
	clear_bit(Keypad_Port,ROW3); // active PORTA2 for the keypad
	set_bit(Keypad_Port,ROW1); // Deactive PORTA2 for the keypad


	if(read_pin(Keypad_Pin,COL3)==0)
	{
		_delay_ms(50);
		return 9;

	}
	else if(read_pin(Keypad_Pin,COL2)==0)
	{
		_delay_ms(50);
		return 8;

	}
	else if(read_pin(Keypad_Pin,COL1)==0)
	{
		_delay_ms(50);
		return 7;

	}

	return 0;

}


