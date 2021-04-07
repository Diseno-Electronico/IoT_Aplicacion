
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "NGtI6jmGFpjUd_vMiKrGsndg4GWAFQck";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "israel2.4g";
char pass[] = "israel1332";

WidgetLED led1(V1);

BlynkTimer timer;
const int sensorPin= A0; 
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}
// V1 LED Widget is blinking
void blinkLedWidget()
{
  if (led1.getValue()) {
    led1.off();
    Serial.println("LED on V1: off");
  } else {
    led1.on();
    Serial.println("LED on V1: on");
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  timer.setInterval(1000L, blinkLedWidget);
  
}

void loop()
{
  Blynk.run();
  int value = analogRead(sensorPin);
float valor=((value *14451) /1023);
  
   Blynk.virtualWrite(V0, "Temperatura: " + String(valor) + " ºC" );
}
