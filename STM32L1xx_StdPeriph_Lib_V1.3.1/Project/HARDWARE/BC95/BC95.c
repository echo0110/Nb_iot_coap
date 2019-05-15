#include "bc95.h"
#include "main.h"
#include "string.h"
#include "delay.h"
char *strx,*extstrx;
extern char  RxBuffer[100],RxCounter;
BC95 BC95_Status;
void Clear_Buffer(void)//��ջ���
{
		u8 i;
		Uart1_SendStr(RxBuffer);
//	for(i=0;i<100;i++)
	//RxBuffer[i]=0;
		RxCounter=0;
}
void CDP_Init(void)//COAP���������ó�ʼ��
{
    printf("AT\r\n"); 
    Delay(300);
    strx=strstr((const char*)RxBuffer,(const char*)"OK");//����OK
    Clear_Buffer();	
  while(strx==NULL)
    {
        Clear_Buffer();	
        printf("AT\r\n"); 
        Delay(300);
        strx=strstr((const char*)RxBuffer,(const char*)"OK");//����OK
    }
    BC95_Status.netstatus=1;//��˸ûע������
    printf("AT+NBAND?\r\n");//��ȡƵ�κ�
    Delay(300);
    strx=strstr((const char*)RxBuffer,(const char*)"+NBAND:28");//����5  ����  ����8���ƶ� �ƶ��Ŀͻ���ط�ע��һ���޸�
    Clear_Buffer();	
    while(strx==NULL)
    {
        Clear_Buffer();	
        printf("AT+NBAND?\r\n");//��ȡƵ�κ�
        Delay(300);
        strx=strstr((const char*)RxBuffer,(const char*)"+NBAND:28");//����OK
    }
    printf("AT+CIMI\r\n");//��ȡ���ţ������Ƿ���ڿ�����˼���Ƚ���Ҫ��
    Delay(300);
    strx=strstr((const char*)RxBuffer,(const char*)"46011");//��46011�ǵ��ţ��ƶ���Ҫ����
    Clear_Buffer();	
  while(strx==NULL)
    {
        Clear_Buffer();	
        printf("AT+CIMI\r\n");//��ȡ���ţ������Ƿ���ڿ�����˼���Ƚ���Ҫ��
        Delay(300);
        strx=strstr((const char*)RxBuffer,(const char*)"46011");//��46011�ǵ��ţ��ƶ���Ҫ����
    }
    printf("AT+CFUN=0\r\n");//�ر���Ƶ
    Delay(300);	
    strx=strstr((const char*)RxBuffer,(const char*)"OK");//����OK
  while(strx==NULL)
    {
        strx=strstr((const char*)RxBuffer,(const char*)"OK");//����OK
    }
    Clear_Buffer();	
    printf("AT+NCDP=180.101.147.115,5683\r\n");//����CDP��������ַ����ƽ̨�ģ����COAPЭ���IP��ַ�ǹ̶���
    Delay(300);	
    strx=strstr((const char*)RxBuffer,(const char*)"OK");//����OK
  while(strx==NULL)
    {
        strx=strstr((const char*)RxBuffer,(const char*)"OK");//����OK
    }
    Clear_Buffer();	
    printf("AT+NRB\r\n");//��ģ���������
    Delay(2000);	//��ʱ2s	
    printf("AT+CIMI\r\n");//��ȡ���ţ�ȷ��ģ����������
    Delay(300);
    strx=strstr((const char*)RxBuffer,(const char*)"46011");//��46011
    Clear_Buffer();	
  while(strx==NULL)
    {
        Clear_Buffer();	
        printf("AT+CIMI\r\n");//��ȡ���ţ�ȷ��ģ����������
        Delay(300);
        strx=strstr((const char*)RxBuffer,(const char*)"46011");//����OK,˵�����Ǵ��ڵ�
    }	
		///����NCDP�ľ�ȷ�Ϻ���,�������������ñ�ȷ�Ϻ�.
}
void BC95_Init(void)
{
    unsigned char i;
    printf("AT\r\n"); 
    Delay(300);
    strx=strstr((const char*)RxBuffer,(const char*)"OK");//����OK
    Clear_Buffer();	
  while(strx==NULL)
    {
        Clear_Buffer();	
        printf("AT\r\n"); 
        Delay(300);
        strx=strstr((const char*)RxBuffer,(const char*)"OK");//����OK
    }
    BC95_Status.netstatus=1;//��˸ûע������
    printf("AT+NBAND?\r\n");//��ȡƵ�κ�
    Delay(300);
    strx=strstr((const char*)RxBuffer,(const char*)"+NBAND:28");//����5  ����,����8���ƶ���
    Clear_Buffer();	
  while(strx==NULL)
   {
        Clear_Buffer();	
        printf("AT+NBAND?\r\n");//��ȡƵ�κ�
        Delay(300);
        strx=strstr((const char*)RxBuffer,(const char*)"+NBAND:28");//����OK
    }
    printf("AT+CIMI\r\n");//��ȡ���ţ������Ƿ���ڿ�����˼���Ƚ���Ҫ��
    Delay(300);
    strx=strstr((const char*)RxBuffer,(const char*)"46011");//��46011�����ţ��ƶ�����������ֵ
    Clear_Buffer();	
  while(strx==NULL)
    {
        Clear_Buffer();	
        printf("AT+CIMI\r\n");//��ȡ���ţ������Ƿ���ڿ�����˼���Ƚ���Ҫ��
        Delay(300);
        strx=strstr((const char*)RxBuffer,(const char*)"46011");//����OK,˵�����Ǵ��ڵĵ��ţ��ƶ�����������ֵ
    }
    printf("AT+CGATT=1\r\n");//�������磬PDP
    Delay(300);
    strx=strstr((const char*)RxBuffer,(const char*)"OK");//��46011
    Clear_Buffer();	
  while(strx==NULL)
    {
        Clear_Buffer();	
        printf("AT+CGATT=1\r\n");//�������� 
        Delay(300);
        strx=strstr((const char*)RxBuffer,(const char*)"OK");//����OK
    }
    printf("AT+CGATT?\r\n");//��ѯ����״̬
    Delay(300);
    strx=strstr((const char*)RxBuffer,(const char*)"+CGATT:1");//��1
    Clear_Buffer();	
  while(strx==NULL)
    {
        Clear_Buffer();	
        printf("AT+CGATT?\r\n");//��ȡ����״̬
        Delay(300);
        strx=strstr((const char*)RxBuffer,(const char*)"+CGATT:1");//����1,����ע���ɹ�
    }
    printf("AT+CSQ\r\n");//�鿴��ȡCSQֵ
    Delay(300);
    strx=strstr((const char*)RxBuffer,(const char*)"+CSQ");//����CSQ
  if(strx)
    {
        BC95_Status.CSQ=(strx[5]-0x30)*10+(strx[6]-0x30);//��ȡCSQ
        if(BC95_Status.CSQ==99)//˵��ɨ��ʧ��
        {
            while(1)
            {
                Uart1_SendStr("�ź�����ʧ�ܣ���鿴ԭ��!\r\n");
                Delay(300);
            }
        }
            BC95_Status.netstatus=4;//ע���ɹ�
     }
  while(strx==NULL)
    {
        Clear_Buffer();	
        printf("AT+CSQ\r\n");//�鿴��ȡCSQֵ
        Delay(300);
        strx=strstr((const char*)RxBuffer,(const char*)"+CSQ");//
        if(strx)
        {
            BC95_Status.CSQ=(strx[5]-0x30)*10+(strx[6]-0x30);//��ȡCSQ
            if(BC95_Status.CSQ==99)//˵��ɨ��ʧ��
            {
                while(1)
                {
                    Uart1_SendStr("�ź�����ʧ�ܣ���鿴ԭ��!\r\n");
                    Delay(300);
                }
            }
         }
    }
    Clear_Buffer();	
    printf("AT+CEREG?\r\n");
    Delay(300);
    strx=strstr((const char*)RxBuffer,(const char*)"+CEREG:0,1");//����ע��״̬
    extstrx=strstr((const char*)RxBuffer,(const char*)"+CEREG:1,1");//����ע��״̬
    Clear_Buffer();	
  while(strx==NULL&&extstrx==NULL)
    {
        Clear_Buffer();	
        printf("AT+CEREG?\r\n");//�ж���Ӫ��
        Delay(300);
        strx=strstr((const char*)RxBuffer,(const char*)"+CEREG:0,1");//����ע��״̬
        extstrx=strstr((const char*)RxBuffer,(const char*)"+CEREG:1,1");//����ע��״̬
    }
    printf("AT+CEREG=1\r\n");
    Delay(300);
    strx=strstr((const char*)RxBuffer,(const char*)"OK");//����OK
    Clear_Buffer();	
    while(strx==NULL&&extstrx==NULL)
    {
        Clear_Buffer();	
        printf("AT+CEREG=1\r\n");//
        Delay(300);
        strx=strstr((const char*)RxBuffer,(const char*)"OK");//����OK
    }
    printf("AT+NMSTATUS?\r\n");//�жϵ�ǰģ����ƽ̨֮������ӹ�ϵ��һ��δ������֮ǰ����INIITIALISED������������͵����ݵ�ƽ̨֮����MO_DATA_ENABLED
    Delay(300);
    strx=strstr((const char*)RxBuffer,(const char*)"+NMSTATUS:INIITIALISED");//�ж��Ƿ񷵻س�ʼ��״̬���û������ڴ���һЩ��ص��ж�
    if(strx)//����ǵģ��͵���LED��
    GPIO_ResetBits(GPIOB,GPIO_Pin_9);//
    printf("AT+NNMI=1\r\n");//����ģ���յ���������ֱ�Ӵ�ӡ������
    Delay(300);
    strx=strstr((const char*)RxBuffer,(const char*)"OK");//
    for(i=0;i<100;i++)
    RxBuffer[i]=0;	
    Clear_Buffer();    
}

