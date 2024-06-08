#include <Kainoi - Multi I.h>

void setup()
{

}

void loop()
{
  //motor(leftspeed,rightspeed);
  motor(100,100); //forward
  delay(1000);
  motor(-100,-100); //backward
  delay(1000);
}
