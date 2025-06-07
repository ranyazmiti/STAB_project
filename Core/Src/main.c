/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "icache.h"
#include "gpio.h"
#include "lfs.h"
#include "lfs_util.h"
#include "lfs_config.h"
#include "usart.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define USER_LED2_Pin GPIO_PIN_8
#define USER_LED2_GPIO_Port GPIOI
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* USER CODE BEGIN PFP */

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
  MX_ICACHE_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  extern struct lfs_config cfg;
  lfs_t lfs;
  int err = lfs_mount(&lfs, &cfg);

  // Test UART : Remplacement de printf() par HAL_UART_Transmit
  uint8_t msg_start[] = "Demarrage du système...\r\n";
  HAL_UART_Transmit(&huart1, msg_start, sizeof(msg_start) - 1, HAL_MAX_DELAY);

  if (err) {
      uint8_t msg_format[] = "LittleFS non monte, formatage...\r\n";
      HAL_UART_Transmit(&huart1, msg_format, sizeof(msg_format) - 1, HAL_MAX_DELAY);

      lfs_format(&lfs, &cfg);
      err = lfs_mount(&lfs, &cfg);
  }

  if (err == 0) {
      lfs_file_t file;
      const char *text = "Bonjour SRAM3 !";
      char buffer[128];

      // Écriture du fichier
      uint8_t msg_write[] = "Ecriture dans monfichier.txt...\r\n";
      HAL_UART_Transmit(&huart1, msg_write, sizeof(msg_write) - 1, HAL_MAX_DELAY);

      if (lfs_file_open(&lfs, &file, "monfichier.txt", LFS_O_WRONLY | LFS_O_CREAT) == 0) {
          lfs_file_write(&lfs, &file, text, strlen(text));
          lfs_file_close(&lfs, &file);

          uint8_t msg_success[] = "Ecriture reussie\r\n";
          HAL_UART_Transmit(&huart1, msg_success, sizeof(msg_success) - 1, HAL_MAX_DELAY);
      } else {
          uint8_t msg_error_open[] = "Erreur : ouverture du fichier en ecriture\r\n";
          HAL_UART_Transmit(&huart1, msg_error_open, sizeof(msg_error_open) - 1, HAL_MAX_DELAY);
      }

      // Lecture du fichier
      uint8_t msg_read[] = "Lecture de monfichier.txt...\r\n";
      HAL_UART_Transmit(&huart1, msg_read, sizeof(msg_read) - 1, HAL_MAX_DELAY);

      if (lfs_file_open(&lfs, &file, "monfichier.txt", LFS_O_RDONLY) == 0) {
          lfs_ssize_t bytes_read = lfs_file_read(&lfs, &file, buffer, sizeof(buffer) - 1);
          if (bytes_read > 0) {
              buffer[bytes_read] = '\0'; // Terminaison de chaîne
              uint8_t msg_content[] = "Contenu lu : ";
              HAL_UART_Transmit(&huart1, msg_content, sizeof(msg_content) - 1, HAL_MAX_DELAY);
              HAL_UART_Transmit(&huart1, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
              uint8_t msg_newline[] = "\r\n";
              HAL_UART_Transmit(&huart1, msg_newline, sizeof(msg_newline) - 1, HAL_MAX_DELAY);
          } else {
              uint8_t msg_read_error[] = "Erreur : lecture du fichier\r\n";
              HAL_UART_Transmit(&huart1, msg_read_error, sizeof(msg_read_error) - 1, HAL_MAX_DELAY);
          }
          lfs_file_close(&lfs, &file);
      } else {
          uint8_t msg_read_open_error[] = "Erreur : ouverture du fichier en lecture\r\n";
          HAL_UART_Transmit(&huart1, msg_read_open_error, sizeof(msg_read_open_error) - 1, HAL_MAX_DELAY);
      }

      // Boucle LED + message
      uint8_t msg_loop[] = "Demarrage de la boucle LED...\r\n";
      HAL_UART_Transmit(&huart1, msg_loop, sizeof(msg_loop) - 1, HAL_MAX_DELAY);

      while (1) {
          HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);

          uint8_t msg_on[] = "LED ON\r\n";
          HAL_UART_Transmit(&huart1, msg_on, sizeof(msg_on) - 1, HAL_MAX_DELAY);

          HAL_Delay(1000);

          HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);

          uint8_t msg_off[] = "LED OFF\r\n";
          HAL_UART_Transmit(&huart1, msg_off, sizeof(msg_off) - 1, HAL_MAX_DELAY);

          HAL_Delay(1000);
      }
  } else {
      uint8_t msg_fatal_error[] = "Erreur fatale : impossible de monter LittleFS\r\n";
      HAL_UART_Transmit(&huart1, msg_fatal_error, sizeof(msg_fatal_error) - 1, HAL_MAX_DELAY);

      HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
      while (1); // Boucle infinie en cas d'erreur
  }
  /* USER CODE END 2 */

   /* Infinite loop */
   /* USER CODE BEGIN WHILE */
   while (1)
   {
     /* USER CODE END WHILE */
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_CSI;
  RCC_OscInitStruct.CSIState = RCC_CSI_ON;
  RCC_OscInitStruct.CSICalibrationValue = RCC_CSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLL1_SOURCE_CSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 125;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1_VCIRANGE_2;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1_VCORANGE_WIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_PCLK3;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the programming delay
  */
  __HAL_FLASH_SET_PROGRAM_DELAY(FLASH_PROGRAMMING_DELAY_2);
}

/**
  * @brief ICACHE Initialization Function
  * @param None
  * @retval None
  */
void MX_ICACHE_Init(void)
{
  /* USER CODE BEGIN ICACHE_Init 0 */

  /* USER CODE END ICACHE_Init 0 */

  /* USER CODE BEGIN ICACHE_Init 1 */

  /* USER CODE END ICACHE_Init 1 */

  /** Enable instruction cache (default 2-ways set associative cache)
  */
  if (HAL_ICACHE_Enable() != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ICACHE_Init 2 */

  /* USER CODE END ICACHE_Init 2 */
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED1_Pin */
  GPIO_InitStruct.Pin = LED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED1_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init 2 */

  /* USER CODE END MX_GPIO_Init 2 */
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
