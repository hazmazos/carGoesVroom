#include <Servo.h>

// Motor pins - to fill
int ML1 ;
int ML2 ;
int MR1 ;
int MR2 ;

// IR Sensors 
int L ;
int R  ;

int lSensorValue;
int rSensorValue;

int last =0;

//Ultrasound
int TRIG;
int ECHO;

//Servo
int servoPin;
Servo servo;

int angles[] = {0, 30, 90, 150, 180};

int obstacle = 12; //might need to adjust

void setup() {
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  servo.attach(servoPin);
  servo.write(90);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  int distances[5];

  for (int i = 0; i < 5; i++) {
  servo.write(angles[i]);
  delay(200); 
  distances[i] = getDistance();
  }

  int leftAvg   = (distances[0] + distances[1]) / 2;
  int centerVal = distances[2];
  int rightAvg  = (distances[3] + distances[4]) / 2;

  if (centerVal < obstacle) {
  backward();
  delay(400);
  turnLeft();
  delay(400);
  }

  else if (centerVal >= leftAvg && centerVal >= rightAvg) {
    forward();
    delay(300);
  }
  else if (leftAvg > rightAvg) {
    turnLeft();
    delay(300);
  } 
  else {
    turnRight();
    delay(300);
  }
  stopRobot();
  delay(100); 
}


void forward() {
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW);
}

void backward() {
  digitalWrite(ML1, LOW);
  digitalWrite(ML2, HIGH);
  digitalWrite(MR1, LOW); 
  digitalWrite(MR2, HIGH);
}

void stopRobot() {
  digitalWrite(ML1, LOW);
  digitalWrite(ML2, LOW);
  digitalWrite(MR1, LOW);
  digitalWrite(MR2, LOW);
}

void turnLeft() {
  digitalWrite(ML1, LOW);
  digitalWrite(ML2, HIGH);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW);
}

void turnRight() {
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW);
  digitalWrite(MR1, LOW);
  digitalWrite(MR2, HIGH);
}

long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 25000);
  if (duration == 0) return 300;
  return duration * 0.034 / 2;
}