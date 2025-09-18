#include "STD_TYPE.h"
#include "Bit_Math.h"
#include "GIE_Register.h"
#include "GIE_interface.h"



void Global_Interrupt_Enable(void){

	SET_BIT(SREG,7);
}

void Global_Interrupt_Disable(void){

	SREG &=~(1<<7);
}

