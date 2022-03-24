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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

// Maximum digits macros.
#define MAX_SPEED_DIGIT 3
#define MAX_ACCERLATION_DIGIT 2
#define MAX_X_AXIS_DIGIT 1
#define MAX_Y_AXIS_DIGIT 1

// TX and RX size macros.
#define TX_SIZE 50
#define RX_SIZE 50

// Car locations macros.
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4
#define NORTH_EAST 5
#define NORTH_WEST 6
#define SOUTH_EAST 7
#define SOUTH_WEST 8

// Car doors macros.
#define LEFT_DOOR  1
#define RIGHT_DOOR 2
#define BAG_DOOR   3
#define CAR_HOOD   4
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

// Warning messages for neighbor cars.
uint8_t reduceSpeedWarningMsg[TX_SIZE] = "Warning! Reduce your speed immediately????????????";
uint8_t holdOnSpeedWarningMsg[TX_SIZE] = "Warning! Hold on your speed???????????????????????";
uint8_t boostSpeedWarningMsg[TX_SIZE]  = "Warning! Boost your speed immediately?????????????";
uint8_t rightSignWarningMsg[TX_SIZE]   = "Warning! Some car in left lane may join yours?????";
uint8_t leftSignWarningMsg[TX_SIZE]    = "Warning! Some car in right lane may join yours????";
uint8_t rightDoorWarningMsg[TX_SIZE]   = "Warning! Some door in left lane may be opened?????";
uint8_t leftDoorWarningMsg[TX_SIZE]    = "Warning! Some door in right lane may be opened????";
uint8_t bagDoorWarningMsg[TX_SIZE]     = "Warning! Bag door in some front car may be opened?";
uint8_t carHoodWarningMsg[TX_SIZE]     = "Warning! Car hood in some behind car may be opened";
uint8_t changeLaneWarningMsg[TX_SIZE]  = "Warning! Don't change your lane right now?????????";
uint8_t redundantSafeMsg[TX_SIZE]      = "                                                  ";

// TX and RX buffer initialization.
uint8_t bufferRX[RX_SIZE];
uint8_t bufferTX[TX_SIZE] = "s=???,a=+??,x=+?,y=+?,r=?,l=?,d=?.................";
int indexOfRXBuffer = 0;
int indexOfTXBuffer = 0;

// Neighbor car Data initialization
uint8_t speed = 0;
int8_t accerlation = 0;
int8_t  xAxis = 0;
int8_t  yAxis = 0;
uint8_t leftSignCheck  = 0;
uint8_t rightSignCheck = 0;
uint8_t doorSignCheck  = 0;
uint8_t positionIndication = 0;

// This car data initialization.
uint8_t carSpeed       = 60;
int8_t carAccerlation = -3;
uint8_t carLeftSign    = 1;
uint8_t carRightSign  = 0;
uint8_t carDoorSign  = 3;
int8_t carXAxis = 0;
int8_t carYAxis = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t calculateValue(int indexOfRXBuffer)
{
	long power = 1;
    uint8_t result = 0;
	while(bufferRX[indexOfRXBuffer] != '=' && bufferRX[indexOfRXBuffer] != '+' && bufferRX[indexOfRXBuffer] != '-')
	{
		result += (bufferRX[indexOfRXBuffer] - '0') * power;
		power *= 10;
		indexOfRXBuffer--;
	}
	return result;
}

uint8_t takeAbsoulute(int8_t value)
{
	if(value < 0) return value*-1;
	return value;
}

void convertIntToChars(uint8_t maxDigit, uint8_t value)
{
	long power = 1;
	int index;
	for(index = 1; index < maxDigit; index++) power *= 10;

	for(index = maxDigit; index > 0; index --)
	{
		bufferTX[indexOfTXBuffer] = (value/power) + '0';
		value -= (bufferTX[indexOfTXBuffer] - '0') * power;
		indexOfTXBuffer++;
		power /= 10;
	}
}

void indicatePosition()
{
	if(xAxis > 0  && yAxis > 0) positionIndication = NORTH_EAST;
	if(xAxis > 0  && yAxis < 0) positionIndication = SOUTH_EAST;
	if(xAxis < 0  && yAxis > 0) positionIndication = NORTH_WEST;
	if(xAxis < 0  && yAxis < 0) positionIndication = SOUTH_WEST;
	if(xAxis == 0 && yAxis > 0) positionIndication = NORTH;
	if(xAxis == 0 && yAxis < 0) positionIndication = SOUTH;
	if(xAxis > 0  && yAxis == 0) positionIndication = EAST;
	if(xAxis < 0  && yAxis == 0) positionIndication = WEST;
}

