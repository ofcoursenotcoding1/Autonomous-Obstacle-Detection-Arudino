// C++ code
//
#include <Servo.h>

int leftdisk = 0;

int frondisk = 0;

int rightdisk = 0;

Servo servo_9;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  servo_9.attach(9, 500, 2500);
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  servo_9.write(90);
  delay(1000); // Wait for 1000 millisecond(s)
  frondisk = 0.01723 * readUltrasonicDistance(11, 10);
  if (frondisk < 20) {
    // moving forward
    Serial.println("forward");
    servo_9.write(90);
    delay(1000); // Wait for 1000 millisecond(s)
    analogWrite(6, 255);
    analogWrite(5, 255);
    digitalWrite(8, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(3, LOW);
  } else {
    // 1st stop
    Serial.println("1st stop");
    servo_9.write(90);
    analogWrite(6, 0);
    analogWrite(5, 0);
    digitalWrite(8, LOW);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
    digitalWrite(3, LOW);
    delay(2000); // Wait for 2000 millisecond(s)
    // 1 reverse
    Serial.println("1 reverse");
    servo_9.write(90);
    analogWrite(6, 127);
    analogWrite(5, 127);
    digitalWrite(8, LOW);
    digitalWrite(4, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(3, HIGH);
    delay(2000); // Wait for 2000 millisecond(s)
    leftdisk = 0.01723 * readUltrasonicDistance(13, 12);
    rightdisk = 0.01723 * readUltrasonicDistance(A0, A1);
    if (leftdisk < 20 && rightdisk >= 20) {
      // right
      Serial.println("forward");
      servo_9.write(0);
      delay(1000); // Wait for 1000 millisecond(s)
      analogWrite(6, 127);
      analogWrite(5, 127);
      digitalWrite(8, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(3, LOW);
      delay(2000); // Wait for 2000 millisecond(s)
    } else {
      if (leftdisk > 20 && rightdisk < 20) {
        // left
        Serial.println("left");
        servo_9.write(180);
        delay(1000); // Wait for 1000 millisecond(s)
        analogWrite(6, 127);
        analogWrite(5, 127);
        digitalWrite(8, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(3, LOW);
        delay(2000); // Wait for 2000 millisecond(s)
      } else {
        // 2nd stop
        Serial.println("2nd stop");
        servo_9.write(90);
        analogWrite(6, 0);
        analogWrite(5, 0);
        digitalWrite(8, LOW);
        digitalWrite(4, LOW);
        digitalWrite(7, LOW);
        digitalWrite(3, LOW);
        delay(2000); // Wait for 2000 millisecond(s)
        // 2 reverse
        Serial.println("2 reverse");
        servo_9.write(90);
        analogWrite(6, 127);
        analogWrite(5, 127);
        digitalWrite(8, LOW);
        digitalWrite(4, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(3, HIGH);
        delay(2000); // Wait for 2000 millisecond(s)
        // uturn
        Serial.println("uturn ");
        servo_9.write(90);
        analogWrite(6, 127);
        analogWrite(5, 127);
        digitalWrite(8, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(7, LOW);
        digitalWrite(3, HIGH);
        delay(3000); // Wait for 3000 millisecond(s)
      }
    }
  }

  Serial.println(0);

  Serial.println(0);

  //

  analogWrite(3, 0);

  //
}