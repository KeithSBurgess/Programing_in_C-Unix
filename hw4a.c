/*
 * Purpose: Implement the use of threads using OPENMP
 * Input: command, int1, int2
 * output: either the sum or product (depends on command) of the provided ints
 * Programmer: Keith Burgess
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

int sum(int num1,int num2);
int mult(int num1,int num2);

int main(int argc, char **argv){
  
  omp_set_num_threads(2); //Sets # of threads to 2
  
  char* command;
  
  int num1,num2;

  if(argc < 4){
    printf("ERROR: Not enough arguments (./a.out sum 2 6)\n");
    exit(1);
  }
  
  command = argv[1];
  num1 = atoi(argv[2]);
  num2 = atoi(argv[3]);
  
  //printf("You Entered: %s %i %i\n",command,num1,num2); // TEST FUNCTION
  
  #pragma omp parallel 
  #pragma omp single 
  {
    #pragma omp task
    {
     if(strcmp(command, "mult")==0){ //if command=mult make thread1 execute mult function
     printf("Created New Thread: %d\n", omp_get_thread_num());
     printf("Result of mult %i and %i = %i\n",num1,num2,mult(num1,num2));
     }
    }
    #pragma omp task
    {
     if(strcmp(command, "sum")==0){ //if command=sum make thread2 execute sum function
     printf("Created New Thread: %d\n", omp_get_thread_num());
     printf("Result of sum %i and %i = %i\n",num1,num2,sum(num1,num2));
     }
    }
    #pragma omp taskwait //wait for threads to finish
    printf("Thread Stopped\n");
   }
  
  return 0;
} // main

/* Function: SUM
 * Input: 2 integers from main
 * Output: Returns sum of the 2 integers
 */
int sum(int num1,int num2){

 return (num1+num2);
}


/* Function: MULT
 * Input: 2 integers from main
 * Output: Returns product of the 2 integers
 */
int mult(int num1,int num2){

 return (num1*num2);
}
