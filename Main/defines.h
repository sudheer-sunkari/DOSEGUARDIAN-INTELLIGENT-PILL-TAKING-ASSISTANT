/*
File Name : defines.h
Description :
Contains common macro definitions used throughout the project.

Includes:
- Bit manipulation macros
- Register access macros
- Utility macros

Purpose:
To avoid magic numbers and improve maintainability.
*/
#define SETBIT(WORD,BP) WORD|=(1<<BP)
#define CLRBIT(WORD,BP) WORD&=~(1<<BP)
#define CPLBIT(WORD,BP) WORD^=(1<<BP)
#define WRITEBIT(WORD,BP,BIT) WORD=((WORD&~(1<<BP))|(BIT<<BP))
#define WRITENIBBLE(WORD,SBP,NIBBLE) WORD=((WORD&~(0xf<<SBP))|(NIBBLE<<SBP))
#define WRITEBYTE(WORD,SBP,BYTE) WORD=((WORD&~(0xff<<SBP))|(BYTE<<SBP))
#define WRITEHWORD(WORD,SBP,HWORD) WORD=((WORD&~(0xffff<<SBP))|(HWORD<<SBP))
