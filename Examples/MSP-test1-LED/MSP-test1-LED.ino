#include <TREEE_TEAS1_MSP.h>

#define PIN            5
#define NUMPIXELS      2
WS2811Driver pixels = WS2811Driver(NUMPIXELS, PIN, NEO_GRB);

void setup() 
{
    pixels.begin();     //彩色灯珠初始化
}
void loop()
{
    pixels.setPixelColor(0, pixels.Color(100,0,0)); //设定第一个灯珠颜色RGB(0~255)
    pixels.setPixelColor(1, pixels.Color(100,0,0)); //设定第二个灯珠颜色
    pixels.show();  //显示设定好的颜色
    delay(1000);    //延迟1秒
    pixels.setPixelColor(0, pixels.Color(0,100,0));
    pixels.setPixelColor(1, pixels.Color(0,100,0));
    pixels.show();
    delay(1000);
    pixels.setPixelColor(0, pixels.Color(0,0,100));
    pixels.setPixelColor(1, pixels.Color(0,0,100));
    pixels.show();
    delay(1000);
}
