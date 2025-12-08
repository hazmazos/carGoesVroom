// Motor pins - to fill
int ML1 ;
int ML2 ;
int MR1 ;
int MR2 ;

// IR Sensors pins
int L = ;
int R = ;

int lSensorValue;
int rSensorValue;

int last =0;

void setup() {
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);

  pinMode(L, INPUT)
  pinMode(R, INPUT)

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lSensorValue = digitalRead(L);
  rSensorValue = digitalRead(R);

  if(lSensorValue==LOW && rSensorValue==LOW){
    forward()
  }
  else if(lSensorValue==LOW && rSensorValue==HIGH){
    turnLeft()
    last = -1;
  }
  else if(lSensorValue==HIGH && rSensorValue==LOW){
    turnRight()
    last=1;
  }
  else{
    if(last<=0){
      turnLeft()
    }
    else{
      turnRight()
    }
  }
  
}


void forward() {
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW);
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
