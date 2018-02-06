/*
 * my_keypad.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ascom
 */

#ifndef MY_KEYPAD_H_
#define MY_KEYPAD_H_

#define set_bit(reg,pin) reg|=(1<<pin)
#define clear_bit(reg,pin) reg&=~(1<<pin)
#define read_pin(reg,pin) (reg&(1<<pin))

#define Keypad_Port PORTA
#define Keypad_DDR  DDRA
#define Keypad_Pin  PINA
#define ROW1        4
#define ROW2        3
#define ROW3        2
#define COL1        7
#define COL2        6
#define COL3        5

void keypad_init(void);
unsigned char keypad_scan(void);

#endif /* MY_KEYPAD_H_ */
