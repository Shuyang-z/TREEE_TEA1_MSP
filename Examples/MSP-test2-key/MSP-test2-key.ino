#include <TREEE_TEAS1_MSP.h>

#define PIN            5
#define NUMPIXELS      2
WS2811Driver pixels = WS2811Driver(NUMPIXELS, PIN, NEO_GRB);

void setup() 
{
    shift_reg_init();   //传感器初始化
    pixels.begin();     //彩色灯珠初始化
}
void loop()                                                                             
{
    reload_shift_reg(); //刷新传感器数据
    if(sensor.key_1)    //按键1被按下//在comm.h内查表
    {
        pixels.setPixelColor(0, pixels.Color(100,0,0)); //设定第一个灯珠颜色RGB(0~255)
        pixels.setPixelColor(1, pixels.Color(100,0,0)); //设定第二个灯珠颜色
        pixels.show();  //显示设定好的颜色
    }
    if(sensor.key_2)    //按键2被按下
    {
        pixels.setPixelColor(0, pixels.Color(0,150,0));
        pixels.setPixelColor(1, pixels.Color(0,150,0));
        pixels.show();
    }
}
