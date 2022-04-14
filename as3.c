/*
 * a.	Purpose: Filter out garbage and print answers
 * b.	Assumptions: Reading integers
 * c.	Input: File name
 * d.	Output: Answers in the form of integers
 * e.	Algorithm: Skip Lines and Skip Chararacters
 * f.	Programmer: Keith Burgess
 *
 */
#include <ctype.h>
#include <stdio.h>

void skipNchar (int n);
void skipALine (void);
int getData(char answer[100][50]);
void outputResult(char asnwer[100][50], int n);

int main(void) {
   int n; //number of students
   char character;
   char answer[100][50]; //100 students 50 answers
   
   
   n = getData(answer);
   
   outputResult(answer,n);

}//main

//------------------------------------
void skipALine(void){
   char c;
   
   scanf("%c",&c);
   while (c != '\n'){
      scanf("%c",&c);
   }
} // skipALine


void skipNchar (int n) {
    int i;
    char c;

    for (i=0;i<n;i++)
	scanf("%c",&c);

} // skipNchar


int getData (char answer[100][50]) {
    int i=0; // array row index: # of students
    int j=0; // question index


    skipALine();

    while (scanf ("%c",&answer[i][j])!= EOF) {
      //skip 28 characters
      skipNchar(28);
      
      // read answers
      for (j=0;j<19;j++)  {
         scanf ("%c",&answer[i][j]);
         if(isspace(answer[i][j])){
            answer[i][j] = '*';
         }
      }
      
      skipALine();
       i+=1; // increment counter
    } // while
    
    return i;
} //getData


void outputResult(char answer[100][50], int n) {
   int i, j;

   for(int i=0; i < n; i++){
      for(int j=0; j < 19; j++){
      printf("%c",answer[i][j]);
      }
   printf("\n");
   }
 


}


