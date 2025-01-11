#include <STC89C5xRC.H>
#include <int_key.h>
#define LED1 P00
#define LED2 P01
#define LED3 P02
#define LED4 P03

int main()
{
    while (1)
    {
        if (Int_key_IsSw1Preassed())
        {
            LED1 = ~LED1;
        }
                if (Int_key_IsSw2Preassed())
        {
            LED2 = ~LED2;
        }
                if (Int_key_IsSw3Preassed())
        {
            LED3 = ~LED3;
        }
                if (Int_key_IsSw4Preassed())
        {
            LED4 = ~LED4;
        }
    }  
}