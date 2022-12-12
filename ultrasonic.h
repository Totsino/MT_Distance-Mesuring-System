#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_



#include "std_types.h"

/* Macro definitions*/

#define TRIGGER_PIN   PIN5_ID /*defining Trigger Pin*/
#define TRIGGER_PORT  PORTB_ID /*defining Trigger Port*/

#define FACTOR 58.8 /* Time Factor */



/*******************************************************************************
 *                      Functions Prototypes                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize Ultrasonic
 * 1. Setup Trigger port as output
 * 2.Make a ConfigType Structure and Pass it to Icu_init Function
 * 3.Set up the call back function
 */
void Ultrasonic_init(void);

/*
 * Description :
 * UltraSonic Edge processing
 * 1.g_flag = 0 then clear timer value, Set edge detection to falling then set flag =1
 * 2.g_flag = 1 then save the ICR value at h_time variable , set edge detection ot rising,clear flag
 */
rasonic_edgeProcessing(void);

/*
 * Description :
 * Ultrasonic Read Distance
 * 1.Send Trigger
 * 2.Calculate distance and return it
 */
uint16 Ultrasonic_readDistance(void);

/*
 * Description :
 * Ultrasonic Trigger
 * 1.Send Trigger to the Trigger port
 */

void Ultrasonic_Trigger(void);

#endif /* ULTRASONIC_H_ */
