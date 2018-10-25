// https://jeelabs.org/2011/05/22/atmega-memory-use/

int incomingByte = 0; // For incoming serial data.

int freeRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

void setup() {
  // put your setup code here, to run once:
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  //Serial.println(voltage);
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" - ");
  Serial.print("RAM Usage: ");
  Serial.println(freeRam());
}
