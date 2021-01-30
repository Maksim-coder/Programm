#include "Rotarycamera.h"
#include <Servo.h>
#include "Timer.h"
RotaryCamera::RotaryCamera();
{
  m_driver=new Servo;
  defAngle=90; 
}
RotaryCamera::RotaryCamera(uint8_t pin);
{
 m_pin=pin;  
 m_driver=new Servo;
 defAngle=90; 
}
void RotaryCamera:: init();
{
  m_driver->attach(m_pin);
  m_driver->write(defAngle);
  timer.start();
}
void RotaryCamera::write(int8_t angle);
{
  if (timer.start>m_rotation_time)
  {
    m_angle+=m_angle; 
    m_angle=constrain(m_angle,1,179); 
    timer.start(); 
    m_driver->write(m_angle);
  }
}
void RotaryCamera::setRotationTime(uint8_t time);
{
  m_rotation_time=time; 
}
