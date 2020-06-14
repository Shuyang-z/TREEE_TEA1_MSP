#include <TREEE_TEAS1_MSP.h>

#define PIN            5
#define NUMPIXELS      2
WS2811Driver pixels = WS2811Driver(NUMPIXELS, PIN, NEO_GRB);

void setup() 
{
    shift_reg_init();   //传感器初始化
    motor_init();       //电机初始化
    pixels.begin();     //彩色灯珠初始化
}
void loop()                                                                             
{
    static int motor_right;
    static int motor_left;
    reload_shift_reg(); //刷新传感器数据(必须)
    if(sensor.key_1)
    {
        while(sensor.key_1) reload_shift_reg(); //消抖
        delay(20);
        if(motor_right == 0)
            motor_right = 150;
        else if(motor_right == 150)
            motor_right = -150;
        else if(motor_right == -150)
            motor_right = 0;
    }
    if(sensor.key_2)
    {
        while(sensor.key_2) reload_shift_reg(); //消抖
        delay(20);
        if(motor_left == 0)
            motor_left = 150;
        else if(motor_left == 150)
            motor_left = -150;
        else if(motor_left == -150)
            motor_left = 0;
    }
    motor_set_PWM(motor_left,motor_right); //设定电机速度(左,右)(0~255)
}
