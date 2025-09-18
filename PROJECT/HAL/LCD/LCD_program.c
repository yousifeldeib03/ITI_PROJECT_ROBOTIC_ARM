
#include "STD_TYPE.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"
#include <util/delay.h>

void LCD_vidInit_8bits(void){
	DIO_voidSetPortDirection(DIO_u8_PORTD,0xFF);

	DIO_voidSetPinDirection(DIO_u8_PORTC, 0, DIO_u8_OUTPUT);
	// RS
	//DIO_voidSetPinDirection (DIO_u8_PORTC, 1, DIO_u8_OUTPUT);
	// RW
	DIO_voidSetPinDirection (DIO_u8_PORTC, 2, DIO_u8_OUTPUT);
	// EN

	// 2. Power-on delay (critical!)
	_delay_ms (40); // Extended delay for safety
	// 3. Triple initialization sequence
	LCD_vidSendCommand(0x30);
	_delay_ms (10);
	LCD_vidSendCommand(0x30);
	_delay_ms(1);
	LCD_vidSendCommand(0x30);
	_delay_us(150);
	LCD_vidSendCommand(0x38);
	_delay_us(50);

	LCD_vidSendCommand(0x08);
	_delay_us(50);
	LCD_vidSendCommand(0x01);
	_delay_ms(3);
	LCD_vidSendCommand(0x06);
	_delay_us(50);
	LCD_vidSendCommand(0x0c);
	_delay_us(50);
}

void LCD_vidSendCommand(u8 u8CmdCpy){
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_LOW);

	DIO_voidSetPortValue(LCD_DATA_PORT,u8CmdCpy);

	//enable
	DIO_voidSetPortDirection(LCD_CONTROL_PORT,DIO_u8_OUTPUT);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_LOW);

}
void LCD_vidWriteCharctr(u8 u8DataCpy){
	///8 Bits (D0->D7)////


	///RS -> 1 for Data////

	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_u8_HIGH);

	//RW PIN writing active LOW

	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_LOW); //pass command //D0->D7//

	DIO_voidSetPortValue (LCD_DATA_PORT, u8DataCpy);

	//EnaLCD vidWriteCharctrble

	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN, DIO_u8_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN, DIO_u8_LOW);
	_delay_us(50);
}

void LCD_vidGotoxy(u8 X, u8 Y)
{
	// Validate coordinates
	if (X < 16 && Y < 2)
	{
		// Calculate DDRAM address
		u8 address = (Y == 0) ? 128 + X : 192 + X;
		LCD_vidSendCommand(address);
	}
}

void LCD_Clear()
{
	 LCD_vidSendCommand(0x01);		/* Clear display */
	_delay_ms(2);
	 LCD_vidSendCommand(0x80);		/* Cursor at home position */
}
void LCD_vidWriteNumber_8bits(u16 Copy_u16Number)
{
    char buffer[10];
    u8 i = 0;

    // 1. Ã™â€žÃ™Ë† Ã˜Â§Ã™â€žÃ˜Â±Ã™â€šÃ™â€¦ Ã˜ÂµÃ™ï¿½Ã˜Â± Ã˜Â§Ã˜Â·Ã˜Â¨Ã˜Â¹Ã™â€¡ Ã™â€¦Ã˜Â¨Ã˜Â§Ã˜Â´Ã˜Â±Ã˜Â©
    if (Copy_u16Number == 0)
    {
    	LCD_vidWriteCharctr('0');
        return;
    }

    // 2. Ã˜Â­Ã™Ë†Ã™â€˜Ã™â€ž Ã˜Â§Ã™â€žÃ˜Â±Ã™â€šÃ™â€¦ Ã™â€žÃ™â‚¬ chars (Ã˜Â¹Ã™Æ’Ã˜Â³Ã™Å )
    while (Copy_u16Number > 0)
    {
        buffer[i] = (Copy_u16Number % 10) + '0';
        Copy_u16Number /= 10;
        i++;
    }

    // 3. Ã˜Â§Ã˜Â·Ã˜Â¨Ã˜Â¹ Ã˜Â§Ã™â€žÃ˜Â£Ã˜Â±Ã™â€šÃ˜Â§Ã™â€¦ Ã˜Â¨Ã˜Â§Ã™â€žÃ˜ÂªÃ˜Â±Ã˜ÂªÃ™Å Ã˜Â¨ Ã˜Â§Ã™â€žÃ˜ÂµÃ˜Â­Ã™Å Ã˜Â­
    while (i > 0)
    {
        i--;
        LCD_vidWriteCharctr(buffer[i]);
    }
}

void LCD_Command( unsigned char cmnd )
	{
	    PORTC &= ~(1<<RS);    /* RS=0, command reg */
	    PORTC &= ~(1<<1);     /* RW=0, write */

	    // إرسال النبضة العليا على PD0–PD3
	    LCD_Port = (LCD_Port & 0xF0) | ((cmnd >> 4) & 0x0F);

	    PORTC |= (1<<EN);
	    _delay_us(1);
	    PORTC &= ~(1<<EN);
	    _delay_us(200);

	    // إرسال النبضة السفلى على PD0–PD3
	    LCD_Port = (LCD_Port & 0xF0) | (cmnd & 0x0F);

	    PORTC |= (1<<EN);
	    _delay_us(1);
	    PORTC &= ~(1<<EN);
	    _delay_ms(2);
	}
/////////////////////////////////////////
 // 4-bit LCD
