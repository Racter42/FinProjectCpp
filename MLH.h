#ifndef MLH_H
#define MLH_H

#include <iostream>
using namespace std;
#include "Node.h"
#include "ML_hash.h"
#include <stdlib.h>
#include "random_op.h"
template < typename NODETYPE >
  ostream & operator<< (ostream & o, const MLH < NODETYPE > &v);

template < typename NODETYPE > class MLH
{
public:
  MLH ();			//constructor
  ~MLH ();			// deconstructor 
  void deleteNode (Node < NODETYPE > *); //helper method for deconstructor as delete calls deconstructor
  bool MLH_insert (int key, NODETYPE * data);
  void print (Node < NODETYPE > *) const;	//helper method for printing
  void print () const;
  NODETYPE *MLH_get (int);	// gets index of selected key
  NODETYPE *MLH_get (int, Node < NODETYPE > *);
  NODETYPE *MLH_delete (int key);
  int findMaxLevel () const;	//looks for lowest level 
  void MLH_set_print (int num);	// prints the elements on lvl
  int set_print;
  friend ostream & operator <<<> (ostream &, const MLH < NODETYPE > &);

private:
  Node < NODETYPE > *root;
  int numHashNode;
  int printOp;
  int numOfKV;			//key values
  unsigned long int stepCounter;
  int level[9];
};

//constructor
template < typename NODETYPE > MLH < NODETYPE >::MLH ()
{
  root = new Node < NODETYPE > ();
  numHashNode = 1;
  printOp = 1;
  stepCounter = 0;
  numOfKV = 0;
}

//deconstructor
template < typename NODETYPE > MLH < NODETYPE >::~MLH ()
{
  deleteNode (root);
}

/*helper method for destructor to do recursion
 */
template < typename NODETYPE >
  void MLH < NODETYPE >::deleteNode (Node < NODETYPE > *ptr)
{
  Node < NODETYPE > *currentNode = ptr;

  for (int i = 0; i < MAX_SIZE; i++)
    {
      if (currentNode->child[i] != NULL)
	{
	  deleteNode (currentNode->child[i]);
	}
    }

  Node < NODETYPE > *parentNode = currentNode->parent;
  if (parentNode != NULL)
    {
      int index = currentNode->index;
      parentNode->child[index] = NULL;
    }
}


template < typename NODETYPE >
  bool MLH < NODETYPE >::MLH_insert (int key, NODETYPE * data)
{
  Node < NODETYPE > *currentNode = root;

  while (currentNode->size > MAX_SIZE)
    {
      int hashNew = ML_hash (currentNode->level + 1, key) - 1;	//uses method from ML_hash to insert into sublevel
      if (currentNode->child[hashNew] == NULL)
	{
	  //create a new node and make space
	  currentNode->child[hashNew] = new Node < NODETYPE > ();
	  currentNode->child[hashNew]->parent = currentNode;
	  currentNode->child[hashNew]->level = currentNode->level + 1;
	  numHashNode++;
	  currentNode->child[hashNew]->index = hashNew;
	  level[currentNode->level + 1]++;
	}
      currentNode = currentNode->child[hashNew];
      stepCounter++;
    }

  while (currentNode->size == MAX_SIZE)
    {
      for (int i = 0; i < MAX_SIZE; i++)
	{

	  if (currentNode->key[i] == key)
	    {
	      return false;
	    }
	}

      //explode
      for (int i = 0; i < MAX_SIZE; i++)
	{
	  int hash =
	    ML_hash (currentNode->level + 1, currentNode->key[i]) - 1;
	  if (currentNode->child[hash] == NULL)
	    {
	      //create a new node
	      currentNode->child[hash] = new Node < NODETYPE > ();
	      currentNode->child[hash]->level = currentNode->level + 1;
	      currentNode->child[hash]->parent = currentNode;
	      currentNode->child[hash]->index = hash;
	      numHashNode++;
	      level[currentNode->level + 1]++;
	    }

	  for (int j = 0; j < MAX_SIZE; j++)
	    {
	      //looks for empty space in leaf
	      if (currentNode->child[hash]->key[j] == 0)
		{
		  currentNode->child[hash]->key[j] = currentNode->key[i];
		  currentNode->child[hash]->data[j] = currentNode->data[i];
		  currentNode->child[hash]->size++;
		  break;
		}
	    }

	}

      int hashNew = ML_hash (currentNode->level + 1, key) - 1;
      if (currentNode->child[hashNew] == NULL)
	{			//allocate space for new node
	  currentNode->child[hashNew] = new Node < NODETYPE > ();
	  currentNode->child[hashNew]->level = currentNode->level + 1;
	  currentNode->child[hashNew]->parent = currentNode;
	  currentNode->child[hashNew]->index = hashNew;
	  currentNode = currentNode->child[hashNew];
	  stepCounter++;
	  numHashNode++;
	  level[currentNode->level]++;
	}
      else
	{
	  currentNode = currentNode->child[hashNew];
	  stepCounter++;
	}
    }

  // insert key and data in empty space
  if (currentNode->size < MAX_SIZE)
    {
      int emptyIndex;
      for (int i = 0; i < MAX_SIZE; i++)
	{
	  if (currentNode->key[i] == key)
	    return false;
	}

      for (int i = 0; i < MAX_SIZE; i++)
	{
	  if (currentNode->key[i] == 0)
	    {
	      emptyIndex = i;
	      break;
	    }
	}

      currentNode->key[emptyIndex] = key;
      currentNode->data[emptyIndex] = data;
      currentNode->size++;
      numOfKV++;

      //update parents
      Node < NODETYPE > *parentNode = currentNode->parent;
      stepCounter++;
      while (parentNode != NULL)
	{
	  parentNode->size++;
	  parentNode = parentNode->parent;
	  stepCounter++;
	}
      return true;
    }
  return false;
}


