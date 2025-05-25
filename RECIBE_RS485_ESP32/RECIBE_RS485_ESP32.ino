#include <HardwareSerial.h>

// Define UART and GPIO pins
#define UART_NUM      1          // Use UART1
#define RX_PIN        20         // GPIO20 for RX
#define TX_PIN        -1         // TX not used in simplex receive mode

HardwareSerial SerialRS485(UART_NUM);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  Serial.println("RS485 Simplex Receiver Test");

  // Initialize RS485 serial port for RX only
  SerialRS485.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);
}

void loop() {
  if (SerialRS485.available()) {
    // Read incoming data
    String data = SerialRS485.readString();
    Serial.print("Received: ");
    Serial.println(data);
  }

  delay(10); // Small delay for stability
}
