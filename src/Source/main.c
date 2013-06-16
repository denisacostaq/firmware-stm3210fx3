/*!
  \file main.c You need edit this file and create some others for your
  personal project.
  \author Alvaro Denis Acosta Quesada denisacostaq\@gmail.com
  \date Sat Jun 15 04:41:16 CDT 2013
  
  \brief If you are a professional emploee, is good edit this comments ;)

  \attention <h1><center>&copy; COPYRIGHT GNU GENERAL PUBLIC LICENSE Version 2, June 1991</center></h1>
*/


/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stm32_eval.h"


#ifdef USE_STM32100B_EVAL
 #include "stm32100b_eval_lcd.h"
#elif defined USE_STM3210B_EVAL
 #include "stm3210b_eval_lcd.h"
#elif defined USE_STM3210E_EVAL
 #include "stm3210e_eval_lcd.h" 
#elif defined USE_STM3210C_EVAL
 #include "stm3210c_eval_lcd.h"
#elif defined USE_STM32100E_EVAL
 #include "stm32100e_eval_lcd.h"
#endif



//#include <stm32f10x_rcc.h>//Libraries/STM32F10x_StdPeriph_Driver/inc
//#include <stm32f10x_rcc.h>//Libraries/STM32F10x_StdPeriph_Driver/inc/
//#include <Common/fonts.h>//Utilities/STM32_EVAL/Common/
//#include <STM32100B_EVAL/stm32100b_eval_lcd.h>//Utilities/STM32_EVAL/STM32100B_EVAL/

/*Headers of Scheduler and MemManager FreeRTOS.*/
#include "FreeRTOSConfig.h"
#include <FreeRTOS.h>
#include <task.h>


#define MESSAGE   " Device running " 
#ifdef USE_STM32100B_EVAL
  #define MESSAGE1   "STM32 MD Value Line "   
  #define MESSAGE2   "  STM32100B-EVAL    " 
#elif defined (USE_STM3210B_EVAL)
  #define MESSAGE1   "STM32 Medium Density"   
  #define MESSAGE2   "   STM3210B-EVAL    " 
#elif defined (STM32F10X_XL) && defined (USE_STM3210E_EVAL)
  #define MESSAGE1   "  STM32 XL Density  " 
  #define MESSAGE2   "   STM3210E-EVAL    "
#elif defined (USE_STM3210E_EVAL)
  #define MESSAGE1   " STM32 High Density " 
  #define MESSAGE2   "   STM3210E-EVAL    " 
#elif defined (USE_STM3210C_EVAL)
  #define MESSAGE1   " STM32 Connectivity " 
  #define MESSAGE2   " on STM3210C-EVAL   "
#elif defined (USE_STM32100E_EVAL)
  #define MESSAGE1   "STM32 HD Value Line " 
  #define MESSAGE2   "  STM32100E-EVAL    "   
#endif

/*! Initialize the dispaly
 * \brief Beafore use the display you need initialize this and configure
 * \sa loadConfigParameters
 */
void LCD_Initialize();

/*! Configure the display
 \param This parameter is not used, WDF??
 \brief Beafore use the display you need initialize this and configure
 \sa LCD_Initialize
*/
void loadConfigParameters(void* a);

/*! Show a message in the LCD
  \param message This is the message to show.
  \brief All the others parameters are wirles, it is only an \"example\"*/
void showMessage(char* message);

/*! This task is running for ever.
 * \brief  This show changes in led using  vTaskDelay.
 * */
void leds (void);

int main()
{
    /******************************************************************/
    /*              Initialize LEDs STM3210X-EVAL on board            */
    /******************************************************************/
    STM_EVAL_LEDInit(LED1);
    STM_EVAL_LEDInit(LED2);
    STM_EVAL_LEDInit(LED3);
    STM_EVAL_LEDInit(LED4);

    /******************************************************************/
    /*              Turn on leds available on STM3210X-EVAL           */
    /******************************************************************/
    STM_EVAL_LEDOn(LED1);
    STM_EVAL_LEDOn(LED2);
    STM_EVAL_LEDOn(LED3);
    STM_EVAL_LEDOn(LED4);

  
    LCD_Initialize();
    xTaskCreate (loadConfigParameters, (signed portCHAR *) "configTask",
                configMINIMAL_STACK_SIZE, NULL, 2, NULL);
    xTaskCreate(leds, (signed portCHAR *) "ledsTask",
                configMINIMAL_STACK_SIZE, NULL, 2, NULL);

    /******************************************************************/
    /*              Run two FreeRTOS task of priority same            */
    /******************************************************************/
    vTaskStartScheduler();
    for (;;);
}

void loadConfigParameters(void* a)
{
    LCD_Clear(0);
    LCD_SetFont(&Font12x12);

    showMessage("<      Hello-stm32       >");
    // Launch monitor config and snooze  
    vTaskSuspend(NULL);
}

void showMessage(char* message)
{
    int lineNo = 100;
    LCD_SetTextColor(65535);
    LCD_SetBackColor(15);
    LCD_DisplayStringLine(lineNo, message);
}

void LCD_Initialize()
{
    // LCD Init
    LCD_Setup();
    LCD_SPIConfig();
    STM3210C_LCD_Init();
}

void leds (void)
{ 
	vTaskDelay(10);
	STM_EVAL_LEDToggle(LED1);
	STM_EVAL_LEDToggle(LED2);
	STM_EVAL_LEDToggle(LED3);
	STM_EVAL_LEDToggle(LED4);
	vTaskDelay(100);
	STM_EVAL_LEDToggle(LED1);
	STM_EVAL_LEDToggle(LED2);
	STM_EVAL_LEDToggle(LED3);
	STM_EVAL_LEDToggle(LED4);
	vTaskDelay(100);
	STM_EVAL_LEDToggle(LED1);
	STM_EVAL_LEDToggle(LED2);
	STM_EVAL_LEDToggle(LED3);
	STM_EVAL_LEDToggle(LED4);
	while (1)
	{
		vTaskDelay(10);
		STM_EVAL_LEDToggle(LED1);
		vTaskDelay(10);
		STM_EVAL_LEDToggle(LED1);
		STM_EVAL_LEDToggle(LED2);
		vTaskDelay(10);
		STM_EVAL_LEDToggle(LED2);
		STM_EVAL_LEDToggle(LED3);
		vTaskDelay(10);
		STM_EVAL_LEDToggle(LED3);
		STM_EVAL_LEDToggle(LED4);
		vTaskDelay(10);
		STM_EVAL_LEDToggle(LED4);
		STM_EVAL_LEDToggle(LED1);
	}
}
