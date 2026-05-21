/*
File Name : lcd.h
Description :
Declares LCD interface functions.

Functions include:
- LCD initialization
- Sending commands
- Sending data
- Displaying strings and numbers
*/
#include"types.h"
void InitLCD(void);
void CmdLCD(u8);
void CharLCD(s8);
void StrLCD(s8 *);
void IntLCD(s32);
void F32LCD(f32,u32);
void display_med_time(void);
void display(void);
void display_med_fail(void);
void display_menu(void);