void sendWarning()
{
	if(positionIndication == NORTH_EAST)
	{
		if(doorSignCheck == LEFT_DOOR) HAL_UART_Transmit(&huart1, leftDoorWarningMsg, TX_SIZE, 0xFF);
		if(leftSignCheck == 1) HAL_UART_Transmit(&huart1, leftSignWarningMsg, TX_SIZE, 0xFF);
		// Todo: Calculate the distances and compare.
		if(speed < carSpeed && accerlation < 0) HAL_UART_Transmit(&huart1, reduceSpeedWarningMsg, TX_SIZE, 0xFF);

	}
	if(positionIndication == NORTH_WEST)
	{
		if(rightSignCheck == 1) HAL_UART_Transmit(&huart1, rightSignWarningMsg, TX_SIZE, 0xFF);
		// Todo: Calculate the distances by second Law Newten and compare.
		if(speed < carSpeed && accerlation < 0) HAL_UART_Transmit(&huart1, reduceSpeedWarningMsg, TX_SIZE, 0xFF);
		if(doorSignCheck == RIGHT_DOOR) HAL_UART_Transmit(&huart1, rightDoorWarningMsg, TX_SIZE, 0xFF);
	}
	if(positionIndication == NORTH)
	{
		if(speed < carSpeed && accerlation < 0) HAL_UART_Transmit(&huart1, reduceSpeedWarningMsg, TX_SIZE, 0xFF);
		if(doorSignCheck == BAG_DOOR && yAxis == 1) HAL_UART_Transmit(&huart1, bagDoorWarningMsg, TX_SIZE, 0xFF);
	}
	if(positionIndication == SOUTH_WEST)
	{
		if(speed > carSpeed && accerlation > 0 && rightSignCheck == 1) HAL_UART_Transmit(&huart1, boostSpeedWarningMsg, TX_SIZE, 0xFF);
		if(speed > carSpeed && carLeftSign == 1) HAL_UART_Transmit(&huart1, changeLaneWarningMsg, TX_SIZE, 0xFF);
	}
	if(positionIndication == SOUTH_EAST)
	{
		if(speed > carSpeed && accerlation > 0 && leftSignCheck == 1) HAL_UART_Transmit(&huart1, boostSpeedWarningMsg, TX_SIZE, 0xFF);
		if(speed > carSpeed && carRightSign == 1) HAL_UART_Transmit(&huart1, changeLaneWarningMsg, TX_SIZE, 0xFF);
	}
	if(positionIndication == SOUTH)
	{
		if(speed > carSpeed && accerlation > 0) HAL_UART_Transmit(&huart1, boostSpeedWarningMsg, TX_SIZE, 0xFF);
		if(doorSignCheck == CAR_HOOD && yAxis == -1) HAL_UART_Transmit(&huart1, carHoodWarningMsg, TX_SIZE, 0xFF);
	}
	if(positionIndication == EAST)
	{
		if(doorSignCheck == LEFT_DOOR) HAL_UART_Transmit(&huart1, leftDoorWarningMsg, TX_SIZE, 0xFF);
		if(leftSignCheck == 1) HAL_UART_Transmit(&huart1, holdOnSpeedWarningMsg, TX_SIZE, 0xFF);
		if(carRightSign == 1 && leftSignCheck == 1) HAL_UART_Transmit(&huart1, changeLaneWarningMsg, TX_SIZE, 0xFF);
	}
	if(positionIndication == WEST)
	{
		if(doorSignCheck == RIGHT_DOOR) HAL_UART_Transmit(&huart1, rightDoorWarningMsg, TX_SIZE, 0xFF);
		if(rightSignCheck == 1) HAL_UART_Transmit(&huart1, holdOnSpeedWarningMsg, TX_SIZE, 0xFF);
		if(carLeftSign == 1 && rightSignCheck == 1) HAL_UART_Transmit(&huart1, changeLaneWarningMsg, TX_SIZE, 0xFF);
	}
	HAL_UART_Transmit(&huart1, redundantSafeMsg, TX_SIZE, 0xFF);

}

