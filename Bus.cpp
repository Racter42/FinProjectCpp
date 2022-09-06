#include <iostream>
using
  std::cout;
using
  std::endl;

#include "Bus.h"

//constructor
Bus::Bus (const int idCar, const int caryear, const string & colors,
	  const int miles, const int pasNum):
Vehicle (idCar, caryear, colors, miles)	//(similar to super method in Java)
{
  //sets passenger capacity
  passenger = pasNum;
}

// returns capacity
int
Bus::getpassenger () const 
{
  return passenger;
}

// print overloading
void
Bus::print () const 
{
  cout << "Passenger capacity: " << getpassenger () << endl;
  Vehicle::print ();
}

//operator overloading
ostream & operator<< (ostream & output, const Bus & c)
{
  c.print ();
}
