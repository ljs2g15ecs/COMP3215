/**
 * This is template for main module created by MCUXpresso Project Generator. Enjoy!
 **/

#include 		<string.h>

#include 		"board.h"
#include 		"pin_mux.h"
#include 		"clock_config.h"
/*#include 		"fsl_debug_console.h"*/
#include		"fsl_gpio.h"

/*	FreeRTOS kernel includes.	*/
#include 		"FreeRTOS.h"
#include 		"task.h"
#include 		"queue.h"
#include 		"timers.h"

/*	Defines & Functions			*/
#define			N					4

static const 	gpio_pin_config_t led_conf =
{
    kGPIO_DigitalOutput,		//	OUTPUT
    1,							//	HIGH INITIAL VALUE
};

GPIO_Type		*led_gpio[N]	=	{	GPIOA,	GPIOA,	GPIOC,	GPIOB	};
uint32_t		led_pins[N]		=	{	18,		19,		1,		0		};

void			GPIO_Init()
{
	uint8_t i;
	for(i=0; i<N; i++)				GPIO_PinInit(led_gpio[i], led_pins[i], &led_conf);
}

portTickType Ticks(const float s)
{
	return (portTickType) (s * (const float) configTICK_RATE_HZ);
}

/*	Task priorities.			*/
#define 		led_task1_PRIORITY 	(configMAX_PRIORITIES - 1)
#define 		led_task2_PRIORITY 	(configMAX_PRIORITIES - 2)

/*!
 * @brief Task responsible for printing of "Hello world." message.
 */
static void		led_task1(void *pv)
{
	uint8_t i;
	for(i=0;;i++) 
	{
		GPIO_WritePinOutput(led_gpio[i%3], led_pins[i%3], 0);
		vTaskDelay( Ticks(0.1) );
		GPIO_WritePinOutput(led_gpio[i%3], led_pins[i%3], 1);
		vTaskDelay( Ticks(0.9) );
	}
}

static void		led_task2(void *pv)
{
	for(;;)
	{
		GPIO_WritePinOutput(led_gpio[3], led_pins[3], 0);
		vTaskDelay( Ticks(1.1) );
		GPIO_WritePinOutput(led_gpio[3], led_pins[3], 1);
		vTaskDelay( Ticks(0.9) );
	}
}

/*!
 * @brief Application entry point.
 */
int 			main(void)
{
	/*	Init board hardware.	*/
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();
	
	/*	Add your code here		*/
	GPIO_Init();
	
	/*	Create RTOS task		*/
	xTaskCreate(	led_task1,
					"led_task1",
					configMINIMAL_STACK_SIZE,
					NULL,
					led_task1_PRIORITY,
					NULL					);
	
	xTaskCreate(	led_task2,
					"led_task2",
					configMINIMAL_STACK_SIZE,
					NULL,
					led_task2_PRIORITY,
					NULL					);
	
	vTaskStartScheduler();

	for(;;)		{	__asm("NOP");			}
}


