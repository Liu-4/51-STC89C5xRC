#include <STC89C5xRC.H>
#include <INTRINS.H>
void Delay100ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	i = 180;
	j = 73;
	do
	{
		while (--j);
	} while (--i);
}

int main()
{
	unsigned char temp = 0x01; //��ֵһ����ʱ��ֵ��������λ����λ��
	while (1) //��ѭ��
	{
		P0 = ~temp; //ȡ������λ��
		Delay100ms(); //�ӳ�100ms
		temp <<= 1; //��λ���л����飩
		if(temp == 0x00) //�ж���û�������������飬��������¸�ֵ�س�ʼֵ������ѭ��
		{
			temp = 0x01;
		}
	}
	

}