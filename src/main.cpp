#include <Arduino.h>

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  // while serial is not available wait
  Serial.println("Waiting for serial connection...");
  delay(5000);
  Serial.println("Serial connected");

  pinMode(A15, OUTPUT); // IN1
  pinMode(A16, OUTPUT); // IN2
  pinMode(A17, OUTPUT); // IN3
  pinMode(A19, OUTPUT); // IN4
}

void loop() {
  char *buffer = (char *)calloc(50, sizeof(char));
  // 50 bytes
  Serial.print("empty buffer: ");
  Serial.println(buffer);
  Serial.print("address of buffer: ");
  Serial.printf("%p\n", buffer);
  sleep(1);
  sprintf(buffer, "Forward %d", 1);
  //  c string interpolation or formating "Forward 1"
  Serial.println(buffer);
  sleep(4);
  free(buffer);
  // put your main code here, to run repeatedly:
  digitalWrite(A15, HIGH); // IN1
  digitalWrite(A16, LOW);  // IN2
  digitalWrite(A17, LOW);  // IN3
  digitalWrite(A19, HIGH); // IN4
}


// 000000 000000 0000000 000000 000000 00000 0000 0000