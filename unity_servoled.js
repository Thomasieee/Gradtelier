using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using UnityEngine.Networking;

public class LEDmotor : MonoBehaviour
{
    string baseUrl = "http://192.168.43.222"; // Replace with your Arduino's IP address

    public void BlinkLED()
    {
        StartCoroutine(SendCommand("/LED=BLINK"));
    }

    public void MoveServo()
    {
        StartCoroutine(SendCommand("/SERVO=MOVE"));
    }

    IEnumerator SendCommand(string command)
    {
        using (UnityWebRequest webRequest = UnityWebRequest.Get(baseUrl + command))
        {
            yield return webRequest.SendWebRequest();
            if (webRequest.isNetworkError || webRequest.isHttpError)
            {
                Debug.Log(webRequest.error);
            }
        }
    }
}
