#ifndef linkedqueue_H
#define linkedqueue_H

#include "abstractqueue.h"

template <typename T>
class LQNode {
public:
	T m_data;
	string m_name;
	T m_total;
	LQNode<T>* m_next;

	// Default constructor of the LQNode class.
	// set next ptr to NULL
	LQNode() : m_next(NULL) {}

	// parameterized constructor of the LQNode class.
	// data are next ptr are set to the parameters
	LQNode(const T& x, LQNode<T>* p) : m_data(x), m_next(p) {}
};

template <typename T>
class LinkedQueue : public AbstractQueue<T> {
public:
	LQNode<T>* m_back;
	int m_size;

	// default constructor for the LQ class
	// set size to zero and ptr to NULL
	LinkedQueue();

	// PURPOSE: Checks if a queue is empty
	// RETURNS: 'true' if the queue is empty
	//   'false' otherwise
	virtual bool isEmpty() const;

	// PURPOSE: looks at the front of the queue
	// RETURNS: a reference to the element currently in front of the queue
	// EXCEPTION: if the queue is empty, THROW a 'Oops' object with an error
	//   message!!!
	virtual const T& front() const throw(Oops);

	// PURPOSE: looks at the name at the front of the queue
	// RETURNS: the name of the node at the front of the queue
	const string& frontName() const;

	// PURPOSE: looks at the total at the front of the queue
	// RETURNS: the number of total eaten at the front of the queue
	const T& frontTotal() const;

	// PURPOSE: looks at the back of the queue
	// RETURNS: a reference to the element currently in the back of the queue
	// EXCEPTION: if the queue is empty, THROW a 'Oops' object with an error
	//   message!!!
	virtual const T& back() const throw(Oops);

	// PURPOSE: enqueue an element into the queue
	// PARAMETERS: x is the item to add to the queue
	// POSTCONDITIONS: x is now the element at the end of the queue,
	virtual void enqueue(const T& x);

	// PURPOSE: assign a name to the node at the back of the queue
	// PARAMETERS: y is the name added to the node at the back of the queue
	// POSTCONDITIONS: y is the name of the element at the end of the queue
	void assignName(const string& y);

	// PURPOSE: update the total variable
	// PARAMETERS: z is added to the total variable of the node at the back of the queue
	// POSTCONDITIONS: the total variable of the node at the back of the queue updated.
	void updateTotals(const T& z, const T& w);

	// PURPOSE: dequeues an elemet from the queue
	// POSTCONDITIONS: the element formerly at the front of the queue has
	//     been removed.
	// NOTE: Dequeueing an empty queue results in an empty queue.
	virtual void dequeue();

	// PURPOSE: clears the queue
	// POSTCONDITIONS: the queue is now empty
	virtual void clear();

	// PURPOSE: delete all elements of the class (automatically called)
	// POSTCONDITIONS: all nodes are deleted and values are set to NULL
	~LinkedQueue();
};

#endif