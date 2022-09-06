#ifndef TASK_H
#define TASK_H

#include <string>
using
  std::string;
class
  Task
{
public:
  Task (const string &, int, int);	//constructor
  string
  getname () const;
/*Method to get part and labor cost respectively */
  int
  getparts () const;
  int
  getlabor () const;
  void
  print () const;

private:
  //private variables
  string
    taskname;
  int
    partCost;
  int
    laborCost;
};
#endif
