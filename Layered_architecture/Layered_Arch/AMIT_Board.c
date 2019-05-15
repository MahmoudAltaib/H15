/*
 * AMIT_Board.c
 *
 * Created: 5/10/2019 11:22:44 PM
 *  Author: A.Elkady
 */ 
#ifdef AMIT_ATMEGA



extern void LED_On (uint8_t u8LED_Number)
{
	Set_bit(PORT3 , u8LED_Number );
}

extern void LED_Off(uint8_t u8LED_Number)
{
	Reset_bit(PORT3 , u8LED_Number );
}

extern void Relay_On ()
{
	Set_bit(PORT3 , AMIT_RELAY );
}

extern void Relay_Off()
{
	Reset_bit(PORT3 , AMIT_RELAY );
}

extern void Buzzer_On ()
{
	Set_bit(PORT3 , AMIT_BUZZER );
}

extern void Buzzer_Off()
{
	Reset_bit(PORT3 , AMIT_BUZZER);
}

#endif