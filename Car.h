#ifndef CAR_H
#define CAR_H

#include <string>
using
  std::string;
using
  std::ostream;
#include "Vehicle.h"

class
  Car:
  public
  Vehicle
{
public:
  Car (const int, const int, const string &, const int, const int,
       const string &, const int);
   ~
  Car ();
  //gets engine cc
  int
  getengine () const;
  //gets gas type
  string
  getgas () const;
  //gets pollution level
  int
  getpoll () const;
  //virtual print function
  virtual void
  print () const;
  //operator overloading
  friend
    ostream &
  operator<< (ostream & output, const Car &);

private:
  //engine size
  int
    engine;
  //gas type(premium regular or plus)
  string
    gas;
  //pollution level
  int
    poll;
};
#endif
