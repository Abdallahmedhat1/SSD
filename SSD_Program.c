/*
 * SSD_Program.c
 *
 * Created: 7/2/2023 9:11:28 PM
 *  Author: Abdallah Medhat
 */ 
#include "SSD_Interface.h"

u8 Local_SSDNumbers[10]=SSD_NUMBER_ARR;
void SSD_Init(SSD_Type SSD_Configuration)
{
	Dio_SetPortDirection(SSD_Configuration.DataPort,0xff);
}
void SSD_Enable(SSD_Type SSD_Configuration)
{
	if(SSD_Configuration.Type==SSD_COMMON_CATHODE)
	{
		Dio_SetPinDirection(SSD_Configuration.EnablePort,SSD_Configuration.EnablePin,DIO_PIN_OUTPUT);
		Dio_SetPinValue(SSD_Configuration.EnablePort,SSD_Configuration.EnablePin,DIO_PIN_LOW);
	}
	else if(SSD_Configuration.Type==SSD_COMMON_ANODE)
	{
		Dio_SetPinDirection(SSD_Configuration.EnablePort,SSD_Configuration.EnablePin,DIO_PIN_OUTPUT);
		Dio_SetPinValue(SSD_Configuration.EnablePort,SSD_Configuration.EnablePin,DIO_PIN_HIGH);
	}
}
void SSD_Disable(SSD_Type SSD_Configuration)
{
	if(SSD_Configuration.Type==SSD_COMMON_CATHODE)
	{
		Dio_SetPinDirection(SSD_Configuration.EnablePort,SSD_Configuration.EnablePin,DIO_PIN_OUTPUT);
		Dio_SetPinValue(SSD_Configuration.EnablePort,SSD_Configuration.EnablePin,DIO_PIN_HIGH);
	}
	else if(SSD_Configuration.Type==SSD_COMMON_ANODE)
	{
		Dio_SetPinDirection(SSD_Configuration.EnablePort,SSD_Configuration.EnablePin,DIO_PIN_OUTPUT);
		Dio_SetPinValue(SSD_Configuration.EnablePort,SSD_Configuration.EnablePin,DIO_PIN_LOW);
	}
}
void SSD_SendNumber(SSD_Type SSD_Configuration,u8 Send_Number)
{
	if(SSD_Configuration.Type==SSD_COMMON_CATHODE)
	{
		Dio_SetPortValue(SSD_Configuration.DataPort,Local_SSDNumbers[Send_Number]);
		
	}
	else if(SSD_Configuration.Type==SSD_COMMON_ANODE)
	{
		Dio_SetPortValue(SSD_Configuration.DataPort,~(Local_SSDNumbers[Send_Number]));
	}
	
	
}