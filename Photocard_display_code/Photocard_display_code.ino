// 버튼으로 On/Off 구현
// 가변저항으로 R,G,B값 조절 구현
// 가변저항으로 밝기 조절 구현

// 구현해야 할 것 ----
// 가변저항으로 LED 칸 조절


#include <Adafruit_NeoPixel.h>

/* NeoPixel LED : 3, 4번 핀
* Switch : 2번 핀
* 
* <가변 저항>
* R : A1
* G : A2
* B : A3
* 밝기 : A4
* LED 칸 조절 : A5
*/

#define RPoten A1
#define GPoten A2
#define BPoten A3
#define Brightness_Pin A4
#define On_LED A5

#define Button 6

int Rval = 0;
int Gval = 0;
int Bval = 0;

int bright_val = 5;
int cnt = 8;

bool flag = false;
int state = 0;


Adafruit_NeoPixel LED3 = Adafruit_NeoPixel(8, 3, NEO_GRB);
Adafruit_NeoPixel LED4 = Adafruit_NeoPixel(8, 4, NEO_GRB);

void setup() {
  
  pinMode(Button, INPUT);
  
  LED3.begin();
  LED3.setBrightness(50);
  LED3.clear();
  LED4.begin();
  LED4.setBrightness(50);
  LED4.clear();

  attachInterrupt(0, Push, RISING);

}

void Push()
{
  flag = !flag;

  if(flag == true)
  {
    state = 0;
  }
}

void loop(){

  Rval = map(analogRead(RPoten), 0, 1023, 0, 255);
  Gval = map(analogRead(GPoten), 0, 1023, 0, 255);
  Bval = map(analogRead(BPoten), 0, 1023, 0, 255);
  bright_val = map(analogRead(Brightness_Pin), 0, 1023, 2, 5);
  

  if (flag == true )
  {
    for(int i=0; i<8; i++) {
     LED3.setPixelColor(i, Rval, Gval, Bval);        
     LED4.setPixelColor(i, Rval, Gval, Bval);
    }
    switch(bright_val)
    {
      case 2:
        LED4.setBrightness(20);
        LED3.setBrightness(20);
        break;
      case 3:
        LED4.setBrightness(130);
        LED3.setBrightness(130);
        break;
      case 4:
        LED4.setBrightness(250);
        LED3.setBrightness(250);
        break;
      default :
        break;
    }
    //LED4.setBrightness(250-250/bright_val);
    //LED3.setBrightness(250-250/bright_val);
    //LED4.setBrightness(50);
    //LED3.setBrightness(50);
    LED3.show();
    LED4.show();
    //delay(1000);
  }
  else if (flag == false && state == 0)
  {
    LED3.clear();
    LED3.show();
    LED4.clear();
    LED4.show();
    state = 1;
  }
  else if(flag == false && state == 1)
  {

  }


  
}
