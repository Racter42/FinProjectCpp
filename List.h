#ifndef LIST_H
#define LIST_H
using
  std::cout;
using
  std::endl;
#include <string>
#include "Task.h"

//Inner type listnode class
class
  ListNode
{
  public:
    //constructor
  ListNode (const Task & ta);
  //returns task
  Task
  getTask () const;

private:
  Task
    content;
  //next pointer
  ListNode *
    next;

  friend class
    List;
};

//list of tasks
class
  List
{
public:
  //constructor
  List ();
  //destructor
  ~
  List ();
  //returns total cost
  int
  getbill ();
  //add new task 
  void
  insert (const string & fa, const int, const int);
  //print method
  void
  print () const;
  //only prints first task
  void
  printfirst () const;

/* private methods */
private:
  //first node in task
  ListNode *
    head;
  //total cost
  int
    bill;
};
#endif
