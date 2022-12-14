#include <iostream>
using
  std::cout;
using
  std::endl;
#include <string>
using
  std::string;
#include "Car.h"
#include "Hybrid.h"
//Hybrid has all car's functions and can use Car constructor
Hybrid::Hybrid (const int idCar, const int caryear, const string & colors,
		const int miles, const int engSize, const string & gasType,
		const int pol, const int pow, const int use, const int cap):
Car (idCar, caryear, colors, miles, engSize, gasType, pol)
{
  //sets new values
  power = pow;
  usage = use;
  capacity = cap;
}

// returns motor power
int
Hybrid::getpower () const 
{
  return power;
}

// returns motor usage
int
Hybrid::getusage () const 
{
  return usage;
}

// returns battery capacity
int
Hybrid::getcapacity () const 
{
  return capacity;
}

// printing method using car's print
void
Hybrid::print () const 
{
  cout << "Power: " << getpower () << endl;
  cout << "Usage: " << getusage () << endl;
  cout << "Capacity: " << getcapacity () << endl;
  Car::print ();
}
