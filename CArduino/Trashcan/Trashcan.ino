#include <Servo.h>
#include <cvzone.h>

SerialData serialData(1,1);

int valsRec[1];

Servo servo_6;

Servo servo_9;

Servo servo_10;

Servo servo_11;

void Default()
{
  servo_6.write(0);

  servo_9.write(0);
  
  delay(1000);

  servo_10.write(0);
  
  delay(1000);

  servo_11.write(0);
  
  delay(1000);
}

void setup()
{
  valsRec[0] = 0;

  serialData.begin();

  servo_6.attach(6);

  servo_9.attach(9);

  servo_10.attach(10);

  servo_11.attach(11);
  
  Default();
  
}

void loop()
{
    serialData.Get(valsRec);

    if (valsRec[0] != 0) 
    {
      if (valsRec[0] == 1) {
        servo_10.write(37);
      }
      if (valsRec[0] == 2) {
        servo_11.write(37);
      }
      delay(2000);
      servo_6.write(90);
      servo_9.write(90);
    }
    delay(3000);
    Default();

    valsRec[0] = 0;
}

