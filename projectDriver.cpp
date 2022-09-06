#include "MLH.h"
#include "random_op.h"
#include <iostream>

using namespace std;

int main (void)
{
  MLH < int >*intptr;
  unsigned int seed;		//seed 
  int num_op, range;
  int *data;
  int key;
  int num_get, num_del, num_update;
  int t;
  intptr = new MLH < int >();
  data = new int;
  cout << "Please indicate a range: " << endl;
  cin >> range;
  cout << "Please indicate number of operations: " << endl;
  cin >> num_op;
  cout << "Please indicate seed: " << endl;
  cin >> seed;
  cout << "------------------------------" << endl;
  //initialize 
  num_get = 0;
  num_del = 0;
  num_update = 0;
  Random_operation Rand_op (seed, range);

  for (t = 1; t <= num_op; t++)
    {
      Rand_op.Randomize_next_op ();
      key = Rand_op.Get_key();
      switch (Rand_op.Get_op ())
	{
	case 'G':
	  num_get++;
	  data = intptr->MLH_get (key);
	  break;
	case 'I':
	  data = new int;
	  *data = t;
	  num_update++;
	  intptr->MLH_insert (key, data);
	  break;
	case 'D':
	  num_del++;
	  data = intptr->MLH_delete (key);
	  data = NULL;//prevent memory leak
	  break;
	}

      if ((t % (num_op / 10)) == 0)
	{
	  if (range > 100)
	    {
	      intptr->MLH_set_print (2);
	    }
	  else
	    {
	      intptr->MLH_set_print (1);
	    }
	  cout << *intptr;

	}
    }

  cout << "Update: " << num_update << " times" << endl;
  cout << "Delete: " << num_del << " times" << endl;
  cout << "Get " << num_get << " times" << endl;

  //frees memory and prevent memory leak
  intptr = NULL;
}
