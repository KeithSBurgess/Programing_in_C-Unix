//
// queue.c: Linked list implementation of queue abstract data type
// Dependancies: queue.h
// Compilation: gcc -c queue.c;  ar -rc libqueue.a queue.o
// 
// Implementation of a queue using a linked list as the underlying
// data structure. Enqueue and dequeue require pointers to the head and tail
// pointers. These pointers must be initialized to NULL before first use of
// queue operations. This implementation provides enqueue(), dequeue(), 
// isempty(), and also an output() function to display the data from all nodes.


#include <stdio.h>
#include <stdlib.h>		// for malloc() 
#include "queue.h"		// definitions of "queue" and "node" data types


// FUNCTION: isempty()
// return 1 if queue is empty, 0 if is not empty
int isempty(node *head)
{
	if (head == NULL)
		return 1;
	else 
		return 0;
}


// FUNCTION: enqueue()
// insert a single item onto the queue
// enqueues to tail of list
void enqueue(node **headptr, node **tailptr, int item)
{
	node *newnode = NULL;		// node to hold new item to list

	// allocate new node
	newnode = malloc(sizeof(node));
	if (newnode == NULL)
		fprintf(stderr, "No memory is available.\n");
	else
	{
		// set data value of new node to value in item
		newnode->item = item;

		// set next to NULL since node is added to tail
		newnode->next = NULL;

		// if is empty, must set head and tail, else just append to tail
		if (isempty(*headptr))
		{
			*headptr = newnode;
			*tailptr = newnode;
		}
		else
		{
			(*tailptr)->next = newnode;
			*tailptr = (*tailptr)->next;
		}
	}

	return;
}


// FUNCTION: dequeue()
// remove a single item from the queue and return its value
// dequeues from the head of the list
int dequeue(node **headptr, node **tailptr)
{
	int item;		// item form dequeued node
	node *nodeptr;	// pointer to node to be dequeued

	// delete from head of list if queue is not empty
	if (isempty(*headptr))
		fprintf(stderr, "Dequeue from empty queue.\n");
	else
	{	
		// keep a pointer to old head node to free() it
		nodeptr = *headptr;

		// store item from old head node
		item = nodeptr->item;

		// make 2nd node in list new head and dealloc old head
		*headptr = (*headptr)->next;
		free(nodeptr);

		// if dequeue last node in list, make sure tail points to null too
		if (*headptr == NULL)
			*tailptr = NULL;
	}

	return item;
}


// FUNCTION: listqueue()
// print all items in queue starting at head
void output(node *head)
{
	node *cursor;		// node pointer to traverse entire list

	printf ("--------------------------All items in the queue:-------------------------\n");
	
	// init cursor to head and print data from each node
	for (cursor=head; cursor != NULL; cursor=cursor->next)
		printf("%d\n", cursor->item);

	return;
}

