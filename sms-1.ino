#include <SoftwareSerial.h>
#include <TinyGPS.h>

int state = 0;
const int pin = 9;
float gpslat, gpslon;

TinyGPS gps;
SoftwareSerial sgps(4, 5);
SoftwareSerial sgsm(2, 3);

void setup()
{
  sgsm.begin(9600);
  sgps.begin(9600);
}

void loop()
{
  while (sgps.available())
  {
    int c = sgps.read();
    if (gps.encode(c))
    {
      gps.f_get_position(&gpslat, &gpslon);
    }
  }
    if (digitalRead(pin) == HIGH && state == 0) {
      delay(1000);
      sgsm.print("AT+CMGF=1");
      delay(1000);
      sgsm.print("AT+CMGS=\"+919429537567\"");
      delay(1000);
      sgsm.print("Accident has been detected with your vehicle no.: XXXXX. The location of the accident spot is:");
      sgsm.print("Latitude :");
      sgsm.println(gpslat, 6);
      sgsm.print("Longitude:");
      sgsm.println(gpslon, 6);
      sgsm.println("This message is sent to emergency department");
      delay(1000);
      sgsm.write(0x1A);
      delay(1000);
      state = 1;
    }
  if (digitalRead(pin) == LOW) {
      state = 0;
    }
  }
