/*
 * LEDsBuzzer_int.h
 *
 *  Created on: Dec 31, 2022
 *      Author: user
 */

#ifndef HAL_LED_BUZZER_LEDSBUZZER_INT_H_
#define HAL_LED_BUZZER_LEDSBUZZER_INT_H_

#define LED1  0
#define LED2  1
#define LED3  2
#define LED4  3
#define LED5  4
#define LED6  5
#define LED7  6
#define LED8  7


/*
 * Function  : LED initialization
 * Parameter : LEDId
 * Return    : void
 */
void LEDsBuzzer_vidInit (uint8 u8LEDIdCopy);

/*
 * Function  : Set LED ON
 * Parameter : LEDId
 * Return    : Error state
 */
uint8 LEDsBuzzer_u8TurnON (uint8 u8LEDIdCopy);


/*
 * Function  : Set LED OFF
 * Parameter : LEDId
 * Return    : Error state
 */
uint8 LEDsBuzzer_u8TurnOff  (uint8 u8LEDIdCopy);

/*
 * Function  : Toggle LED
 * Parameter : LEDId
 * Return    : Error state
 */
uint8 LEDsBuzzer_u8ToggleState (uint8 u8LEDIdCopy);

/*
 * Function  : Represent binary numbers on led
 * Parameter : Number
 * Return    : void
 */

void LEDsBuzzer_u8WriteBinary( uint8 u8NumberCopy);
#endif /* HAL_LED_BUZZER_LEDSBUZZER_INT_H_ */
