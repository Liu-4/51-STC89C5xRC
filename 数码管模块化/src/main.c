#include "int_DigitalTube.h"


int main()
{
    Int_DigitalTube_Init();
    Int_DigitalTube_DispalyNum(123456);
    while (1)
    {
        Int_DigitalTube_Refresh();
    }
    
}


