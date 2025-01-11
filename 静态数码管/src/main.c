#include <STC89C5xRC.H> 
#define SMG_EN P36 //ֱ�ӵ��ÿ�������ܵ����
#define LED_EN P34 //����LED
typedef unsigned char u8; 
static u8 codes[10] = { //����0-9�ı���
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
void DigitalTube_DispalySingle(u8 position,u8 num_code) //����λ�ú�����
{
    // λѡ P15 P14 P13
    position <<=3; //������λ
    P1 &= 0xC7;     //��11100011 �����㣬����10 11 12 16 17 18�ŵ�����
    P1 |= position; //��������λ�����������-
    // ��ѡ:P0
    P0 = num_code; //ֱ�ӵ�������

}

void main()
{
    SMG_EN = 0; //�������
    LED_EN = 0; //�ر���ˮ��
    DigitalTube_DispalySingle(0,codes[2]); //�򿪵�һ��λ�õ�����ܣ���ʾ����8
    while (1)
    {
    }
}