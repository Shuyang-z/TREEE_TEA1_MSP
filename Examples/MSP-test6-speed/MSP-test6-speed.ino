#include <TREEE_TEAS1_MSP.h>

#define PIN            5
#define NUMPIXELS      2
WS2811Driver pixels = WS2811Driver(NUMPIXELS, PIN, NEO_GRB);

void setup() 
{
    shift_reg_init();   //传感器初始化
    motor_init();       //电机初始化
    pixels.begin();     //彩色灯珠初始化

    pixels.setPixelColor(0, pixels.Color(0,100,0));
    pixels.setPixelColor(1, pixels.Color(0,100,0));
    pixels.show();
    delay(1);  //必须加入延时否则WS2811可能无法正常显示
}
void loop()                                                                             
{
    static int state = 1;
    static int state_now = 0;
    reload_shift_reg(); //刷新传感器数据(必须)

    if(left_pulse%2)    //显示测速状态
        pixels.setPixelColor(0, pixels.Color(0,0,100));
    else
        pixels.setPixelColor(0, pixels.Color(0,100,0));
    if(right_pulse%2)
        pixels.setPixelColor(1, pixels.Color(0,0,100));
    else
        pixels.setPixelColor(1, pixels.Color(0,100,0));
    pixels.show();
    
    if(sensor.switcher_back_right)  //车体以左轮为圆心旋转360度
    {
        motor_step(0,150,0,48);//左转48个刻度
        motor_step(0,0);//停止
    }

    if(sensor.switcher_back_left)   //车体以右轮为圆心旋转360度
    {
        motor_step(150,0,48,0);//左转48个刻度
        motor_step(0,0);//停止
    }
}
