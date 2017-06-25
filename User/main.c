#include "includes.h"

static void vTaskTaskUserIF(void *pvParameters);
static void vTaskLed(void *pvParameters);
static void vTaskMsgPro(void *pvParameters);
static void vTaskStart(void *pvParameters);
static void vTaskWin(void *pvParameters);
static void AppTaskCreate(void);


static TaskHandle_t xHandleTaskUserIF = NULL;
static TaskHandle_t xHandleTaskLed = NULL;
static TaskHandle_t xHandleTaskMsgPro = NULL;
static TaskHandle_t xHandleTaskStart = NULL;



int main(void)
{
	__set_PRIMASK(1);
	
	Bsp_Init();
	
	AppTaskCreate();
	
	vTaskStartScheduler();
	
	
	while(1);
	
}


static void vTaskTaskUserIF(void *pvParameters)
{
	while(1)
	{
		Led(1);
		vTaskDelay(1000);
	}
}

static void vTaskLed(void *pvParameters)
{
	while(1)
	{
		Led(2);
		vTaskDelay(2000);
	}
}

static void vTaskMsgPro(void *pvParameters)
{
	while(1)
	{
		Led(3);
		vTaskDelay(900);
	}
}

static void vTaskStart(void *pvPatameters)
{
	while (1)
	{
		Led(4);
		vTaskDelay(1940);
	}
}

static void vTaskWin(void *pvPatameters)
{
		MainTask();

}
	
	
static void AppTaskCreate (void)
{
	xTaskCreate(vTaskTaskUserIF,
							"vTaskTaskUserIF",
							512,
							NULL,
							1,
							&xHandleTaskUserIF);
	
	xTaskCreate(vTaskLed,
							"vTaskLed",
							512,
							NULL,
							2,
							&xHandleTaskLed);
	
	xTaskCreate(vTaskMsgPro,
							"vTaskMsgPro",
							512,
							NULL,
							3,
							&xHandleTaskMsgPro);
	
	xTaskCreate(vTaskStart,
							"vTaskStart",
							512,
							NULL,
							4,
							&xHandleTaskStart);
	xTaskCreate(vTaskWin,
							"vTaskWin",
							512,
							NULL,
							1,
							NULL);
							
							
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	



