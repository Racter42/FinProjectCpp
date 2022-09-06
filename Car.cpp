#include <iostream>
using
  std::cout;
using
  std::endl;

#include "Car.h"
//constructor using vehicle constructor (Car.h includes Vehicle.h)
Car::Car (const int idCar, const int caryear, const string & colors,
	  const int miles, const int eng, const string & gasType,
	  const int pol):
Vehicle (idCar, caryear, colors, miles)
{
  //sets new things according to parameter
  engine = eng;
  gas = gasType;
  poll = pol;			//pollution
}

//get methods
int
Car::getengine () const 
{
  return engine;
}

string
Car::getgas () const 
{
  return gas;
}

int
Car::getpoll () const 
{
  return poll;
}

//print method overloading
void
Car::print () const 
{
  cout << "Engine: " << getengine () << endl;
  cout << "Gas: " << getgas () << endl;
  cout << "Pollution: " << getpoll () << endl;
  //calls vehicle's print
  Vehicle::print ();

}

//operator overloading
ostream & operator<< (ostream & output, const Car & c)
{
  c.print ();
}
