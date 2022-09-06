#include <iostream>
using
  std::cout;
using
  std::endl;

#include "Motor.h"
#include "Vehicle.h"
//constructor
Motor::Motor (const int idCar, const int caryear, const string & colors,
	      const int miles, const int engSize, const int frontSize,
	      const int backSize):
Vehicle (idCar, caryear, colors, miles)
{
  //setting new things only for motor
  engine = engSize;
  front = frontSize;
  back = backSize;
}

// returns engine size
int
Motor::getengine () const 
{
  return engine;
}

// returns front wheel size
int
Motor::getfront () const 
{
  return front;
}

// returns back wheel size
int
Motor::getback () const 
{
  return back;
}

// virtual print
void
Motor::print () const 
{
  cout << "Engine: " << getengine () << endl;
  cout << "Front: " << getfront () << endl;
  cout << "Back: " << getback () << endl;
  Vehicle::print ();
}

//operator overloading
ostream & operator<< (ostream & output, const Motor & c)
{
  c.print ();
}
