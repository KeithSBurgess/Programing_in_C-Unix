/*
 * Purpose (of Program): Simulate a bus stop
 *
 * Assumption: File contains a set format
 *
 * Input: File
 *
 * Output: integers
 *
 * Algorithm (or processing logic): Scanf store info in arrays (Using structers and malloc)
 *
 * Programmer: Keith Burgess
 */



#include <stdio.h>
#include <stdlib.h> // for malloc() and exit()


typedef struct arrival_struct
{
    int time;       // time of arrival
    int count;      // number of passengers/seats arriving
} itemtype;



int main(void) {
    itemtype item;
    int *time[10]; // stores all dynamic memory arrays
    int code;
    int totalPassenger=0;
    int i;
    int  *a; //dynamic memory base address
    int top=0;// #batches-1
    int required[10]; // stores # of passenger up to 10 arrive at the same time in batch
// required[]=(2,1,4,2,9)
    int j=0; // represents batches of passenger arrivals
// read in code until eof
// check if code is 0, then call passenger function else call bus function
    
    while (scanf("%i", &code) !=EOF) {
    // Write 1-2 lines below to read rest of data line (2 numbers)
    // into the variable item with item type structure(time and count fields)

      scanf("%i",&item.time);

      scanf("%i",&item.count);


      if (code == 0){
        required[j]=item.count;
        // write a line below to update totalPassenger
        totalPassenger=totalPassenger+item.count;
        
// Modify the following line to request int dynamic memory quantity=required[j]
        a=(int *)malloc(required[j]*sizeof(int));
        // check whether the request of the dynamic memory is successful
        if (a == 0){
          printf("Error: Heap is full!\n");
          exit(1);
        } // if
        // stores the dynamic memory in time[j]
        time[j]=a;
        // fill in the dynamic memory with passenger arrival time in jth batch
        for (i=0;i<required[j];i++){
          // write a line  below to store arrival time: item.time
          // at each dynamic memory (address=time[j]+i) with starting address time[j]
          *(time[j]+i)= item.time;
        } // for
      j++;
      } // if
    } // while
    printf("Total Passenger = %d\n", totalPassenger);
    // top: stores #of passenger batches-1
    top=j;
    for (j=0;j<top;j++) {
      for(i=0;i<required[j];i++) {
	      printf("time=%i\n",*(time[j]+i));
      } // for i
      // write a line below to free up dynamic memeory with base addresses time[j]
      free(time[j]);

    } // for j

    return 0;

}// main



