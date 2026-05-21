/*
File Name : keypad.h
Description :
Declares keypad interface functions.

Functions include:
- Keypad initialization
- Key press detection
- Returning pressed key value
*/
void KeypadInit(void);
int ColStat(void);
char ReadKeyVal(void);
