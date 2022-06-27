/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "can.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define LM_IN1(STATE)	  HAL_GPIO_WritePin(GPIOA, L_Motor_IN1_Pin, STATE)
#define LM_IN2(STATE)	  HAL_GPIO_WritePin(GPIOA, L_Motor_IN2_Pin, STATE)
#define RM_IN3(STATE)	  HAL_GPIO_WritePin(GPIOA, R_Motor_IN3_Pin, STATE)
#define RM_IN4(STATE)	  HAL_GPIO_WritePin(GPIOA, R_Motor_IN4_Pin, STATE)

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define DELAY 1000
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void Lift_Foreword(void);
void Lift_Backword(void);
void Lift_Stop(void);
void Lift_Turn(void);

void Right_Foreword(void);
void Right_Backword(void);
void Right_Stop(void);
void Right_Turn(void);

void Left_Rot(void);
void Right_Rot(void);
void Forword(void);
void Backword(void);
void Stop(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_CAN_Init();
	MX_TIM3_Init();
	MX_USART2_UART_Init();
	/* USER CODE BEGIN 2 */
	uint8_t Msg=0;
	uint8_t Msg_Speed[10] = {'\0'};
	uint16_t Speed=1000;
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */



		/*Bluetooth*/

		HAL_UART_Receive(&huart2, &Msg, 1, HAL_MAX_DELAY);
		if ('F'==Msg) {
			Forword();
		}else if ('B'==Msg){
			Backword();
		}else if ('R'==Msg){
			Right_Rot();
		}else if ('L'==Msg){
			Left_Rot();
		}else if ('Q'==Msg){
			Lift_Turn();
		}else if ('E'==Msg){
			Right_Turn();
		}else if ('S'==Msg){
			Stop();
		}else if ('U'==Msg){
			Speed += 100;
			if(Speed >= 1000)
			{
				Speed = 1000;
			}
			TIM3->CCR3 = Speed;
			TIM3->CCR4 = Speed;
			sprintf(Msg_Speed,"%d\n",Speed/10);
			HAL_UART_Transmit(&huart2, Msg_Speed, sizeof(Msg_Speed), HAL_MAX_DELAY);

		}else if ('D'==Msg){
			Speed -= 100;
			if(Speed <= 100)
			{
				Speed = 100;
			}
			TIM3->CCR3 = Speed;
			TIM3->CCR4 = Speed;
			sprintf(Msg_Speed,"%d\n",Speed/10);
			HAL_UART_Transmit(&huart2, Msg_Speed, sizeof(Msg_Speed), HAL_MAX_DELAY);
		}

		//		HAL_Delay(DELAY);
		//		Stop();
		/*Test1*/
		/*Forword();
	  HAL_Delay(DELAY);
	  Backword();
	  HAL_Delay(DELAY);
	  Left_Rot();
	  HAL_Delay(DELAY);
	  Right_Rot();
	  HAL_Delay(DELAY);
	  Stop();
	  HAL_Delay(DELAY);*/
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
			|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV16;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV16;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
	{
		Error_Handler();
	}
}

/* USER CODE BEGIN 4 */
void Lift_Foreword(void){
	LM_IN1(RESET);
	LM_IN2(SET);
}
void Lift_Backword(void){
	LM_IN1(SET);
	LM_IN2(RESET);
}
void Lift_Stop(void){
	LM_IN1(RESET);
	LM_IN2(RESET);
}
void Lift_Turn (void){
	//(B1) CH4 Left channel
	TIM3->CCR4 -= 100;
	TIM3->CCR3 += 100;
	Forword();
}
void Right_Foreword(void){
	RM_IN3(RESET);
	RM_IN4(SET);
}
void Right_Backword(void){
	RM_IN3(SET);
	RM_IN4(RESET);
}
void Right_Stop(void){
	RM_IN3(RESET);
	RM_IN4(RESET);
}
void Right_Turn(void){
	//(B0) CH3 Right channel
	TIM3->CCR3 -= 100;
	TIM3->CCR4 +=100;
	Forword();
}

void Forword(void){
	Stop();
	Lift_Foreword();
	Right_Foreword();
}

void Backword(void){
	Stop();
	Lift_Backword();
	Right_Backword();
}

void Stop(void){
	HAL_Delay(500);
	Lift_Stop();
	Right_Stop();
}
void Right_Rot(void){
	Stop();
	Lift_Foreword();
	Right_Backword();
}

void Left_Rot(void){
	Stop();
	Lift_Backword();
	Right_Foreword();
}
/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

