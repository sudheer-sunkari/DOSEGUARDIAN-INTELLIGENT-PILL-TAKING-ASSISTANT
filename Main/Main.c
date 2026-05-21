/*
File Name : Main.c
Description :
Main application file of the Medicine Reminder System.

Responsibilities:
- System initialization
- RTC time comparison
- Triggering buzzer and LED alerts
- Handling user acknowledgment
- Displaying status messages on LCD

This file integrates all peripheral modules.
*/
#include <LPC21xx.h>
#include "defines.h"
#include "lcd.h"
#include "lcd_defines.h"
#include "keypad.h"
#include "rtc.h"
#include "delay.h"
#include "Time_edit.h"
#include "pin_defines.h"
s32 CHECK_HOUR=10,CHECK_MIN,CHECK_SEC;
s32 hour,min,sec,date,month,year,day;
int main()
{
	u8 choice;
	IODIR0|=3<<LED;
	RTC_Init();
	InitLCD();
	KeypadInit();
	while(1)
	{
		  display();
			if((((IOPIN0>>SW1)&1)==0))
				{
					  display_menu();
						WRITENIBBLE(IOPIN1,16,0);
						while(ColStat());
            choice=ReadKeyVal();
   					switch(choice)
						{
								case '1':CmdLCD(CLEAR_LCD);
									       edit_RTC();
												  break;
								case '2':CmdLCD(CLEAR_LCD);
									       edit_MED(&CHECK_HOUR,&CHECK_MIN,&CHECK_SEC);
												 break;
								case '3': CmdLCD(CLEAR_LCD);
													break;
							  default:CmdLCD(CLEAR_LCD);
												StrLCD("WRONG INPUT");
							          delay_s(30);
									      CmdLCD(CLEAR_LCD);
						}
					}
/* 
	 Medicine reminder core logic
	 This block checks medicine time, alerts the user,
	 waits for acknowledgment, and handles failure.
*/
	if ((hour == CHECK_HOUR) && (min == CHECK_MIN) && (sec <= CHECK_SEC))
	{
			u32 wait_time = 0;
			u8 medicine_taken = 0;
			/* Step 1: Notify user */
			display_med_time();
			/* Step 2: Turn ON buzzer */
			SETBIT(IOSET0, BUZZER);
			/* Step 3: Wait up to 30 seconds for user response */
			while (wait_time < 30)
			{
					/* Check if SW2 is pressed (active low) */
					if (((IOPIN0 >> SW2) & 1) == 0)
					{
							medicine_taken = 1;
							break;
					}
					delay_s(1);
					wait_time++;
			}
			/* Step 4: Stop buzzer */
			SETBIT(IOCLR0, BUZZER);
			/* Step 5: Handle user response */
			if (medicine_taken)
			{
					CmdLCD(CLEAR_LCD);
					CmdLCD(GOTO_LINE1_POS0);
					StrLCD("MEDICINE TAKEN");
					delay_s(1);
			}
			else
			{
					/* User failed to take medicine */
					SETBIT(IOSET0, LED);
					display_med_fail();
					/* Wait until user finally presses SW2 */
					while (((IOPIN0 >> SW2) & 1) != 0);
					SETBIT(IOCLR0, LED);
			}
			/* Step 6: Clear display and return to normal mode */
			CmdLCD(CLEAR_LCD);
		}
	}
}
