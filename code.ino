#define BLYNK_TEMPLATE_ID "TMPLqINVp74H"
#define BLYNK_DEVICE_NAME "Scam"
#define BLYNK_AUTH_TOKEN "sQh5bsbcpG9T9hpwLK7eT7lW9oOwE1xQ"
#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>


char auth[] = BLYNK_AUTH_TOKEN ;
int  pinValuex = 0;
int  pinValuey = 0;
char ssid[] = "OPPORTUNITY";
char pass[] = "12345679";

#define xstp 9
#define xdir 8

#define ystp 10
#define ydir 11
int x;

#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600
ESP8266 wifi(&EspSerial);


BLYNK_WRITE(V13)
{
  pinValuex = param.asInt();

}
BLYNK_WRITE(V14)
{
  pinValuey = param.asInt();

}
void setup()
{
  // Debug console
  Serial.begin(115200);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(1000);

  Blynk.begin(auth, wifi, ssid, pass);

  pinMode(xstp, OUTPUT);
  pinMode(xdir, OUTPUT);
  pinMode(ystp, OUTPUT);
  pinMode(ydir, OUTPUT);


}

void loop()
{
  Blynk.run(); 
  delay(200);
  Blynk.syncVirtual(V13, V14);

  if (pinValuex > 0 &&  pinValuey > 0)
  {
    digitalWrite(xdir, HIGH);
    digitalWrite(ydir, HIGH );
    for (x = 0; x < 800; x++)
    {
      digitalWrite(xstp, HIGH);
      digitalWrite(ystp, HIGH);
      delay(1);
      digitalWrite(xstp, LOW);
      digitalWrite(ystp, LOW);
      delay(1);
    }
  }
  else if (pinValuex > 0 && pinValuey < 0) {
    digitalWrite(xdir, HIGH);
    digitalWrite(ydir, LOW);
    for (x = 0; x < 800; x++)
    {
      digitalWrite(xstp, HIGH);
      digitalWrite(ystp, HIGH);
      delay(1);
      digitalWrite(xstp, LOW);
      digitalWrite(ystp, LOW);
      delay(1);
    }
  }
  else if (pinValuex < 0 && pinValuey > 0) {
    digitalWrite(ydir, HIGH);
    digitalWrite(xdir, LOW);
    for (x = 0; x < 800; x++)
    {
      digitalWrite(xstp, HIGH);
      digitalWrite(ystp, HIGH);
      delay(1);
      digitalWrite(xstp, LOW);
      digitalWrite(ystp, LOW);
      delay(1);
    }
  }
  else if (pinValuex < 0 && pinValuey < 0) {
    digitalWrite(ydir, LOW);
    digitalWrite(xdir, LOW);
    for (x = 0; x < 800; x++)
    {
      digitalWrite(xstp, HIGH);
      digitalWrite(ystp, HIGH);
      delay(1);
      digitalWrite(xstp, LOW);
      digitalWrite(ystp, LOW);
      delay(1);
    }

  }
  else if (pinValuex == 0 && pinValuey < 0) {
    digitalWrite(ydir, LOW);
    //    digitalWrite(xdir, LOW);
    for (x = 0; x < 800; x++)
    {
      //      digitalWrite(xstp, HIGH);
      digitalWrite(ystp, HIGH);
      delay(1);
      digitalWrite(xstp, LOW);
      digitalWrite(ystp, LOW);
      delay(1);
    }

  }
  else if (pinValuex == 0 && pinValuey > 0) {
    digitalWrite(ydir, HIGH);
    //    digitalWrite(xdir, LOW);
    for (x = 0; x < 800; x++)
    {
      //      digitalWrite(xstp, HIGH);
      digitalWrite(ystp, HIGH);
      delay(1);
      digitalWrite(xstp, LOW);
      digitalWrite(ystp, LOW);
      delay(1);
    }

  }
  else if (pinValuex > 0 && pinValuey == 0) {
    //    digitalWrite(ydir, HIGH);
    digitalWrite(xdir, HIGH);
    for (x = 0; x < 800; x++)
    {
      //      digitalWrite(xstp, HIGH);
      digitalWrite(xstp, HIGH);
      delay(1);
      digitalWrite(xstp, LOW);
      digitalWrite(ystp, LOW);
      delay(1);
    }

  }
  else if (pinValuex < 0 && pinValuey == 0) {
    //    digitalWrite(ydir, HIGH);
    digitalWrite(xdir, LOW);
    for (x = 0; x < 800; x++)
    {
      //      digitalWrite(xstp, HIGH);
      digitalWrite(xstp, HIGH);
      delay(1);
      digitalWrite(xstp, LOW);
      digitalWrite(ystp, LOW);
      delay(1);
    }

  }
  else
  { digitalWrite(ydir, LOW);
    digitalWrite(xdir, LOW);
    digitalWrite(xstp, LOW);
    digitalWrite(ystp, LOW);
    delay(100);
  }
  delay(100);



}
