#include <STC89C5xRC.H>
#include <int_KeyMatrix.h>
#include <int_DigitalTube.h>
int main()
{
    u8 key;
    Int_DigitalTube_Init();
    Int_DigitalTube_DispalyNum(12345678);
    while (1)
    {
        key = Int_KeyMatrix_CheckSW();
        if(key != 0)
        {
            //ÊýÂë¹Ü
            Int_DigitalTube_DispalyNum(key);  
        }
        Int_DigitalTube_Refresh();
    }
}