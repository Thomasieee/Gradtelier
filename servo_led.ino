#include <SPI.h>
#include <WiFiNINA.h>
#include <WiFiServer.h>
#include <Servo.h>

char ssid[] = "thomsieee";     // your network SSID (name)
char pass[] = "1122334466";    // your network password
WiFiServer server(80);

Servo myServo;  // create servo object to control a servo

void setup() {
  pinMode(2, OUTPUT); // LED connected to D2
  myServo.attach(10);  // attaches the servo on pin D10 to the servo object
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  server.begin();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    Serial.print("Received request: "); // Add this line
    Serial.println(request);
    client.flush();

    if (request.indexOf("/LED=BLINK") != -1) {
      digitalWrite(2, HIGH);
      delay(200); // Wait for 500 milliseconds
      digitalWrite(2, LOW);
      Serial.println("LED Blinked");
    }

    if (request.indexOf("/SERVO=MOVE") != -1) {
      myServo.write(90); // Move servo to 90 degrees
      delay(500); // Wait for 1 second
      myServo.write(0);  // Move servo back to 0 degrees
      Serial.println("Servo Moved");
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<body>");
    client.println("<h1>LED and Servo Control</h1>");
    client.println("</body>");
    client.println("</html>");
    client.stop();
  }
}
