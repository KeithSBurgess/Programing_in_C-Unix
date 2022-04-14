//
// queue.h: Header file for queue abstract data type
//
// Declarations of node data types and queue functions


// new "node" data type to hold single element of linked-list queue
struct node 
{
	int item;		// data item held by this node (interger data)
	struct node *next;	// pointer to next node in linked list
};

typedef struct node node;


// FUNCTION: isempty()
// return 1 if queue is empty, 0 if is not empty
int isempty(node *head);

// FUNCTION: enqueue()
// insert a single item onto the queue
void enqueue(node **headptr, node**tailptr, int item);

// FUNCTION: dequeue()
// remove a single item from the queue and return its value
int dequeue(node **headptr, node**tailptr);

// FUNCTION: output()
// print all items in queue 
void output(node *head);

