#include <iostream>
using namespace std;
#include "Vehicle.h"
#include <string>

#include "List.h"

//constructor
Vehicle::Vehicle (const int idCar, const int caryear, const string & colors,
		  const int miles):
id (idCar),
year (caryear),
mileage (miles)
{
  setcolor (colors);
  //mallocs tasklist
  tasklist = new List ();
}

//destructor
Vehicle::~Vehicle ()
{
  delete tasklist;
  tasklist = NULL;
}

//sets unique id (defined by user)
void
Vehicle::setid (const int identity)
{
  id = identity;
}

//returns id
int
Vehicle::getid () const 
{
  return id;
}

//sets model year
void
Vehicle::setyear (const int caryear)
{
  year = caryear;
}

//returns model year
int
Vehicle::getyear () const 
{
  return year;
}

//sets color
void
Vehicle::setcolor (const string & colors)
{
  color = colors;
}

//returns color 
string
Vehicle::getcolor () const 
{
  return color;
}

//sets mileage of car
void
Vehicle::setmileage (const int miles)
{
  mileage = miles;
}

//returns mileage
int
Vehicle::getmileage () const 
{
  return mileage;
}

//prints id, year, color mileage and current first task
void
Vehicle::print () const 
{
  cout << "ID: " << getid () << endl;
  cout << "Year: " << getyear () << endl;
  cout << "Color: " << getcolor () << endl;
  cout << "Mileage " << getmileage () << endl;
  cout << "Current task: " << endl;
  tasklist->printfirst ();
}

//add task via list method
void
Vehicle::add (std::string & tname, const int i, const int j)
{
  tasklist->insert (tname, i, j);
}

//operator overloading
ostream & operator<< (ostream & output, const Vehicle & v)
{
  v.print ();
}

//gets total bill
int
Vehicle::getcost () const 
{
  return tasklist->getbill ();
}

//prints charge
void
Vehicle::printbill () const 
{
  tasklist->print ();
}
