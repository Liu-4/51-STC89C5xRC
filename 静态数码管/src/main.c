#include <STC89C5xRC.H> 
#define SMG_EN P36 //直接调用控制数码管的针脚
#define LED_EN P34 //控制LED
typedef unsigned char u8; 
static u8 codes[10] = { //数字0-9的编码
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};
void DigitalTube_DispalySingle(u8 position,u8 num_code) //定义位置和数据
{
    // 位选 P15 P14 P13
    position <<=3; //左移三位
    P1 &= 0xC7;     //和11100011 与运算，保留10 11 12 16 17 18脚的数据
    P1 |= position; //讲左移三位后的数据填入-
    // 段选:P0
    P0 = num_code; //直接调用数据

}

void main()
{
    SMG_EN = 0; //打开数码管
    LED_EN = 0; //关闭流水灯
    DigitalTube_DispalySingle(0,codes[2]); //打开第一个位置的数码管，显示数字8
    while (1)
    {
    }
}