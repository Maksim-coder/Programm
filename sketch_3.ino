#include "Arduino.h"
#include <Servo.h>
#include "Motor.h"
#include "BrushlessMotor.h"
#include "LevelMotor.h"
#include "Manipulator.h"
#include "Rotarycamera.h"
#include "Timer.h"
BrushlessMotor motor(7);
BrushlessMotor motor2(5);

void setup()
{
  objCommunicator.init();
  motor.init();
  motor2.init();
  delay(10000);
}
void loop()
{
  objCommunicator.read();
  motor.write(objCommunicator.retry());
  motor2.write(objCommunicator.retry());
}
