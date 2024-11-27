#include <Servo.h>
Servo servo;
int deg = 0;

#define EA 3
#define EB 11
#define M_IN1 4
#define M_IN2 5
#define M_IN3 13
#define M_IN4 12
int mav = 1;
int mbv = 1;

void setup() {
  // put your setup code here, to run once:
  servo.attach(7);
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(8, OUTPUT);
  
  pinMode(EA, OUTPUT);
  pinMode(EB, OUTPUT);
  pinMode(M_IN1, OUTPUT);
  pinMode(M_IN2, OUTPUT);
  pinMode(M_IN3, OUTPUT);
  pinMode(M_IN4, OUTPUT);
}

int a = 8;

int ag = 90;

void left(int x){
  for(int angle = 90 + a; angle <= 90+x + a; angle++) {
    servo.write(angle);
    delay(10); 
  }
}

void right(int x){
  for(int angle = 90 + a; angle >= 90-x + a; angle--) {
    servo.write(angle); 
    delay(10); 
  }
}

int ret(int x){
    if(x > 90){
      for(int angle = x + a; angle >= 90 + a; angle--) {
        servo.write(angle); 
        delay(10); 
      }
      return 1;
    } else if(x == 90){
      return 0;
    } else {
      for(int angle = x + a; angle <= 90 + a; angle++) {
        servo.write(angle);
        delay(10); 
      }
      return 1;
    }
}

int fb = 0; // 1 - front, 0 - back

int temp = 20;

bool isrunning = false;

void loop() {
  if(BTSerial.available()){
    byte data = BTSerial.read();
    Serial.write(data);

    if(data == '1'){
      ret(ag);
      ag = 90;
      fb = 1;
    }

    if(data == '2'){
      left(temp);
      ag = ag + temp
    }

    if(data == '3'){
      right(temp);
      ag = ag + temp
    }

    if(data == '4'){
      fb = 0;
    }

    if(data == '5'){
      if(isrunning){
        digitalWrite(EA, LOW);
        digitalWrite(M_IN1, LOW); 
        digitalWrite(M_IN2, LOW);  
      
        digitalWrite(EB, LOW);
        digitalWrite(M_IN3, LOW);
        digitalWrite(M_IN4, LOW);  
      } else {
        digitalWrite(EA, HIGH);
        digitalWrite(M_IN1, fb * mav);
        digitalWrite(M_IN2, fb * !mav);  
      
        digitalWrite(EB, HIGH);
        digitalWrite(M_IN3, fb * mbv);
        digitalWrite(M_IN4, fb * !mbv);  
      }
    }
  }
}
