#ifndef HYBRID_H
#define HYBRID_H

#include <string>
using
  std::string;
#include "Vehicle.h"

//hybrid is a type of car
#include "Car.h"
#include <iostream>
using
  std::ostream;

//Hybrid inherits car
class
  Hybrid:
  public
  Car
{
public:
  //constructor
  Hybrid (const int, const int, const string &, const int, const int,
	  const string &, const int, const int, const int, const int);
  //destructor 
   ~
  Hybrid ();
  //get methods
  int
  getpower () const;

  int
  getusage () const;

  int
  getcapacity () const;

  //virtual print
  virtual void
  print () const;

private:
  //motor power
  int
    power;
  //motor usage
  int
    usage;
  //battery capacity of hybrid
  int
    capacity;
};
#endif
