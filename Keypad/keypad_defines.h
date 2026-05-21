/*
File Name : keypad_defines.h
Description :
Contains row and column pin definitions for the matrix keypad.

Used by keypad driver to scan and detect key presses.
*/
char LUT[][4]={ '1','2','3','/',
                '4','5','6','*',
	              '7','8','9','-',
	              '%','0','#','+'};
#define R0 16
#define R1 17
#define R2 18
#define R3 19
#define C0 20
#define C1 21
#define C2 22
#define C3 23
