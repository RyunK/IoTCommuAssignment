// 버튼으로 On/Off 구현
// 가변저항으로 R,G,B값 조절 구현
// 가변저항으로 밝기 조절 구현

// 구현해야 할 것 ----
// 가변저항으로 LED 칸 조절


#include <Adafruit_NeoPixel.h>

/* NeoPixel LED : 3, 4번 핀
* Switch : 6번 핀
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

}

void loop(){

  Rval = map(analogRead(RPoten), 0, 1023, 0, 255);
  Gval = map(analogRead(GPoten), 0, 1023, 0, 255);
  Bval = map(analogRead(BPoten), 0, 1023, 0, 255);
  bright_val = map(analogRead(BPoten), 0, 1023, 1, 5);
  
    if (digitalRead(Button) == 0)
  {
    if(flag == true) 
      flag = false;
    else             
      flag = true;
  }

  if (flag == true)
  {
    for(int i=0; i<8; i++) {
     LED3.setPixelColor(i, Rval, Gval, Bval);
     LED3.setBrightness(250/bright_val);
     LED3.show();
     LED4.setPixelColor(i, Rval, Gval, Bval);
     LED4.setBrightness(250/bright_val);
     LED4.show();
    }
  }
  else if (flag == false)
  {
    LED3.clear();
    LED3.show();
    LED4.clear();
    LED4.show();
  }


  
}
