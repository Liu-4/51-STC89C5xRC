#include "int_key.h"
#include <STC89C5xRC.H>
#include <Com_Util.h>
#define sw1 P42
#define sw2 P43
#define sw3 P32
#define sw4 P33

bit Int_key_IsSw1Preassed()
{
    if (sw1 == 0)
        {
            Com_Util_Delay1ms(10);
            if (sw1 == 0)
            {
                while(sw1 == 0);
                return 1;
            }
        }
        return 0;
}

bit Int_key_IsSw2Preassed()
{
    if (sw2 == 0)
        {
            Com_Util_Delay1ms(10);
            if (sw2 == 0)
            {
                while(sw2 == 0);
                return 1;
            }
        }
        return 0;   
}

bit Int_key_IsSw3Preassed()
{
    if (sw3 == 0)
        {
            Com_Util_Delay1ms(10);
            if (sw3 == 0)
            {
                while(sw3 == 0);
                return 1;
            }
        }
        return 0;    
}

bit Int_key_IsSw4Preassed()
{
    if (sw4 == 0)
        {
            Com_Util_Delay1ms(10);
            if (sw4 == 0)
            {
                while(sw4 == 0);
                return 1;
            }
        }
        return 0;    
}