template < typename NODETYPE > NODETYPE * MLH < NODETYPE >::MLH_get (int key)
{
  Node < NODETYPE > *currentNode = root;

//if max capacity reached, check lower levels
  while (currentNode->size > MAX_SIZE)
    {
      int newHash = ML_hash (currentNode->level + 1, key) - 1;
      if (currentNode->child[newHash] == NULL)
	{
	  return NULL;
	}

      currentNode = currentNode->child[newHash];
      stepCounter++;
    }


  //Look for key once size is less than max capacity
  for (int i = 0; i < MAX_SIZE; i++)
    {
      if (currentNode->key[i] == key)
	{
	  return currentNode->data[i];
	}
    }
  return NULL;
}


/**
* Deletes object if key exists in MLH, otherwise null. 
*/
template < typename NODETYPE >
  NODETYPE * MLH < NODETYPE >::MLH_delete (int key)
{
  Node < NODETYPE > *currptr = root;

  while (currptr->size > MAX_SIZE)
    {
      int hashNew = ML_hash (currptr->level + 1, key) - 1;
      if (currptr->child[hashNew] == NULL)
	{
	  return NULL;
	}

      //go to next level
      currptr = currptr->child[hashNew];
      stepCounter++;
    }
  //now this means currpptr size is <= 5
  //and now see if the key is one of them
  for (int i = 0; i < MAX_SIZE; i++)
    {
      if (currptr->key[i] == key)
	{
	  NODETYPE *dataptr = currptr->data[i];	//so that I can return it
	  currptr->data[i] = NULL;
	  currptr->key[i] = 0;
	  currptr->size--;
	  numOfKV--;

	  Node < NODETYPE > *parentN = currptr->parent;
	  stepCounter++;
	  if (currptr->size == 0 && currptr != root)
	    {
	      level[currptr->level]--;
	      Node < NODETYPE > *parentNN = currptr->parent;
	      //need parentNN since if currptr is already deleted,
	      //then cannot access to currptr anymore
	      stepCounter++;
	      int index = currptr->index;
	      parentNN->child[index] = NULL;

	      numHashNode--;
	    }

	  //update size of parents.
	  while (parentN != NULL)
	    {
	      parentN->size--;

	      //see if need to collapse if size is 5  
	      if (parentN->size == MAX_SIZE)
		{
		  int num = 0;	//num is the next empty slot
		  for (int j = 0; j < MAX_SIZE; j++)
		    {
		      if (parentN->child[j] != NULL)
			{
			  for (int k = 0; k < MAX_SIZE; k++)
			    {
			      if (parentN->child[j]->key[k] != 0)
				{
				  parentN->key[num] =
				    parentN->child[j]->key[k];
				  parentN->data[num++] =
				    parentN->child[j]->data[k];
				  parentN->child[j]->key[k] = 0;
				  //parentN->pointers[j]->data[k] = NULL;
				}
			    }	//ends for
			  level[parentN->child[j]->level]--;
			  parentN->child[j] = NULL;
			  numHashNode--;
			}	//ends if
		    }		//ends for loop
		}		//ends if
	      parentN = parentN->parent;
	      stepCounter++;
	    }			//ends while
	  return dataptr;
	}
    }				//ends for
  return NULL;			//cannot find the key
}

/*Return the current max level*/
template < typename NODETYPE > int MLH < NODETYPE >::findMaxLevel () const 
{
  for (int i = 0; i < 9; i++)
    {
      if (level[i] == 0)
	{
	  return i;
	  //level starts from zero
	}
    }
  //otherwise all full
  return 9;
}

/* To determine if data needs to be printed. 1 to print , 2 to ignore*/
template < typename NODETYPE > void MLH < NODETYPE >::MLH_set_print (int num)
{
  printOp = num;
}

/*Helper method that prints key and data in the repository*/
template < typename NODETYPE >
  void MLH < NODETYPE >::print (Node < NODETYPE > *ptr) const 
{

  Node < NODETYPE > *currentNode;
  currentNode = ptr;
  if (currentNode->size <= MAX_SIZE)
    {
      for (int i = 0; i < MAX_SIZE; i++)
	{
	  if (currentNode->key[i] != 0)
	    {
	      cout << "Key: " << currentNode->key[i] << "   objetct: "
		<< *currentNode->data[i] << "\n";
	    }
	}

    }
  else
    {
      for (int i = 0; i < MAX_SIZE; i++)
	{
	  if (currentNode->child[i] != NULL)
	    {
	      print (currentNode->child[i]);
	    }
	}


    }
}

/*print that calls the helper print function (recursive)*/
template < typename NODETYPE > void MLH < NODETYPE >::print () const 
{
  print (root);

}

/*overload the << operator*/
template < typename NODETYPE >
  ostream & operator<< (ostream & output, const MLH < NODETYPE > &list)
{
  cout << "Number of objects: " << list.numOfKV << endl;
  cout << "Number of hash nodes: " << list.numHashNode << endl;
  cout << "The maximum level so far: " << list.findMaxLevel () << endl;
  cout << "The steps performed so far: " << list.stepCounter << endl;
  if (list.printOp == 1)
    {
      list.print (list.root);	//print out the key and respective data
    }
}

#endif
