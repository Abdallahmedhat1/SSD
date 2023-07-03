/*
 * SSD_Interface.h
 *
 * Created: 7/2/2023 9:10:57 PM
 *  Author: Abdallah Medhat
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#include "DIO_INTERFACE.h"
#include "SSD_Private.h"


#define SSD_COMMON_CATHODE    0
#define SSD_COMMON_ANODE      1
   
    //Port Defines
#define SSD_PORTA             0
#define SSD_PORTB             1
#define SSD_PORTC             2
#define SSD_PORTD             3

	//Pin Defines 
#define  SSD_PIN0             0
#define  SSD_PIN0             1
#define  SSD_PIN0             2
#define  SSD_PIN0             3
#define  SSD_PIN0             4
#define  SSD_PIN0             5
#define  SSD_PIN0             6
#define  SSD_PIN0             7

typedef struct{
	
	u8 Type;
	u8 DataPort;
	u8 EnablePort;
	u8 EnablePin;
	
   }SSD_Type;
		
void SSD_Init(SSD_Type SSD_Configuration);
void SSD_Enable(SSD_Type SSD_Configuration);
void SSD_Disable(SSD_Type SSD_Configuration);
void SSD_SendNumber(SSD_Type SSD_Configuration,u8 Send_Number);	
	
	
	
	

#endif /* SSD_INTERFACE_H_ */