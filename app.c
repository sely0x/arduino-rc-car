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
  servo.attach(7);
  Serial.begin(9600);
  BTSerial.begin(9600);
  prinMode(8, OUTPUT);
  
  pinMode(EA, OUTPUT);
  pinMode(EB, OUTPUT);
  pinMode(M_IN1, OUTPUT);
  pinMode(M_IN2, OUTPUT);
  pinMode(M_IN3, OUTPUT);
  pinMode(M_IN4, OUTPUT);
}

void loop() {
  if(BTSerial.available()){
    byte data = BTSerial.read();
    Serial.write(data);

    if(data == '1'){
      // 서보 모터 중앙
    }

    if(data == '2'){
      // 서보 모터 왼쪽
    }

    if(data == '3'){
      // 서보 모터 오른쪽
    }

    if(data == '4'){
      // 후진
    }

    if(data == '5'){
      // DC 전진, 후진 토글
    }
  }
  /* digitalWrite(EA, HIGH);
  digitalWrite(M_IN1, mav);
  digitalWrite(M_IN2, !mav);  전진

  digitalWrite(EB, HIGH);
  digitalWrite(M_IN3, mbv);
  digitalWrite(M_IN4, !mbv);  전진
  delay(5000);

  digitalWrite(EA, LOW);
  digitalWrite(M_IN1, LOW);
  digitalWrite(M_IN2, LOW);  정지

  digitalWrite(EB, LOW);
  digitalWrite(M_IN3, LOW);
  digitalWrite(M_IN4, LOW);  정지
  delay(5000); */
}
