#include "Timer.h"
Timer::Timer()
{
}
void Timer::start();
{ 
  m_time_start=millis();
  is_started=true;
}
bool Timer::is_started();
{
return is_started; 
}
void Timer::stop();
{
  is_started=false; 
}
long int Timer::elapsed();
{
  if (is_started==false)
 {  
  return 0; 
 }
 else 
 {
  long int x=millis-m_time_start; 
  return x; 
 }
}
