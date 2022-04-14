/*
 * a.	Purpose (of Program): Change Fahrenheit to Celsius using Functions
 * b.	Assumption: What domain of data you are restricting
 * c.	Input: variables(with data types) available
 * d.	Output: variables to display
 * e.	Algorithm (or processing logic): How to reach output from input
 * f.	programmer: Keith Burgess
*/



#include <stdio.h>

void PrintHeading(void);
int GetInput(double F[]);
void ProcessData(double F[], int count, double C[]);
void OutputResult(double F[], int count, double C[]);

int main(void) {
    char c;
    int i;
    double F[1000];
    double C[1000];
    int count;

 printf("\n");

    count = GetInput(F);

    ProcessData(F,count,C);

    PrintHeading();

    OutputResult(F,count,C);

 printf("\n");

    return 0;

}//main

//----------------------------------------------------------------
void PrintHeading(){

   printf("\t\tFahrenheit\tCelsius\n\t\t__________\t_______\n");
   
}//PrintHeading


int GetInput(double F[1000]){
	int i = 0;
	double num;
        double SENTINEL = -1.000000;

	scanf("%lf",&num);
	
 while(num != SENTINEL){
      F[i] = num;
      scanf("%lf",&num);
      i++;
  }
return i;
}//GetInput


void ProcessData(double F[1000],int count,double C[1000]){
 const double CONVERFACTOR = 9.0/5.0;
 	
   for(int i=0;i<count;i++){
      C[i]=(F[i] - 32.0)/CONVERFACTOR;

   }


}//ProcessData


void OutputResult(double F[1000],int count,double C[1000]){

   for(int i=0;i < count; i++){
      printf("\t\t%.2lf\t\t%.2lf\n",F[i],C[i]);
   }

}//OutputResult

