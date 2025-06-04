//  ����ͨ��     USART1    

#include "BSP_USART1.h"
#include "traffic_light.h"
volatile uint8_t usart1_cmd_flag = 0; //  ������־
volatile uint8_t usart1_cmd_val = 0;  //  ��������
extern TrafficLightSystem *sys;
/* USART1 ���ų�ʼ�� */
void USART1_IOInit(void)
{
GPIO_InitTypeDef GPIO_InitStructure;
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //ʹ�� GPIOA ʱ��
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //TXD ����->PA9
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //����Ϊ�����������
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //������� 50MHz
GPIO_Init(GPIOA, &GPIO_InitStructure); //��ʼ�� GPIOA
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //RXD ����->PA10
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //����Ϊ��������
GPIO_Init(GPIOA, &GPIO_InitStructure); //��ʼ�� GPIOA
}

/* USART1 �ж����ȼ���ʼ�� */
void NVIC_USART1Enable(void)
{
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
//һ�������������
NVIC_InitTypeDef NVIC_InitStructure;
NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; //ѡ�� USART1 �ж�
NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //������ռ���ȼ�
NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //������Ӧ���ȼ�
NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //ʹ��ͨ��
NVIC_Init(&NVIC_InitStructure);
}

/* USART1 ģ���ʼ������, BAUDRATE-������ */
void USART1Init(uint32_t BAUDRATE)
{
USART_InitTypeDef USART_InitStructure;
USART1_IOInit(); //USART1 ���ų�ʼ��
RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); //ʹ�� USART1 ʱ��
USART_InitStructure.USART_BaudRate = BAUDRATE; //���ò�����
USART_InitStructure.USART_WordLength = USART_WordLength_8b;//����Ϊ 8 λ����λ
USART_InitStructure.USART_StopBits = USART_StopBits_1; //����Ϊ 1 λֹͣλ
USART_InitStructure.USART_Parity = USART_Parity_No; //��ʹ����żУ��
//����Ӳ��������
USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//ѡ�� USART ���ͺͽ���ģʽ
USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
USART_Init(USART1, &USART_InitStructure); //��ʼ�� USART1
NVIC_USART1Enable(); //USART1 �ж����ȼ���ʼ��
USART_ITConfig(USART1,USART_IT_RXNE, ENABLE); //�������ڽ����ж�
USART_Cmd(USART1,ENABLE); //ʹ�� USART1
}


//�ض���c�⺯��printf�����ڣ��ض�����ʹ��printf����
int fputc(int ch, FILE *f)
{	
// while(!((USART1->SR) & 0x80));  //�ȴ�������� 
while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);	
USART_SendData(USART1, (uint16_t)ch); 
return (ch);
}

//�ض���c�⺯��scanf�����ڣ���д����ʹ��scanf��getchar�Ⱥ���
int fgetc(FILE *f)
{
//�ȴ�������������
// while(!((USART1->SR) & 0x20));
// while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
return (int)USART_ReceiveData(USART1);
}

void Show_Message( void )
{
 printf("ʹ��USART����Ϊ��%d 8-N-1 \n",9600);
	printf("����1��2ʵ�ֽ����̵�ͨ�У�1Ϊ�ϱ�����15s�̵ƣ�2Ϊ��������15s�̵ƣ� \r\n");
	 
	
}

void USART1_IRQHandler(void)
{
    uint8_t dat;
    if(USART_GetITStatus(USART1,USART_IT_RXNE) != 0) //�������жϱ�־λ
    {
        dat = USART_ReceiveData(USART1); //��ȡ���յ�������
        //  �������
        if(dat == '1' || dat == '2') {
            usart1_cmd_flag = 1;
            usart1_cmd_val = dat;
					 USART_SendData(USART1, dat);     //����
        }
    }
}


