
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : BME280 Sensor Data using STM32
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "bme280.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

/* USER CODE BEGIN PV */

struct bme280_dev dev;
struct bme280_data comp_data;
struct bme280_settings settings;

static uint8_t dev_addr = BME280_I2C_ADDR_PRIM;

int8_t rslt;

double temperature;
double pressure;
double humidity;

uint8_t sensor_status;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);

/* USER CODE BEGIN PFP */

int8_t user_i2c_read(uint8_t reg_addr, uint8_t *reg_data,
                     uint32_t len, void *intf_ptr);

int8_t user_i2c_write(uint8_t reg_addr, const uint8_t *reg_data,
                      uint32_t len, void *intf_ptr);

void user_delay_us(uint32_t period, void *intf_ptr);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/**
  * @brief  Read data from BME280 using I2C
  */
int8_t user_i2c_read(uint8_t reg_addr, uint8_t *reg_data,
                     uint32_t len, void *intf_ptr)
{
    uint8_t address = *(uint8_t *)intf_ptr;

    if(HAL_I2C_Mem_Read(&hi2c1, address << 1, reg_addr,
                        I2C_MEMADD_SIZE_8BIT, reg_data,
                        len, 1000) == HAL_OK)
    {
        return BME280_OK;
    }

    return BME280_E_COMM_FAIL;
}

/**
  * @brief  Write data to BME280 using I2C
  */
int8_t user_i2c_write(uint8_t reg_addr, const uint8_t *reg_data,
                      uint32_t len, void *intf_ptr)
{
    uint8_t address = *(uint8_t *)intf_ptr;

    if(HAL_I2C_Mem_Write(&hi2c1, address << 1, reg_addr,
                         I2C_MEMADD_SIZE_8BIT,
                         (uint8_t *)reg_data,
                         len, 1000) == HAL_OK)
    {
        return BME280_OK;
    }

    return BME280_E_COMM_FAIL;
}

/**
  * @brief  Delay function required by BME280 driver
  */
void user_delay_us(uint32_t period, void *intf_ptr)
{
    HAL_Delay((period + 999) / 1000);
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
    HAL_Init();

    SystemClock_Config();

    MX_GPIO_Init();
    MX_I2C1_Init();

    /* USER CODE BEGIN 2 */

    /* Initialize BME280 communication interface */

    dev.intf_ptr = &dev_addr;
    dev.intf = BME280_I2C_INTF;
    dev.read = user_i2c_read;
    dev.write = user_i2c_write;
    dev.delay_us = user_delay_us;

    /* Detect BME280 I2C address */

    if(HAL_I2C_IsDeviceReady(&hi2c1, 0x76 << 1, 3, 100) == HAL_OK)
    {
        dev_addr = 0x76;
        sensor_status = 1;
    }
    else if(HAL_I2C_IsDeviceReady(&hi2c1, 0x77 << 1, 3, 100) == HAL_OK)
    {
        dev_addr = 0x77;
        sensor_status = 1;
    }
    else
    {
        sensor_status = 2;
        Error_Handler();
    }

    /* Initialize BME280 */

    rslt = bme280_init(&dev);

    if(rslt != BME280_OK)
    {
        sensor_status = 3;
        Error_Handler();
    }

    sensor_status = 4;

    /* Configure BME280 settings */

    settings.osr_h = BME280_OVERSAMPLING_1X;
    settings.osr_p = BME280_OVERSAMPLING_1X;
    settings.osr_t = BME280_OVERSAMPLING_1X;
    settings.filter = BME280_FILTER_COEFF_OFF;
    settings.standby_time = BME280_STANDBY_TIME_1000_MS;

    rslt = bme280_set_sensor_settings(
        BME280_SEL_OSR_PRESS |
        BME280_SEL_OSR_TEMP |
        BME280_SEL_OSR_HUM |
        BME280_SEL_FILTER |
        BME280_SEL_STANDBY,
        &settings,
        &dev
    );

    if(rslt != BME280_OK)
    {
        sensor_status = 5;
        Error_Handler();
    }

    /* Set BME280 to normal mode */

    rslt = bme280_set_sensor_mode(BME280_POWERMODE_NORMAL, &dev);

    if(rslt != BME280_OK)
    {
        sensor_status = 6;
        Error_Handler();
    }

    sensor_status = 7;

    HAL_Delay(1000);

    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */

    while(1)
    {
        /* Read BME280 sensor data */

        rslt = bme280_get_sensor_data(BME280_ALL, &comp_data, &dev);

        if(rslt == BME280_OK)
        {
            temperature = comp_data.temperature;
            pressure = comp_data.pressure / 100.0;
            humidity = comp_data.humidity;

            sensor_status = 8;
        }
        else
        {
            sensor_status = 9;
        }

        HAL_Delay(1000);

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

    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 4;
    RCC_OscInitStruct.PLL.PLLN = 84;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 4;

    if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK |
                                  RCC_CLOCKTYPE_SYSCLK |
                                  RCC_CLOCKTYPE_PCLK1 |
                                  RCC_CLOCKTYPE_PCLK2;

    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
    {
        Error_Handler();
    }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{
    hi2c1.Instance = I2C1;

    hi2c1.Init.ClockSpeed = 100000;
    hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.OwnAddress2 = 0;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

    if(HAL_I2C_Init(&hi2c1) != HAL_OK)
    {
        Error_Handler();
    }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief Error Handler
  * @retval None
  */
void Error_Handler(void)
{
    __disable_irq();

    while(1)
    {
    }
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
}
#endif /* USE_FULL_ASSERT */
