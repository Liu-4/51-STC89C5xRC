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
	unsigned char temp = 0x01; //赋值一个临时数值，用来定位灯珠位置
	while (1) //死循环
	{
		P0 = ~temp; //取反灯珠位置
		Delay100ms(); //延迟100ms
		temp <<= 1; //移位（切换灯珠）
		if(temp == 0x00) //判断有没有跑完整个灯珠，跑完就重新赋值回初始值，继续循环
		{
			temp = 0x01;
		}
	}
	

}