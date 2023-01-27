#include "../SERV/STD_Types.h"
#include "../SERV/BitMath.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LED_Buzzer/LEDsBuzzer_int.h"


void main(void)
{
	LEDsBuzzer_vidInit(LED1);
	LEDsBuzzer_u8TurnOff(LED1);
	LEDsBuzzer_vidInit(LED2);
	LEDsBuzzer_u8TurnOff(LED2);

	while(1)
	{
		LEDsBuzzer_u8ToggleState(LED1);
		LEDsBuzzer_u8TurnON(LED2);
		_delay_ms(500);
		LEDsBuzzer_u8TurnOff(LED2);
		_delay_ms(500);
    }

}
