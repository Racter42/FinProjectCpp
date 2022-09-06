#include <iostream>
using
  std::cout;
using
  std::endl;
#include "List.h"
#include "Task.h"

/*constructor*/
ListNode::ListNode (const Task & task):
content (task),
next (0)
{
  //empty
}

//gets task and returns
Task
ListNode::getTask () const 
{
  return content;
}

/* constructor for List*/
List::List ()
{
  head = NULL;
  bill = 0;
};


//deconstructor
List::~List ()
{
  ListNode *tempNode;

  while (head != NULL)
    {
      tempNode = head;
      head = tempNode->next;
      delete tempNode;
    }
}

//return total cost
int
List::getbill ()
{
  return bill;
}

void
List::insert (const string & ta, const int i, const int j)
{
  ListNode *tempNode;
  Task *task;
  task = new Task (ta, i, j);
  //creates task node
  tempNode = new ListNode (*task);
  tempNode->next = head;
  head = tempNode;
  //update bill
  bill += i;
  bill += j;
}

void
List::printfirst () const 
{
  if (head != NULL)
    {
      //prints first task
      head->getTask ().print ();
    }
  else
    {
      cout << "no current task" << endl;
    }
}

//print method
void
List::print () const 
{

  ListNode *pnode;		//nodes to print
  pnode = head;
  if (head == NULL)
    {
      cout << "No tasks exist." << endl;
    }
  //traverse and print all tasks
  while (pnode != NULL)
    {
      pnode->getTask ().print ();
      cout << "     |" << endl;
      cout << "     |" << endl;
      pnode = pnode->next;
    }
  //total charge
  cout << "$Current total bill: " << bill << endl;
  cout << "{{{Bill complete}}}" << endl;
}
