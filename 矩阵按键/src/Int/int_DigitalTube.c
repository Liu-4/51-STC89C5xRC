#include "int_DigitalTube.h"
#include <STC89C5xRC.H>

static u8 S_codes[10] = { //数字0-9的编码
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
    SMG_EN = 0; //打开数码管
    LED_EN = 0; //关闭流水灯
}

static void Int_DigitalTube_DispalySingle(u8 position,u8 num_code) //定义位置和数据
{
    P0 = 0x00;     //清零
    // 位选 P15 P14 P13--
    position <<=3; //左移三位
    P1 &= 0xC7;     //和11100011 与运算，保留10 11 12 16 17 18脚的数据
    P1 |= position; //讲左移三位后的数据填入

    // 段选:P0
    P0 = num_code; //直接调用数据
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
