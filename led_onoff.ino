const int ledPin = 2; // LED connected to digital pin 2

void setup() {
    pinMode(ledPin, OUTPUT); // Set the LED pin as output
    Serial.begin(9600); // Start serial communication at 9600 baud
}

void loop() {
    if (Serial.available() > 0) {
        char receivedChar = Serial.read(); // Read the incoming data
        if (receivedChar == '1') {
            digitalWrite(ledPin, HIGH); // Turn LED on
        } else if (receivedChar == '0') {
            digitalWrite(ledPin, LOW); // Turn LED off
        }
    }
}
