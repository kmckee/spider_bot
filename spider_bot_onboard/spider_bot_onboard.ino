
const int positiveForForwardPin =  8;
const int positiveForBackwardPin = 7;
const int positiveForRightPin = 6;
const int positiveForLeftPin = 5;

const int LEFT = 97;
const int BACK = 115;
const int RIGHT = 100;
const int FORWARD = 119;

void setup() {
  // set the digital pin as output:
  Serial.begin(9600);
  pinMode(positiveForForwardPin, OUTPUT);      
  pinMode(positiveForBackwardPin, OUTPUT); 
  pinMode(positiveForRightPin, OUTPUT);      
  pinMode(positiveForLeftPin, OUTPUT); 
}


void loop()
{
  if (Serial.available()) {
    byte incomingByte = Serial.read();
    Serial.println(incomingByte);
    switch (incomingByte) {
      case LEFT:
        rotateLeft();
        break;
      case RIGHT:
        rotateRight();
        break;
      case BACK:
        moveBackward();
        break;
      case FORWARD:
        moveForward();
        break;
    }  
  }
}

void rotateRight(){
  engageMotor(positiveForRightPin, positiveForLeftPin);
}

void rotateLeft()
{
  engageMotor(positiveForLeftPin, positiveForRightPin);
}

void moveForward(){
  engageMotor(positiveForForwardPin, positiveForBackwardPin);
}

void moveBackward(){
  engageMotor(positiveForBackwardPin, positiveForForwardPin);
}

void engageMotor(int highPin, int lowPin){
  digitalWrite(lowPin, LOW);
  digitalWrite(highPin, HIGH);
  delay(100);
  digitalWrite(highPin, LOW);
}




