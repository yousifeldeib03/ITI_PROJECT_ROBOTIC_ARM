#include "STD_TYPE.h"
#include "Bit_Math.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "DIO_register.h"


void DIO_voidSetPortDirection(u8 u8PortId, u8 u8PortDir){
		switch(u8PortId)
		{
		case DIO_u8_PORTA:DDRA=u8PortDir; break;
		case DIO_u8_PORTB:DDRB=u8PortDir; break;
		case DIO_u8_PORTC:DDRC=u8PortDir; break;
		case DIO_u8_PORTD:DDRD=u8PortDir; break;
		}


}
void DIO_voidSetPortValue(u8 u8PortId, u8 u8PortVal)
{
	switch(u8PortId)
	{
	case DIO_u8_PORTA:PORTA=u8PortVal; break;
	case DIO_u8_PORTB:PORTB=u8PortVal; break;
	case DIO_u8_PORTC:PORTC=u8PortVal; break;
	case DIO_u8_PORTD:PORTD=u8PortVal; break;
	}

}
void DIO_voidSetPinDirection(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy){
	if(u8PinDirCopy){
		switch(u8PortIdCopy){
		case DIO_u8_PORTA:SET_BIT(DDRA,u8PinIdCopy); break;
		case DIO_u8_PORTB:SET_BIT(DDRB,u8PinIdCopy); break;
		case DIO_u8_PORTC:SET_BIT(DDRC,u8PinIdCopy); break;
		case DIO_u8_PORTD:SET_BIT(DDRD,u8PinIdCopy); break;
		}
	}
	else{
		switch(u8PortIdCopy){
		case DIO_u8_PORTA:CLR_BIT(DDRA,u8PinIdCopy); break;
		case DIO_u8_PORTB:CLR_BIT(DDRB,u8PinIdCopy); break;
		case DIO_u8_PORTC:CLR_BIT(DDRC,u8PinIdCopy); break;
		case DIO_u8_PORTD:CLR_BIT(DDRD,u8PinIdCopy); break;

		}
	}

}





u8  DIO_u8GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy){
	u8 pin_value=0;

	switch(u8PortIdCopy)
	{
	case DIO_u8_PORTA:pin_value = GET_BIT(PINA,u8PinIdCopy);

	break;

	case DIO_u8_PORTB:pin_value = GET_BIT(PINB,u8PinIdCopy);

	break;

	case DIO_u8_PORTC:pin_value = GET_BIT(PINC,u8PinIdCopy);

	break;

	case DIO_u8_PORTD:pin_value = GET_BIT(PIND,u8PinIdCopy);

	break;
	default: break;
	}
	return pin_value;
}



void DIO_voidSetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy){
	if(u8PinValCopy == DIO_u8_HIGH)
		{

			switch(u8PortIdCopy){
				case DIO_u8_PORTA : SET_BIT(PORTA , u8PinIdCopy); break;
				case DIO_u8_PORTB : SET_BIT(PORTB , u8PinIdCopy); break;
				case DIO_u8_PORTC : SET_BIT(PORTC , u8PinIdCopy); break;
				case DIO_u8_PORTD : SET_BIT(PORTD , u8PinIdCopy); break;
			}
		}else{
			switch(u8PortIdCopy){
				case DIO_u8_PORTA : CLR_BIT(PORTA , u8PinIdCopy); break;
				case DIO_u8_PORTB : CLR_BIT(PORTB , u8PinIdCopy); break;
				case DIO_u8_PORTC : CLR_BIT(PORTC , u8PinIdCopy); break;
				case DIO_u8_PORTD : CLR_BIT(PORTD , u8PinIdCopy); break;
			}

		}
}


void DIO_voidTogglePinValue(u8 u8PortIdCopy, u8 u8PinIdCopy)
{
    switch(u8PortIdCopy)
    {
        case DIO_u8_PORTA: TOG_BIT(PORTA , u8PinIdCopy); break;
        case DIO_u8_PORTB: TOG_BIT(PORTB , u8PinIdCopy); break;
        case DIO_u8_PORTC: TOG_BIT(PORTC , u8PinIdCopy); break;
        case DIO_u8_PORTD: TOG_BIT(PORTD , u8PinIdCopy); break;
    }
}

