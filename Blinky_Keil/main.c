#include "FreeRTOS.h"
#include "Board_LED.h"
#include "timers.h"

#define LED_1_tskPRIORITY (configMAX_PRIORITIES - 1)

#define	N 4	// Number of LEDs

portTickType	ticks(const float s);
void	LED_1(void *p);
void	LED_2(void *p);

int	main()
{
	void SystemInit ();
	void SystemCoreClockUpdate ();
	LED_Initialize ();
	
	xTaskCreate	(	LED_1,
								"LED 1",
								configMINIMAL_STACK_SIZE,
								NULL,
								LED_1_tskPRIORITY,
								NULL
							);
	xTaskCreate	(	LED_2,
								"LED 2",
								configMINIMAL_STACK_SIZE,
								NULL,
								LED_1_tskPRIORITY,
								NULL
							);
	vTaskStartScheduler();
	for(;;);
}

portTickType	ticks(const float s)	{	return (portTickType) (s *  configTICK_RATE_HZ);	};

void	LED_1(void *p)
{
	for(;;)
	{
		LED_On(N-1);
		vTaskDelay( ticks(1) );
		LED_Off(N-1);
		vTaskDelay( ticks(1) );
	}
}

void	LED_2(void *p)
{
	int i;
	for(i=0;;i++)
	{
		LED_On(i%(N-1));
		vTaskDelay( ticks(0.5) );
		LED_Off(i%(N-1)-1);
		vTaskDelay( ticks(0.5) );
	}
}
