#ifndef NODE_H
#define NODE_H

template < typename NODETYPE > class MLH;

template < typename NODETYPE >

#define MAX_SIZE 5

  class Node
{
  friend class MLH < NODETYPE >;
  
public:
  Node ();
  ~Node ();
private:
  int size;
  int level;
  int index;
  int key[MAX_SIZE];
  Node < NODETYPE > *child[MAX_SIZE];
  NODETYPE *data[MAX_SIZE];	// array to store value 
  Node < NODETYPE > *parent;	//points to parent node
};

template < typename NODETYPE > Node < NODETYPE >::Node ()
{
  for (int i; i < MAX_SIZE; i++)
    {
      child[i] = NULL;
      key[i] = 0;
      data[i] = NULL;
    }
  parent = NULL;
  size = 0;
  index = 0;
  level = 0;
}

//deconstructor 
template < typename NODETYPE > Node < NODETYPE >::~Node ()
{
  for (int i = 0; i < MAX_SIZE; i++)
    {
      if (data[i] != NULL)
	{
	  data[i] = NULL;
	}
      if (child[i] != NULL)
	{
	  delete child[i];
	  child[i] = NULL;
	}
    }
}

#endif
