#include <iostream>
using
  std::cout;
using
  std::cin;
using
  std::endl;
using
  std::string;
#include <vector>
using
  std::vector;

#include "Vehicle.h"
#include "Car.h"
#include "Hybrid.h"
#include "Motor.h"
#include "Bus.h"
#include "MLH.h"

int main ()
{
  MLH < Vehicle > *center = new MLH < Vehicle > ();
  center->MLH_set_print (1);
  int
    choice;
  int
    task;
  int 
    input = 0;
  int
    id;
  int
    typeOfCar;
  int
    year;
  string
    color;
  int
    mileage;
  int
    engineSize;
  string
    gasType;
  int
    polLevel;
  string
    service;
  double
    motorPower;
  double
    motorUsage;
  double
    batteryCap;

  double
    frontSize;
  double
    backSize;

  int
    passengerCap;

  int
    partC,
    laborC;
  int
    init = 0;
   Vehicle *v;

  while (init != 4)
    {
      cout << "Welcome to the Service Center!" << endl;
      cout <<
	"Do you want to: 1.add a vehicle  2.add tasks  3.checkout/print/other  4.Exit"
	<< endl;
      cin >> init;
      //switches choice.
      switch (init)
	case 1:
	while (choice != 5)
	  {
	    cout << "Please enter id (1 - 100000): " << endl;
	    cin >> id;
	    cout << "Please enter car year: " << endl;
	    cin >> year;
	    cout << "Please enter milage: " << endl;
	    cin >> mileage;
	    cout << "Enter car color: " << endl;
	    cin >> color;
	    cout << "Choose a vehicle type: " << endl;
	    cout << "1.car 2.hybrid 3.motor 4.bus 5.stop " << endl;
	    cin >> choice;
	    //swiches vehicle selection.
	    switch (choice)
	      {
	      case 1:
		{
		  cout << "Please enter engine size: " << endl;
		  cin >> engineSize;
		  cout << "Enter Gas type (premium/plus/regular): " << endl;
		  cin >> gasType;
		  cout << "Enter pollution level(int 1-5): " << endl;
		  cin >> polLevel;
		  //allocates space for a new car.
		  v =
		    new Car (id, year, color, mileage, engineSize, gasType,
			     polLevel);
		  center->MLH_insert (id, v);
		  cout << "The car is added! \n";
		  break;
		}
	      case 2:
		{
		  //Creating hybrid.
		  cout << "Please enter engine size: " << endl;
		  cin >> engineSize;
		  cout << "Enter Gas type (premium/plus/regular): " << endl;
		  cin >> gasType;
		  cout << "Enter pollution level(int 1-5): " << endl;
		  cin >> polLevel;
		  cout << "Enter motor usage: " << endl;
		  cin >> motorUsage;
		  cout << "Enter motor power: " << endl;
		  cin >> motorPower;
		  cout << "Enter Battery capacity: " << endl;
		  cin >> batteryCap;
		  v =
		    new Hybrid (id, year, color, mileage, engineSize, gasType,
				polLevel, motorPower, motorUsage, batteryCap);
		  center->MLH_insert (id, v);
		  cout << "Hybrid car is added! \n";
		  break;
		}
	      case 3:
		{
		  //Creating motorcycle.
		  cout << "Enter engine size: " << endl;
		  cin >> engineSize;
		  cout << "Enter int front wheel size: " << endl;
		  cin >> frontSize;
		  cout << "Enter int back wheel size: " << endl;
		  cin >> backSize;
		  v =
		    new Motor (id, year, color, mileage, engineSize,
			       frontSize, backSize);
		  center->MLH_insert (id, v);
		  cout << "The motorcycle is added! \n";
		  break;
		}
	      case 4:
		{
		  //Creating bus.
		  cout << "Please enter bus passenger capacity: " << endl;
		  cin >> passengerCap;
		  v = new Bus (id, year, color, mileage, passengerCap);
		  center->MLH_insert (id, v);
		  cout << "The bus is added! \n";
		  break;
		}
	      default:
		{
		  cout << "Stop adding/ Invalid selection! " << endl;
		  break;
		}
	      }
	    /* Setting choice to previous value. */
	    choice = 0;
	    break;

	case 2:
	    /* This method allows car, bus, hybrid, and motor methods to reduce redundant code */
	    while (task != 6)
	      {
		cout <<
		  "Choose a task: 1.maintanance 2.brake change 3.tune_up 4.wash 5.decoration 6.stop adding task"
		  << endl;
		cin >> task;
		// Switches task among 5 options.
		switch (task)
		  {
		  case 1:
		    {
		      cout << "Cost of parts: " << endl;
		      cin >> partC;
		      cout << "Cost of labor" << endl;
		      cin >> laborC;
		      cout << "Please select which vehicle via id:\n";
		      cin >> id;
		      Vehicle *
			g = center->MLH_get (id);
		      if (g == NULL)
			{
			  cout << "the vehicle doesn not exist! \n";
			  break;
			}
		      service = "maintanance";
		      // Creates a task and insert wrapped as node
		      g->add (service, partC, laborC);
		      cout << "Task added!\n";
		      g = NULL;	//resets
		      break;
		    }
		  case 2:
		    {
		      cout << "Cost of parts: " << endl;
		      cin >> partC;
		      cout << "Cost of labor" << endl;
		      cin >> laborC;
		      cout << "Please select which vehicle via id:\n";
		      cin >> id;
		      Vehicle *
			g = center->MLH_get (id);
		      if (g == NULL)
			{
			  cout << "the vehicle doesn not exist! \n";
			  break;
			}

		      service = "brake change";
		      center->MLH_get (id)->add (service, partC, laborC);
		      cout << "Task added!\n";
		      g = NULL;
		      break;
		    }
		  case 3:
		    {
		      cout << "Cost of parts: " << endl;
		      cin >> partC;
		      cout << "Cost of labor" << endl;
		      cin >> laborC;
		      cout << "Please select which vehicle via id:\n";
		      cin >> id;
		      Vehicle *
			g = center->MLH_get (id);
		      if (g == NULL)
			{
			  cout << "the vehicle doesn not exist! \n";
			  break;
			}
		      service = "tune_up";
		      center->MLH_get (id)->add (service, partC, laborC);
		      cout << "Task added!\n";
		      g = NULL;
		      break;
		    }
		  case 4:
		    {
		      cout << "Cost of parts: " << endl;
		      cin >> partC;
		      cout << "Cost of labor" << endl;
		      cin >> laborC;
		      cout << "Please select which vehicle via id:\n";
		      cin >> id;
		      Vehicle *
			g = center->MLH_get (id);
		      if (g == NULL)
			{
			  cout << "the vehicle doesn not exist! \n";
			  break;
			}

		      service = "wash";
		      center->MLH_get (id)->add (service, partC, laborC);
		      cout << "Task added!\n";
		      g = NULL;
		      break;
		    }
		  case 5:
		    {
		      cout << "Cost of parts: " << endl;
		      cin >> partC;
		      cout << "Cost of labor" << endl;
		      cin >> laborC;
		      cout << "Please select which vehicle via id:\n";
		      cin >> id;
		      Vehicle *
			g = center->MLH_get (id);
		      if (g == NULL)
			{
			  cout << "the vehicle doesn not exist! \n";
			  break;
			}
		      service = "decoration";
		      center->MLH_get (id)->add (service, partC, laborC);
		      cout << "Task added!\n";
		      g = NULL;
		      break;
		    }
		  default:
		    {
		      cout << "Stop adding/ Invalid task selection! \n";
		      break;
		    }
		  }
	      }
	    task = 0;
	    break;

	case 3:

	    while (input != 6)

	      {
		cout << "1.Checkout a vehicle" << endl;
		cout << "2.View all vehicles" << endl;
		cout << "3.View single vehicle" << endl;
		cout << "4.Check the current bill of the car" << endl;
		cout << "5.Paint a car (change car color)" << endl;
		cout << "6.Exit check/view" << endl;
		cin >> input;
		switch (input)
		  {
		    //switches selection.     
		  case 1:
		    {
		      cout << "Please select the vehicle id to checkout" <<
			endl;
		      //gets a vehicle
		      cin >> id;
		      //vehicle pointer created
		      Vehicle *
			m = center->MLH_get (id);
		      if (m == NULL)
			{	//vehicle not found.
			  cout << "the vehicle doesn not exist! \n";
			  break;
			}
		      m->printbill ();	//call print method in vehicle
		      m = center->MLH_delete (id);
		      cout << "Vehicle deletion complete!\n";
		      m = NULL;
		      break;
		    }
		  case 2:
		    {
		      cout << "Viewing all the vehicles>>>" << endl;
		      //prints all.
		      cout << *center;
		      break;
		    }
		  case 3:
		    {
		      cout << "Which vehicle to view?" << endl;
		      cin >> id;
		      Vehicle *
			n = center->MLH_get (id);
		      if (n == NULL)
			{
			  cout << "the vehicle does not exist! \n";
			  break;
			}
		      //prints vehicle infomation  
		      cout << *n;
		      n = NULL;
		      break;
		    }
		  case 4:
		    {
		      cout << "Select which bill to view via id: " << endl;
		      cin >> id;
		      Vehicle *
			n = center->MLH_get (id);
		      if (n == NULL)
			{
			  cout << "the vehicle doesn not exist! \n";
			  break;
			}
		      //get sum of costs in the tasklist.
		      cout << "Total cost so far is: $" << n->
			getcost () << endl;
		      n = NULL;
		      break;
		    }
		  case 5:
		    {
		      cout << "Which paint color? Please select id: " << endl;
		      cin >> id;
		      Vehicle *
			n = center->MLH_get (id);
		      if (n == NULL)
			{
			  cout << "the vehicle doesn not exist! \n";
			  break;
			}
		      cout << "Change to which color? " << endl;
		      cin >> color;
		      //changes vehicle color string representation.
		      n->setcolor (color);
		      cout << "Vehicle No. " << id << "Is changed to " <<
			color << "!" << endl;
		      n = NULL;
		      break;
		    }
		  default:
		    {
		      cout <<
			"Exiting this level of menu for invalid selection/ Quitting"
			<< endl;
		      break;
		    }
		  }
	      }
	    //restores input, in case of infinite loop.
	    input = 0;
	    break;
	  }
    }
  cout << "Exiting service center. Thank you for visiting!" << endl;
  //deletes center
  delete
    center;
  center = NULL;			//memory management.
  return 0;
}
