#include <string>
#include <iostream>
#include "Task.h"
using namespace std;

Task::Task (const string & name, int parts, int labor)
{
  taskname = name;
  partCost = parts;
  laborCost = labor;
}

//returns string
string
Task::getname () const 
{
  return taskname;
}

//returns part cost
int
Task::getparts () const 
{
  return partCost;
}

//returns labor cost
int
Task::getlabor () const 
{
  return laborCost;
}

void
Task::print () const 
{
  cout << "Taskname: " << getname () << endl;
  cout << "$Cost of parts: " << getparts () << endl;
  cout << "$Cost of labor: " << getlabor () << endl;
}
