#include <Servo.h>

// Left sensor and servo
const int trigPinLeft = 10;
const int echoPinLeft = 11;
Servo leftServo;

// Right sensor and servo
const int trigPinRight = 4;
const int echoPinRight = 5;
Servo rightServo;

void setup() {
  Serial.begin(9600);

  // Attach servos
  leftServo.attach(12);   // Update to your left servo pin
  rightServo.attach(2);  // Update to your right servo pin

  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);
  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);
}

void loop() {
  for (int angle = 15; angle <= 165; angle++) {
    leftServo.write(angle);
    rightServo.write(angle);
    delay(15);  // Allow servos to move

    int leftDistance = measureDistance(trigPinLeft, echoPinLeft);
    int rightDistance = measureDistance(trigPinRight, echoPinRight);

    Serial.print("L:");
    Serial.print(angle);
    Serial.print(",");
    Serial.print(leftDistance);
    Serial.print(";R:");
    Serial.print(angle);
    Serial.print(",");
    Serial.println(rightDistance);

    delay(100);
  }

  for (int angle = 165; angle >= 15; angle--) {
    leftServo.write(angle);
    rightServo.write(angle);
    delay(15);

    int leftDistance = measureDistance(trigPinLeft, echoPinLeft);
    int rightDistance = measureDistance(trigPinRight, echoPinRight);

    Serial.print("L:");
    Serial.print(angle);
    Serial.print(",");
    Serial.print(leftDistance);
    Serial.print(";R:");
    Serial.print(angle);
    Serial.print(",");
    Serial.println(rightDistance);

    delay(100);
  }
}

int measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}
