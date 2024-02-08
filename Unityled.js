using System.Collections;
using System.IO.Ports;
using UnityEngine;
using UnityEngine.UI;

public class LEDControl : MonoBehaviour {
    SerialPort serialPort = new SerialPort("COM3", 9600); // Adjust the COM port and baud rate as needed

    void Start() {
        serialPort.Open(); // Open the serial port
        serialPort.ReadTimeout = 50;
    }

    public void TurnOnLED() {
        if (serialPort.IsOpen) {
            serialPort.Write("1"); // Send '1' to turn on the LED
        }
    }

    public void TurnOffLED() {
        if (serialPort.IsOpen) {
            serialPort.Write("0"); // Send '0' to turn off the LED
        }
    }

    void OnDestroy() {
        if (serialPort != null && serialPort.IsOpen) {
            serialPort.Close(); // Close the serial port when the application closes
        }
    }
}
