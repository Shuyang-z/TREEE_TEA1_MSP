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
    char r0,r1,g0,g1,b0,b1;
    reload_shift_reg(); //刷新传感器数据
    if(sensor.ir_left_3) //左侧第三个(最外面)红外传感器测到黑线或悬空
        r0 = 100; //设定第1个灯珠亮红色
    else
        r0 = 0;
    if(sensor.ir_left_2) g0 = 100; else g0 = 0;
    if(sensor.ir_left_1) b0 = 100; else b0 = 0;
    if(sensor.ir_right_1) b1 = 100; else b1 = 0;
    if(sensor.ir_right_2) g1 = 100; else g1 = 0;
    if(sensor.ir_right_3) r1 = 100; else r1 = 0;
    if(sensor.ir_mid) r0=r1=g0=g1=b0=b1 = 100;
        
    pixels.setPixelColor(0, pixels.Color(r0,g0,b0)); //设定第一个灯珠颜色RGB(0~255)
    pixels.setPixelColor(1, pixels.Color(r1,g1,b1)); //设定第二个灯珠颜色
    pixels.show();  //显示设定好的颜色
    delay(1);       //必须加入延时否则WS2811可能无法正常显示
}