void LCD_4_bit_vidGotoxy(u8 X, u8 Y)
{
	// Validate coordinates
	if (X < 16 && Y < 2)
	{
		// Calculate DDRAM address
		u8 address = (Y == 0) ? 128 + X : 192 + X;
		LCD_Command(address);
	}
}
 void LCD_Char( char data )
 {
     PORTC |= (1<<RS);     /* RS=1, data reg */
     PORTC &= ~(1<<1);     /* RW=0, write */

     // إرسال النبضة العليا على PD0–PD3
     LCD_Port = (LCD_Port & 0xF0) | ((data >> 4) & 0x0F);

     PORTC |= (1<<EN);
     _delay_us(1);
     PORTC &= ~(1<<EN);
     _delay_us(200);

     // إرسال النبضة السفلى على PD0–PD3
     LCD_Port = (LCD_Port & 0xF0) | (data & 0x0F);

     PORTC |= (1<<EN);
     _delay_us(1);
     PORTC &= ~(1<<EN);
     _delay_ms(2);
 }
 void LCD_Init (void)			/* LCD Initialize function */
 {

 	// Ã˜ÂªÃ™â€¡Ã™Å Ã˜Â¦Ã˜Â© Ã˜Â¯Ã˜Â¨Ã˜Â§Ã˜Â¨Ã™Å Ã˜Â³ Ã˜Â§Ã™â€žÃ˜ÂªÃ˜Â­Ã™Æ’Ã™â€¦
 	DIO_voidSetPinDirection(DIO_u8_PORTC, 0, DIO_u8_OUTPUT); // RS
 	DIO_voidSetPinDirection(DIO_u8_PORTC, 1, DIO_u8_OUTPUT); // RW
 	DIO_voidSetPinDirection(DIO_u8_PORTC, 2, DIO_u8_OUTPUT); // E

 	// Ã˜ÂªÃ™â€¡Ã™Å Ã˜Â¦Ã˜Â© Ã˜Â¯Ã˜Â¨Ã˜Â§Ã˜Â¨Ã™Å Ã˜Â³ Ã˜Â§Ã™â€žÃ˜Â¨Ã™Å Ã˜Â§Ã™â€ Ã˜Â§Ã˜Âª (D4-D7 Ã™ï¿½Ã™â€šÃ˜Â· Ã™ï¿½Ã™Å  Ã™Ë†Ã˜Â¶Ã˜Â¹ 4-bit)
 	DIO_voidSetPinDirection(DIO_u8_PORTD, 0, DIO_u8_OUTPUT); // D4
 	DIO_voidSetPinDirection(DIO_u8_PORTD, 1, DIO_u8_OUTPUT); // D5
 	DIO_voidSetPinDirection(DIO_u8_PORTD, 2, DIO_u8_OUTPUT); // D6
 	DIO_voidSetPinDirection(DIO_u8_PORTD, 3, DIO_u8_OUTPUT); // D7

 	_delay_ms(50); // Ã˜ÂªÃ˜Â£Ã˜Â®Ã™Å Ã˜Â± Ã˜Â¨Ã˜Â¯Ã˜Â¡ Ã˜Â§Ã™â€žÃ˜ÂªÃ˜Â´Ã˜ÂºÃ™Å Ã™â€ž

 	// Ã˜ÂªÃ˜Â³Ã™â€žÃ˜Â³Ã™â€ž Ã˜ÂªÃ™â€¡Ã™Å Ã˜Â¦Ã˜Â© 4-bit Ã˜Â§Ã™â€žÃ˜ÂµÃ˜Â­Ã™Å Ã˜Â­
 	LCD_Command(0x33);
 	LCD_Command(0x33);// Ã˜ÂªÃ™â€¡Ã™Å Ã˜Â¦Ã˜Â© Ã˜Â£Ã™Ë†Ã™â€žÃ™Å Ã˜Â©
 	LCD_Command(0x32); // Ã˜ÂªÃ™â€¡Ã™Å Ã˜Â¦Ã˜Â© Ã˜Â£Ã™Ë†Ã™â€žÃ™Å Ã˜Â©
 	LCD_Command(0x28); // Ã™Ë†Ã˜Â¶Ã˜Â¹ 4-bitÃ˜Å’ 2 Ã˜Â³Ã˜Â·Ã˜Â±Ã˜Å’ Ã™â€¦Ã˜ÂµÃ™ï¿½Ã™Ë†Ã™ï¿½Ã˜Â© 5x7
 	LCD_Command(0x0C);// Ã˜ÂªÃ˜Â´Ã˜ÂºÃ™Å Ã™â€ž Ã˜Â§Ã™â€žÃ˜Â¹Ã˜Â±Ã˜Â¶Ã˜Å’ Ã˜Â¥Ã™Å Ã™â€šÃ˜Â§Ã™ï¿½ Ã˜Â§Ã™â€žÃ™â€¦Ã˜Â¤Ã˜Â´Ã˜Â±
 	LCD_Command(0x06); // Ã˜Â²Ã™Å Ã˜Â§Ã˜Â¯Ã˜Â© Ã˜Â§Ã™â€žÃ™â€¦Ã˜Â¤Ã˜Â´Ã˜Â±
 	LCD_Command(0x01); // Ã™â€¦Ã˜Â³Ã˜Â­ Ã˜Â§Ã™â€žÃ˜Â´Ã˜Â§Ã˜Â´Ã˜Â©
 	_delay_ms(2);

 }


 void LCD_svoidSendString(char *ARG_charptr)
 {
     u8 i = 0;

     if (ARG_charptr == 0)
     {
         // Do nothing if the pointer is NULL
     }
     else
     {
         // Loop through the string until null terminator '\0'
         while (ARG_charptr[i] != '\0')
         {
             LCD_Char(ARG_charptr[i]); // Send each character
             i++;
         }
     }
 }

