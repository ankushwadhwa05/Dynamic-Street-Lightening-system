// Pin Definitions
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 6; // Must be a PWM pin

// Constants
const int DIM_LEVEL = 51;  // 20% of 255 (Max PWM)
const int BRIGHT_LEVEL = 204; // 80% of 255
const int DETECTION_DISTANCE = 50; // Distance in cm to trigger lights

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Logic for Light Intensity
  if (distance > 0 && distance < DETECTION_DISTANCE) {
    // Vehicle detected
    analogWrite(ledPin, BRIGHT_LEVEL);
    delay(5000); // Keep lights bright for 5 seconds
  } else {
    // Idle state
    analogWrite(ledPin, DIM_LEVEL);
  }

  delay(100);
}