void BC95_SendCOAPdata(uint8_t *len,uint8_t *data)
{
	printf("AT+NMGS=%s,%s\r\n",len,data);//����COAP����
	Delay(300);
	strx=strstr((const char*)RxBuffer,(const char*)"OK");//����OK
  if(strx)//����������ȷ��ƽ̨�յ�����
    {
        Uart1_SendStr("SEND DATA OK!\r\n");//���ô���1��ӡ���ͳɹ���ʾ
        Clear_Buffer();	
    }
   else//�������error һ���ǵ�һ����ƽ̨�������������CDP�������������⡣�û����Բ�ѯ�� AT+NMSTATUS? ��ӡ����ʾ�˽��в鿴
   {
        printf("AT+NMSTATUS?\r\n");//�жϵ�ǰģ����ƽ̨֮������ӹ�ϵ��һ��δ������֮ǰ����INIITIALISED������������͵����ݵ�ƽ̨֮����MO_DATA_ENABLED
        Delay(300);
        strx=strstr((const char*)RxBuffer,(const char*)"+NMSTATUS:MO_DATA_ENABLED");//�鿴�Ƿ񷵻���������ݣ�
      if(strx)
       {
            Uart1_SendStr("Connect OK!\r\n");  //���������������ģ����´��ٷ����ݾͿ�����
       }
        Clear_Buffer();	//��ӡƽ̨�ķ���ֵ
   }      
	Clear_Buffer();	
	
}
//����ƽ̨�˶��豸���ݵ��·�
void BC95_RECCOAPData(void)
{
	char i;
	static char nexti;
    strx=strstr((const char*)RxBuffer,(const char*)"+NNMI:");//����+NSONMI:���������յ�UDP���������ص�����
  if(strx)
    {
        Clear_Buffer();	
        for(i=0;i<100;i++)
        RxBuffer[i]=0;
    }
}