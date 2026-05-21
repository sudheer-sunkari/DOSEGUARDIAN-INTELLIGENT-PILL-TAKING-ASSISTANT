/*
File Name : delay.c
Description :
Implements software delay routines.

These functions generate delays using empty loops and are
used for LCD timing, buzzer timing, and user interaction delays.
*/
#include"types.h"
void delay_us(u32 tdly)
{
	tdly*=12;
	while(tdly--);
}
void delay_ms(u32 tdly)
{
	tdly*=12000;
	while(tdly--);
}
void delay_s(u32 tdly)
{
	tdly*=12000000;
	while(tdly--);
}
