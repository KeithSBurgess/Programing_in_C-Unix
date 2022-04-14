#include <stdio.h>
#include "queue.h"

typedef struct arrival_struct
{
    int time;       // time of arrival
    int count;      // number of passengers/seats arriving
} itemtype;



// function prototypes
void passenger(node **headptr, node **tailptr, itemtype *arrival);
double bus(node **headptr, node **tailptr, itemtype *arrival);
//
//

int main(void) {
    node *head=NULL, *tail=NULL;
    itemtype item;

    int code;
    double waitTime;
    int totalPassengers=0;
    
    printf("\n"); // formatting

    // read in code until eof
    while(scanf("%i",&code) !=EOF){    
	// read rest of data line into the variable item with item type structure
        scanf("%i",&item.time);
	scanf("%i",&item.count);

	// check if code is 0, then call passenger function else call bus function
	if (code == 0){
	  // shows how to call passenger function
	  // //        passenger(&head, &tail, &item);

	  if(item.count == 1){ // format for 1 Person
	    printf("%i person arrived at time %i\n",item.count,item.time);
	  }
	  else{
	    printf("%i persons arrived at time %i\n",item.count,item.time);
	  }
	  totalPassengers = totalPassengers + item.count;
	  
          passenger(&head, &tail, &item);
	}

	else{
	  printf("bus arrived at time %i with %i seats available\n",item.time,item.count);
	  waitTime = waitTime + bus(&head,&tail,&item);
	}
	//
//    else
//    {
//	store waiting time when call bus function and then accumulate total waiting time and total passengers
//	waitTime = bus(&head,&tail,&item);
// find totalWaitTime from each waitTime
//    }

    } // while
    
    printf("\nTotal %i persons waited for %.0lf minutes, the average time %.2lf\n\n",totalPassengers,waitTime,(waitTime/totalPassengers));
    
    
    return 0;
}



/*





*/
void passenger(node **headptr, node **tailptr, itemtype *arrival) {
//
// for loop to enqueue each passenger's arrival time	
// call enqueue: enqueue (headptr, tailptr, arrival->time); 
// note there is no time vartiable in the function, but it has pointer arrival 
// replace time using the pointer arrival
    for(int i=0;i<arrival->count;i++){
      enqueue (headptr, tailptr, arrival->time);
    }

}


/*



*/
double bus(node **headptr, node **tailptr, itemtype *arrival) {
//
// for loop to dequeue each passenger	
// call dequeue: dequeue (headptr, tailptr);  
// note this will return the passenger arrival time (int data type)
// You need to calculate each passenger's waiting time & sum them up
// and then return the total waiting time
    double waitingTime=0; // bus arrive time - passenger current time
    double temp=0;
    int arrivalTime;
    for(int i=0;i<arrival->count;i++){
      arrivalTime = dequeue (headptr, tailptr);
      temp = (arrival->time)-arrivalTime;
      waitingTime = waitingTime+temp;
    }
    
    return waitingTime;
}
