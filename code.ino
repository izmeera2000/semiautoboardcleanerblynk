#define BLYNK_TEMPLATE_ID "TMPLqINVp74H"
#define BLYNK_DEVICE_NAME "Scam"
#define BLYNK_AUTH_TOKEN "sQh5bsbcpG9T9hpwLK7eT7lW9oOwE1xQ"
#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

char auth[] = BLYNK_AUTH_TOKEN ;
int  pinValuex = 0;
int  pinValuey = 0;
int servoq = 0;
char ssid[] = "OPPORTUNITY";
char pass[] = "12345679";
int pos = 0;    // variable to store the servo position
int pos1 = 90;
#define xstp 9
#define xdir 8

#define ystp 10
#define ydir 11
int x;

// Hardware Serial on Mega, Leonardo, Micro...
#define EspSerial Serial1

// or Software Serial on Uno, Nano...
//#include <SoftwareSerial.h>
//SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

BLYNK_WRITE(V0)
{
  servoq = param.asInt();
  if (servoq == 1)
  {

    Serial.println(" 1 ");

    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree

      myservo.write(pos1);              // tell servo to go to position in variable 'pos'
      pos1++;
      delay(1);                       // waits 15 ms for the servo to reach the position

    }
  }
  else
  {
    Serial.println(" 2 ");

    for (pos = 90; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos1);              // tell servo to go to position in variable 'pos'
      pos1--;

      delay(1);                       // waits 15 ms for the servo to reach the position
      //      Serial.println("ISAP KOTE");
    }
  }
}



BLYNK_WRITE(V1)
{
  pinValuex = param[0].asInt();
  pinValuey = param[1].asInt();


  Serial.print(pinValuex);
  Serial.println("x");

  Serial.print(pinValuey);
  Serial.println("y");

  if (pinValuex > 128 &&  pinValuey > 128)
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
  else if (pinValuex > 128 && pinValuey < 128) {
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
  else if (pinValuex < 128 && pinValuey > 128) {
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
  else if (pinValuex < 128 && pinValuey < 128) {
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
  else if (pinValuex == 128 && pinValuey < 128) {
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
  else if (pinValuex == 128 && pinValuey > 128) {
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
  else if (pinValuex > 128 && pinValuey == 128) {
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
  else if (pinValuex < 128 && pinValuey == 128) {
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
//BLYNK_WRITE(V14)
//{
//
//}
void setup()
{
  // Debug console
  Serial.begin(115200);
  myservo.attach(2);  // attaches the servo on pin 9 to the servo object

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(1000);

  Blynk.begin(auth, wifi, ssid, pass);

  pinMode(xstp, OUTPUT);
  pinMode(xdir, OUTPUT);
  pinMode(ystp, OUTPUT);
  pinMode(ydir, OUTPUT);

  Blynk.virtualWrite(V4, 1);
  Blynk.virtualWrite(V0, 0);

}

void loop()
{
  Blynk.run();
  //  Blynk.syncVirtual(V1);


}
