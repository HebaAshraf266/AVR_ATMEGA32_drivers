/*
 * LCD_src.c
 *
 *  Created on: Jan 7, 2023
 *      Author: user
 */
#include "../../SERV/STD_Types.h"
#include "../../SERV/BitMath.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "LCD_conf.h"
#include "LCD_private.h"
#include"util/delay.h"

#define LCD_DSP_CURSOR_SHIFT_LEFT           0b00011000
#define LCD_DSP_CURSOR_SHIFT_RIGHT          0b00011100

static void LCD_SendEnablePulse (){

	DIO_u8SetPinVal(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	DIO_u8SetPinVal(LCD_EN_PORT,LCD_EN_PIN,LOW);
}

static void LCD_u8SendData (uint8 u8DataCopy){

	#if LCD_DB_8WIRES == 1
		DIO_u8SetPinVal( LCD_D0_PORT , LCD_D0_PIN , GET_BIT ( u8DataCopy,0 ) );
		DIO_u8SetPinVal( LCD_D1_PORT , LCD_D1_PIN , GET_BIT ( u8DataCopy,1 ) );
		DIO_u8SetPinVal( LCD_D2_PORT , LCD_D2_PIN , GET_BIT ( u8DataCopy,2 ) );
		DIO_u8SetPinVal( LCD_D3_PORT , LCD_D3_PIN , GET_BIT ( u8DataCopy,3 ) );
		DIO_u8SetPinVal( LCD_D4_PORT , LCD_D4_PIN , GET_BIT ( u8DataCopy,4 ) );
		DIO_u8SetPinVal( LCD_D5_PORT , LCD_D5_PIN , GET_BIT ( u8DataCopy,5 ) );
		DIO_u8SetPinVal( LCD_D6_PORT , LCD_D6_PIN , GET_BIT ( u8DataCopy,6 ) );
		DIO_u8SetPinVal( LCD_D7_PORT , LCD_D7_PIN , GET_BIT ( u8DataCopy,7 ) );

		LCD_SendEnablePulse();

	#elif  LCD_DB_8WIRES == 0
		DIO_u8SetPinVal( LCD_D4_PORT , LCD_D4_PIN , GET_BIT ( u8DataCopy,4 ) );
		DIO_u8SetPinVal( LCD_D5_PORT , LCD_D5_PIN , GET_BIT ( u8DataCopy,5 ) );
		DIO_u8SetPinVal( LCD_D6_PORT , LCD_D6_PIN , GET_BIT ( u8DataCopy,6 ) );
		DIO_u8SetPinVal( LCD_D7_PORT , LCD_D7_PIN , GET_BIT ( u8DataCopy,7 ) );

		LCD_SendEnablePulse();

		DIO_u8SetPinVal( LCD_D0_PORT , LCD_D0_PIN , GET_BIT ( u8DataCopy,0 ) );
		DIO_u8SetPinVal( LCD_D1_PORT , LCD_D1_PIN , GET_BIT ( u8DataCopy,1 ) );
		DIO_u8SetPinVal( LCD_D2_PORT , LCD_D2_PIN , GET_BIT ( u8DataCopy,2 ) );
		DIO_u8SetPinVal( LCD_D3_PORT , LCD_D3_PIN , GET_BIT ( u8DataCopy,3 ) );

		LCD_SendEnablePulse();

	#endif
}

void LCD_vidSendCommand (uint8 u8CmdCodeCopy){

	//Write Command
	DIO_u8SetPinVal(LCD_RS_PORT,LCD_RS_PIN,LOW);
	DIO_u8SetPinVal(LCD_RW_PORT,LCD_RW_PIN,LOW);

	LCD_u8SendData(u8CmdCodeCopy);
}


void LCD_u8WriteChar(uint8 u8CharCopy){

	//Write Data
	DIO_u8SetPinVal(LCD_RS_PORT , LCD_RS_PIN , HIGH);
	DIO_u8SetPinVal(LCD_RW_PORT,LCD_RW_PIN,LOW);

	LCD_u8SendData (u8CharCopy);
}


void LCD_vidinit(){

	DIO_u8SetPinDir ( LCD_D0_PORT , LCD_D0_PIN , OUTPUT );
	DIO_u8SetPinDir ( LCD_D1_PORT , LCD_D1_PIN , OUTPUT );
	DIO_u8SetPinDir ( LCD_D2_PORT , LCD_D2_PIN , OUTPUT );
	DIO_u8SetPinDir ( LCD_D3_PORT , LCD_D3_PIN , OUTPUT );
	DIO_u8SetPinDir ( LCD_D4_PORT , LCD_D4_PIN , OUTPUT );
	DIO_u8SetPinDir ( LCD_D5_PORT , LCD_D5_PIN , OUTPUT );
	DIO_u8SetPinDir ( LCD_D6_PORT , LCD_D6_PIN , OUTPUT );
	DIO_u8SetPinDir ( LCD_D7_PORT , LCD_D7_PIN , OUTPUT );

	DIO_u8SetPinDir ( LCD_RS_PORT , LCD_RS_PIN , OUTPUT );
	DIO_u8SetPinDir ( LCD_RW_PORT , LCD_RW_PIN , OUTPUT );
	DIO_u8SetPinDir ( LCD_EN_PORT , LCD_EN_PIN , OUTPUT );

	_delay_ms(50);

   #if LCD_DB_8WIRES==0
		DIO_u8SetPinVal( LCD_D4_PORT , LCD_D4_PIN , 0);
		DIO_u8SetPinVal( LCD_D5_PORT , LCD_D5_PIN , 1);
		DIO_u8SetPinVal( LCD_D6_PORT , LCD_D6_PIN , 0);
		DIO_u8SetPinVal( LCD_D7_PORT , LCD_D7_PIN , 0);

		LCD_SendEnablePulse();
	#endif

	#if LCD_DB_8WIRES==0 && LCD_DL_2LINES==0 && LCD_FONT_5x10==0
		LCD_vidSendCommand (DB4_WIRES_DL_1LINES_FONT_5x7_INSTUCTION);

	#elif LCD_DB_8WIRES==0 && LCD_DL_2LINES==0 && LCD_FONT_5x10==1
		LCD_vidSendCommand (DB4_WIRES_DL_1LINES_FONT_5x10_INSTUCTION);

	#elif LCD_DB_8WIRES==0 && LCD_DL_2LINES==1 && LCD_FONT_5x10==0
		LCD_vidSendCommand (DB4_WIRES_DL_2LINES_FONT_5x7_INSTUCTION);

	#elif LCD_DB_8WIRES==0 && LCD_DL_2LINES==1 && LCD_FONT_5x10==1
		LCD_vidSendCommand (DB4_WIRES_DL_2LINES_FONT_5x10_INSTUCTION);

	#elif LCD_DB_8WIRES==1 && LCD_DL_2LINES==0 && LCD_FONT_5x10==0
		LCD_vidSendCommand (DB8_WIRES_DL_1LINES_FONT_5x7_INSTUCTION);

	#elif LCD_DB_8WIRES==1 && LCD_DL_2LINES==0 && LCD_FONT_5x10==1
		LCD_vidSendCommand (DB8_WIRES_DL_1LINES_FONT_5x10_INSTUCTION);

	//
	#elif LCD_DB_8WIRES==1 && LCD_DL_2LINES==1 && LCD_FONT_5x10==0
		LCD_vidSendCommand (DB8_WIRES_DL_2LINES_FONT_5x7_INSTUCTION);

	#elif LCD_DB_8WIRES==1 && LCD_DL_2LINES==1 && LCD_FONT_5x10==1
		LCD_vidSendCommand (DB8_WIRES_DL_2LINES_FONT_5x10_INSTUCTION);

	#endif

	_delay_us(50);

	#if LCD_DISPLAY_ON==0
		LCD_vidSendCommand(DOFF_COFF_BOFF_INSTRUCTION);

    #elif LCD_DISPLAY_ON==1 && LCD_CURSOR_ON==0 && LCD_BLINK_ON==0
		LCD_vidSendCommand(DON_COFF_BOFF_INSTRUCTION);

	#elif LCD_DISPLAY_ON==1 && LCD_CURSOR_ON==0 && LCD_BLINK_ON==1
		LCD_vidSendCommand(DON_COFF_BON_INSTRUCTION);

    #elif LCD_DISPLAY_ON==1 && LCD_CURSOR_ON==1 && LCD_BLINK_ON==0
		LCD_vidSendCommand(DON_CON_BOFF_INSTRUCTION);

	#elif LCD_DISPLAY_ON==1 && LCD_CURSOR_ON==1 && LCD_BLINK_ON==1
		LCD_vidSendCommand(DON_CON_BON_INSTRUCTION);

    #endif

	_delay_us(50);

	LCD_vidSendCommand(CLEAR_DISPLAY_INSTRUCTION);

	_delay_ms(3);

	#if LCD_ENTRY_MODE_AUTO_INC==0 && LCD_ENTRY_MODE_AUTO_SHIFT==0
		LCD_vidSendCommand (ENRTY_MODE_AUTODEC_INSTRUCTION);

	#elif LCD_ENTRY_MODE_AUTO_INC==0 && LCD_ENTRY_MODE_AUTO_SHIFT==1
		LCD_vidSendCommand (ENRTY_MODE_AUTODEC_DFLEFT_INSTRUCTION);

	#elif LCD_ENTRY_MODE_AUTO_INC==1 && LCD_ENTRY_MODE_AUTO_SHIFT==0
		LCD_vidSendCommand (ENRTY_MODE_AUTOINC_INSTRUCTION );

	#elif LCD_ENTRY_MODE_AUTO_INC==1 && LCD_ENTRY_MODE_AUTO_SHIFT==1
		LCD_vidSendCommand (ENRTY_MODE_AUTOINC_DFLEFT_INSTRUCTION);

	#endif
}


void LCD_vidClearDisply(){

	LCD_vidSendCommand ( CLEAR_DISPLAY_INSTRUCTION );
}

void LCD_vidReturnHome(){

	LCD_vidSendCommand ( RETURN_HOME_INSTRUCTION );
}

void LCD_vidCutomCharcter(uint8 *u8CharPatternCopy,uint8 u8CharAddress){

	uint8 i;
	LCD_vidSendCommand(ENRTY_MODE_AUTOINC_INSTRUCTION);
	LCD_vidSendCommand(POINT_AT_CGRAM_INSTRUCTION +  (u8CharAddress*8) );

	for (i=0; i<8; i++){
		LCD_u8WriteChar(u8CharPatternCopy[i]);
	}

}

void LCD_vidSetEntryMode (uint8 u8LcdEntyModeCopy) {

	switch (u8LcdEntyModeCopy){
		case 0: LCD_vidSendCommand(ENRTY_MODE_AUTODEC_INSTRUCTION);          break;
		case 1: LCD_vidSendCommand(ENRTY_MODE_AUTODEC_DFLEFT_INSTRUCTION);   break;
		case 2: LCD_vidSendCommand(ENRTY_MODE_AUTOINC_INSTRUCTION);          break;
		case 3: LCD_vidSendCommand(ENRTY_MODE_AUTOINC_DFRIGHT_INSTRUCTION);  break;
	}
	//LCD_vidSendCommand(ENRTY_MODE_AUTODEC_DFRIGHT_INSTRUCTION + u8LcdEntyModeCopy);
}


void LCD_vidGoToXY(uint8 u8RowIdCopy,uint8 u8ColumnIdCopy){

	if (1==u8RowIdCopy){
		//User will start from 1 to 16
		LCD_vidSendCommand( POINT_AT_DDRAM_1ST_LINE_INSTRUCTION + u8ColumnIdCopy-1);
	}
	else{
		LCD_vidSendCommand( POINT_AT_DDRAM_2ND_LINE_INSTRUCTION + u8ColumnIdCopy-1);
	}
}

void LCD_vidRightShiftWritingPosistion (){
	LCD_vidSendCommand(ADDRESS_COUNTER_DECREAMENT_INSTRUCTION);
}

void LCD_vidLeftShiftWritingPosistion (){
	LCD_vidSendCommand(ADDRESS_COUNTER_INCREAMENT_INSTRUCTION);
}

void LCD_vidDisplayFrameLeftShift(){
	LCD_vidSendCommand(DISPLAY_FRAME_LEFT_SHIFT_INSTRUCTION);
}

void LCD_vidDisplayFrameRightShift(){
	LCD_vidSendCommand(DISPLAY_FRAME_RIGHT_SHIFT_INSTRUCTION);
}


void LCD_vidSendString(uint8 *u8StringCopy){

	uint16 i=0;
	while(u8StringCopy[i]!='\0')                   //the loop will done until the value is null

		if (i==16)                                 //chick if the first line in LCD is full
		 {
			LCD_vidSendCommand(0b11000000);        //start write on second line
	 	 }

		LCD_u8WriteChar(u8StringCopy[i]);
	     i++;
	 }
}


void LCD_vidSendInteger(uint16 number)
 {
	 uint16 copy, lenght=0 , arr[5]={0} ;
	 uint8 asky[10] = {'0','1','2','3','4','5','6','7','8','9'} ;
	 sint8 i;
	 copy=number;
	 while(copy != 0)
	 {
		 lenght++;
		 copy/=10;
	 }
	 for(i=0;i<lenght;i++)
	 {
		 arr[i] = number % 10;
		 number/=10;
	 }
	 for(i=lenght-1;i>=0;i--)
	 {
		 LCD_u8WriteChar(asky[arr[i]]);
	 }
 }

void LCD_vidShiftLeft(void){
	LCD_vidSendCommand(LCD_DSP_CURSOR_SHIFT_RIGHT);

}

void LCD_vidShiftRight(void){
	LCD_vidSendCommand(LCD_DSP_CURSOR_SHIFT_RIGHT);
}
