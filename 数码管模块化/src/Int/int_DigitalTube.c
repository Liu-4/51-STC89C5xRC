#include "int_DigitalTube.h"
#include <STC89C5xRC.H>

static u8 S_codes[10] = { //����0-9�ı���
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F // 9
};

static u8 S_buffer[8];

void Int_DigitalTube_Init()
{
    SMG_EN = 0; //�������
    LED_EN = 0; //�ر���ˮ��
}

static void Int_DigitalTube_DispalySingle(u8 position,u8 num_code) //����λ�ú�����
{
    P0 = 0x00;     //����
    // λѡ P15 P14 P13--
    position <<=3; //������λ
    P1 &= 0xC7;     //��11100011 �����㣬����10 11 12 16 17 18�ŵ�����
    P1 |= position; //��������λ�����������

    // ��ѡ:P0
    P0 = num_code; //ֱ�ӵ�������
}

void Int_DigitalTube_DispalyNum(u32 num)
{
    u8 i;
    for(i = 0; i < 8; i++)
    {
        S_buffer[i] = 0x00;
    }

    if(num == 0)
    {
        S_buffer[7] = S_codes[0];
        return;
    }

    i = 7;

    while (num >0)
    {
        S_buffer[i] = S_codes[num%10];
        num /= 10;
        i--;
    }
}

void Int_DigitalTube_Refresh()
{
    u8 i;
    for ( i = 0; i < 8; i++)
    {
        Int_DigitalTube_DispalySingle(i,S_buffer[i]);
        Com_Util_Delay1ms(1);

    }    
}
