/**
  ******************************************************************************
  * @file    Project/STM32L1xx_StdPeriph_Templates/main.c 
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    16-May-2014
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "timer.h"
#include "bc95.h"
#include "led.h"
#include "delay.h"
#include "dht11.h"
#include "string.h"
#include "stdlib.h"
GPIO_InitTypeDef GPIO_InitStructure;
static __IO uint32_t TimingDelay;
u8 temp,humi;
/* Private function prototypes -----------------------------------------------*/
/** @addtogroup Template_Project
  * @{
  */

/*****����COAPЭ�����򿪷��������ݷ��͵�����ƽ̨��������ʾ�����������Ϊ���򿪷�
ע����ŵĿ�ֻ�ܽ�����ŵ�IOTƽ̨����Ӧ�ƶ��Ŀ������������Ż����ǻ�Ϊ��ƽ̨�����
��Ҫ����oceanconncet�Ļ�����Ҫ�����ƶ���B8ϵ�п�����
*****/
/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
//u8 sendata[7]="001234";	
uint8_t sendata[10]="01";
int main(void)
{
//ID �¶� ʪ��
    u8 i;
    delay_init();	
    LED_Init();
//    while(DHT11_Init());//��ʼ��DHT11
    uart_init(9600);
    uart3_init(9600);
    TIM4_Int_Init(4999,3199);//500msһ���ж�
    CDP_Init();//CDP��������ʼ��    
    BC95_Init();
  while (1)
  {
//    DHT11_Read_Data(&temp,&humi);//��ȡ��ʪ������
//    sendata[2]=temp/16+0x30;//��׼��������ʮ�������ϴ����ݵ�ƽ̨
//  if(temp%16>=10)
//    sendata[3]=temp%16+0x37;//ת��A-F���ַ�
//  else
//    sendata[3]=temp%16+0x30;     
//    sendata[4]=humi/16+0x30;
//  if(humi%16>=10)
//    sendata[5]=humi%16+0x37;
//  else
//    sendata[5]=humi%16+0x30;       
//    sendata[6]=0;//�ַ���������   
		BC95_SendCOAPdata((uint8_t*)"1",sendata);
    Delay(1000);//��ʱ1s 
    Delay(1000);//��ʱ1s
		Delay(1000);//��ʱ1s
		Delay(1000);//��ʱ1s
		Delay(1000);//��ʱ1s
		Delay(1000);//��ʱ1s
    BC95_RECCOAPData();//���շ������·�������
    GPIO_ToggleBits(GPIOB,GPIO_Pin_9);//LED��ת
	
  }
}




#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