void storeCarVariables()
{
	indexOfTXBuffer = 2;
	// Store Speed.
	convertIntToChars(MAX_SPEED_DIGIT, carSpeed);
	indexOfTXBuffer +=3;

	// Store Accerlation.
	if(carAccerlation < 0) bufferTX[indexOfTXBuffer] = '-';
	indexOfTXBuffer++;
	convertIntToChars(MAX_ACCERLATION_DIGIT, takeAbsoulute(carAccerlation));
	indexOfTXBuffer +=3;

	//store XAxis.
	if(xAxis > 0) bufferTX[indexOfTXBuffer] = '-';
	indexOfTXBuffer++;
	bufferTX[indexOfTXBuffer] = takeAbsoulute(xAxis) + '0';
	indexOfTXBuffer +=4;

	//store YAxis.
	if(yAxis > 0) bufferTX[indexOfTXBuffer] = '-';
	indexOfTXBuffer++;
	bufferTX[indexOfTXBuffer] = takeAbsoulute(yAxis) + '0';
	indexOfTXBuffer +=4;

	//store Right sign.
	bufferTX[indexOfTXBuffer] = carRightSign + '0';
	indexOfTXBuffer +=4;

	//store Left sign.
	bufferTX[indexOfTXBuffer] = carLeftSign + '0';
	indexOfTXBuffer +=4;

	//store Door sign.
	bufferTX[indexOfTXBuffer] = carDoorSign + '0';
	indexOfTXBuffer +=4;
}

void resetVariables()
{
	speed = 0;
	accerlation = 0;
	xAxis = 0;
	yAxis = 0;
	leftSignCheck  = 0;
	rightSignCheck = 0;
	doorSignCheck  = 0;
	positionIndication = 0;
}
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	resetVariables();

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

	indexOfRXBuffer = 0;
	while(indexOfRXBuffer != sizeof(bufferRX))
	{
			if(bufferRX[indexOfRXBuffer] == 's')
			{
				speed = calculateValue(indexOfRXBuffer + MAX_SPEED_DIGIT + 1);
				indexOfRXBuffer += MAX_SPEED_DIGIT + 1;
			}
			if(bufferRX[indexOfRXBuffer] == 'a')
			{
				accerlation = calculateValue(indexOfRXBuffer + MAX_ACCERLATION_DIGIT + 2);
				if(bufferRX[indexOfRXBuffer + 2] == '-') accerlation *= -1;
				indexOfRXBuffer += MAX_ACCERLATION_DIGIT + 2;
			}
			if(bufferRX[indexOfRXBuffer] == 'x')
			{

				xAxis = bufferRX[indexOfRXBuffer + MAX_X_AXIS_DIGIT + 2] - '0';
				if(bufferRX[indexOfRXBuffer + 2] == '-') xAxis *= -1;
				indexOfRXBuffer += MAX_X_AXIS_DIGIT + 2;

			}
			if(bufferRX[indexOfRXBuffer] == 'y')
			{

				yAxis = bufferRX[indexOfRXBuffer + MAX_Y_AXIS_DIGIT + 2] - '0';
				if(bufferRX[indexOfRXBuffer + 2] == '-') yAxis *= -1;
				indexOfRXBuffer += MAX_Y_AXIS_DIGIT + 2;
			}
			if(bufferRX[indexOfRXBuffer] == 'l')
			{
				leftSignCheck = bufferRX[indexOfRXBuffer + 2] - '0';
				indexOfRXBuffer += 2;
			}
			if(bufferRX[indexOfRXBuffer] == 'r')
			{
				rightSignCheck = bufferRX[indexOfRXBuffer + 2] - '0';
				indexOfRXBuffer += 2;
			}
			if(bufferRX[indexOfRXBuffer] == 'd')
			{
				doorSignCheck = bufferRX[indexOfRXBuffer + 2] - '0';
				indexOfRXBuffer += 2;
			}
			if(bufferRX[indexOfRXBuffer] == '.')
				break;

		indexOfRXBuffer++;

	}

	indicatePosition();
	sendWarning();

    storeCarVariables();
    HAL_UART_Transmit_IT(&huart1, bufferTX, sizeof(bufferTX));

}
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
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	 HAL_UART_Receive_IT(&huart1, bufferRX, sizeof(bufferRX));
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

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

