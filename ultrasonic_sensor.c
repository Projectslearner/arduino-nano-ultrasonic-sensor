/*
    Project name : Ultrasonic Sensor
    Modified Date: 12-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-nano-ultrasonic-sensor
*/

#define trigPin 9 // Trigger pin of the ultrasonic sensor connected to digital pin 9
#define echoPin 10 // Echo pin of the ultrasonic sensor connected to digital pin 10

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(trigPin, OUTPUT); // Set trigger pin as OUTPUT
  pinMode(echoPin, INPUT); // Set echo pin as INPUT
}

void loop() {
  long duration, distance; // Variables to store the duration of the ultrasonic wave and calculated distance

  // Send a short pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo signal
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters (assuming speed of sound is 343m/s)
  distance = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000); // Wait for a short interval before taking another measurement
}
