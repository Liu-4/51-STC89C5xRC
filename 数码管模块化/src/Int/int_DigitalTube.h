#ifndef __INT_DIGITALTUBE_H__
#define __INT_DIGITALTUBE_H__

#include <Com_Util.h>
#define SMG_EN P36 //直接调用控制数码管的针脚
#define LED_EN P34 //控制LED



void Int_DigitalTube_Init();
void Int_DigitalTube_DispalyNum(u32 num);
void Int_DigitalTube_Refresh();

#endif // !1