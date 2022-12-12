/*
 * ultrasonic.c
 *
 *  Created on: Oct 19, 2021
 *      Author: Youssef
 */








#include "icu.h"
#include "std_types.h"
#include "gpio.h"
#include "avr/io.h"
#include <util/delay.h>
#include "ultrasonic.h"


/*******************************************************************************
 *                            Global Variables                                 *
 *******************************************************************************/
uint8 g_flag=0;
uint16 h_time=0;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * UltraSonic Edge processing
 * 1.g_flag = 0 then clear timer value, Set edge detection to falling then set flag =1
 * 2.g_flag = 1 then save the ICR value at h_time variable , set edge detection ot rising,clear flag
 */

void Ultrasonic_edgeProcessing(void){

	if (g_flag==0){
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType(FALLING);
		g_flag=1;
	}
	else if (g_flag==1){

		h_time = Icu_getInputCaptureValue();
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType(RISING);
		g_flag=0;

	}

}

/*
 * Description :
 * Initialize Ultrasonic
 * 1. Setup Trigger port as output
 * 2.Make a ConfigType Structure and Pass it to Icu_init Function
 * 3.Set up the call back function
 */


void Ultrasonic_init(void){

	GPIO_setupPinDirection(TRIGGER_PORT, TRIGGER_PIN , PIN_OUTPUT);

	Icu_ConfigType config1 ={F_CPU_8,RISING};

	Icu_init(&config1);

	Icu_setCallBack(Ultrasonic_edgeProcessing);




}




/*
 * Description :
 * Ultrasonic Read Distance
 * 1.Send Trigger
 * 2.Calculate distance and return it
 */

uint16 Ultrasonic_readDistance(void){
	Ultrasonic_Trigger();

	uint16 distance=0;

	distance = (h_time/FACTOR);
	return distance;

}

/*
 * Description :
 * Ultrasonic Trigger
 * 1.Send Trigger to the Trigger port
 */

void Ultrasonic_Trigger(void){

	 GPIO_writePin(PORTB_ID, PIN5_ID , LOGIC_HIGH);
	 _delay_us(10);
	 GPIO_writePin(PORTB_ID, PIN5_ID , LOGIC_LOW);

}
