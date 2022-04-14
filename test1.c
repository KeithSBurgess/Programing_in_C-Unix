/*
 * Purpose:
 *
 * Assumption:
 *
 * Input:
 *
 * Output:
 *
 * Algorithm: 
 *
 * Programmer:
 */

#include <stdio.h>

#define MAX_STUDENTS 100
#define TOTAL_QUESTIONS 29
const int MAX_CHOICES = 5;

void readKey(int key[TOTAL_QUESTIONS]);
int readAnswer(int answer[MAX_STUDENTS][TOTAL_QUESTIONS]);
char convertChar (int ans);
void PrintKeyHeading(void);
void PrintAnswerHeading(void);
void printAvgHeading(void);
void outputKey(int key[], int n);
void outputData(int answer[MAX_STUDENTS][TOTAL_QUESTIONS], int miss[][TOTAL_QUESTIONS], double grade[], int n);

void findGrade(int key[TOTAL_QUESTIONS],int answer[][TOTAL_QUESTIONS],int count,double grade[],int miss[][TOTAL_QUESTIONS]);
double findAvg(double grade[],int count);
void outputResult(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS], int count, double grade[], int miss[][TOTAL_QUESTIONS],double question_correct [TOTAL_QUESTIONS],int question_response[MAX_STUDENTS][MAX_CHOICES+1],int frequency[MAX_STUDENTS]);
void findQuestion(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS], int count, int question_response[][MAX_CHOICES+1], double question_correct [TOTAL_QUESTIONS]); 
void sortGrade(double grade[], int n);
double findMedian(double grade[],int count);
double findFrequency(double grade[], int frequency[], int count);

int main(void) {
	
	char c;
	int n;
        double avg;	

	int key[TOTAL_QUESTIONS];
	int answer[MAX_STUDENTS][TOTAL_QUESTIONS];
	int miss[MAX_STUDENTS][TOTAL_QUESTIONS];
	int correct[TOTAL_QUESTIONS];
	double grade[MAX_STUDENTS];
        int question_response[MAX_STUDENTS][MAX_CHOICES+1];
        double question_correct[TOTAL_QUESTIONS];
	int frequency[MAX_STUDENTS];
	readKey(key);
	n = readAnswer(answer);
	findGrade(key, answer, n, grade, miss);

	PrintKeyHeading();
	outputKey(key, n);
	PrintAnswerHeading();
	outputData(answer,miss,grade,n);
		
	printAvgHeading();
	avg = findAvg(grade,n);
	findQuestion(key,answer,n,question_response,question_correct);

	outputResult(key,answer,n,grade,miss,question_correct,question_response,frequency);

  return 0;
} // main



/* sortgrade: sorts grades in descending order
 * input fron main: grade,n
 * output to main: none
 */

void sortGrade(double grade[], int n){
  double temp;
  for (int i=0;i<n; i++){
    for (int j=i+1;j<n;j++){
                
      if (grade[i] < grade[j]){
        temp = grade[i];
        grade[i] = grade[j];
        grade[j] = temp;
      }

    }// for j
  }// for i
 
  for (int i = 0; i < n; ++i){
    printf("%.2lf\n", grade[i]);
  }
}// sortGrade




/*
 * findQuestion: gets question avg and answer frequency
 * input from main: key,answer,count,question_response,question_correct
 * output to main: none
 */

void findQuestion(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS], int count, int question_response[][MAX_CHOICES+1], double question_correct[TOTAL_QUESTIONS]){

  double sum=0;
  
  for(int j=0;j<TOTAL_QUESTIONS;j++){
    
    sum=0;
      for(int i=0;i<count;i++){
        
        if(key[j] == answer[i][j]){ //Checking if question j matches student i answer
          sum=sum+1;
        }
      }
      question_correct[j]= 100.00*(sum/count); //% students got question j correct
    
  }


  int BLANK;
  int A;
  int B;
  int C;
  int D;
  int E;

  for(int j=0;j<TOTAL_QUESTIONS;j++){
    BLANK=0;
    A=0;
    B=0;
    C=0;
    D=0;
    E=0;
    
      for(int i=0;i<count;i++){

        if(convertChar(answer[i][j]) == ' '){ //if question j = ' ' for student i
          BLANK++;
        }
	
	else if(answer[i][j] == 1){ //if question j = 1 for student i
          A++;
        }

	else if(answer[i][j] == 2){ //if question j = 2 for student i
          B++;
        }

	else if(answer[i][j] == 3){ //if question j = 3 for student i
          C++;
        }

	else if(answer[i][j] == 4){ //if question j = 4 for student i
          D++;
        }

	else if(answer[i][j] == 5){ //if question j = 5 for student i
          E++;
        }

	
      } // for i

      question_response[j][0]= BLANK;
      question_response[j][1]= A;
      question_response[j][2]= B;
      question_response[j][3]= C;
      question_response[j][4]= D;
      question_response[j][5]= E;
  }// for j

}// findQuestion

/*
 * outputResult: prints contents below AvgHeading
 * input from main: key,answer,count,grade,miss
 * output to main: none
 */


void outputResult(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS], int count, double grade[], int miss[][TOTAL_QUESTIONS],double question_correct[TOTAL_QUESTIONS],int question_response[][MAX_CHOICES+1],int frequency[MAX_STUDENTS]){

int i, j;
double  mode;

   for (i=0; i<TOTAL_QUESTIONS; i++) {

     printf("%i\t\t", i+1);
     printf("%c\t",convertChar(key[i]));
     printf("%.2lf\t\t",question_correct[i]);
     printf("%i\t%i\t%i\t%i\t%i\t%i",question_response[i][0],question_response[i][1],question_response[i][2],question_response[i][3],question_response[i][4],question_response[i][5]);
     printf("\n"); 
  }// for

   printf("\nThe class average is %.2lf\n",findAvg(grade,count));
   printf("\nAfter sort:\nGrade\n");
   sortGrade(grade,count);
   printf("\nThe median is %.2lf\n\n",findMedian(grade,count));
   printf("Grade\tFrequency\n");
   mode=findFrequency(grade,frequency,count);
   printf("\nThe mode is %.2lf\n",mode);
   
   printf("\n");
  

}// outputResult


/*
 * findMedian: find median
 * input from main: grade,count
 * output to main: median
 */

double findMedian(double grade[],int count){
  double median;

  if(count  % 2 == 0){
    median = (grade[count/2] + grade[count/2+1])/2.0 ;
  } 
  else{
   median = grade[count/2 + 1];
  }

 return median;
}// findMedian



/*
 * findFrequency: finds the Frequency of each grade
 * input from main: grade,frequency,count
 * output to main: frequency list
 */


double findFrequency(double grade[], int frequency[], int count){
  int max=0;
  double mode;
  for (int i=0;i<count;i++){
    
    for (int j=0; j<count;j++){
    
      if (grade[i]==grade[j]){
        frequency[i]++;
      }
      if (frequency[i] > max){
        max = frequency[i];
        mode = grade[i];  
      }
    
    }// for j
  
  }// for i

  for (int i=0;i<count;i++){
      
      if (grade[i]!=grade[i+1]){
        printf("%.2lf\t%i\n",grade[i],frequency[i]);
      }

  }// for i

return mode;
}// findFrequency



/*
 * findAvg: finds average
 * input from main: grade and count
 * output to main: average
 */


double findAvg(double grade[],int count){
  double sum=0;
  
  for (int i=0;i<count;i++){
    sum = grade[i]+ sum;
  }
return (sum/count);
}// findAvg


/*
 * printAvgHeading: prints heading for average
 * input from main: none
 * output to main: none
 */

void printAvgHeading(void){
  printf("\nQuestion\tKey\tCorrect %%\tNumber of Responses\n\t\t\tStudents\tBLANK\tA\tB\tC\tD\tE\n");
}// printAvgHeading


/*
 * findGrade: calculates grade and stores Correct/Missed questions
 * input from main: none
 * output to main: a char grade
 */

void findGrade(int key[TOTAL_QUESTIONS],int answer[][TOTAL_QUESTIONS],int count,double grade[],int miss[][TOTAL_QUESTIONS]){

int temp; //questions correct

for(int i=0;i<count;i++){
  temp = 0;
  for(int j=0;j<TOTAL_QUESTIONS;j++){

    if (key[j] != answer[i][j]){
      miss[i][j] = j+1; // j+1 = Question # 
    }// if
    else{
      temp++;
    }

  }// for j
  grade[i]= 100.0*temp/TOTAL_QUESTIONS;

}// for i

}// findGrade



/* 
 * readKey:read keys of all questions into a 1D array
 * input from main: none
 * output to main: a 1D key array (int)
 */

void readKey(int key[TOTAL_QUESTIONS]) {
	int i;
	char c;
	char garbage[1000];

	scanf("%75c",garbage);
	for (i=0;i<TOTAL_QUESTIONS; i++){
		scanf("%c",&c);
		key[i] = c - '0';
   }
  	scanf("%[^\n]", garbage); // skip reading the rest line
	scanf("%c", &c); // skip reading '\n'
   
} // readKey



/* 
 * readAnswer:read answers of all questions into a 2D array
 * input from main: none
 * output to main: a 2D answer array (int)
 */

int readAnswer(int answer[MAX_STUDENTS][TOTAL_QUESTIONS]) {
   int i=0, j;
   char c;
   char garbage[1000];

   while (scanf("%c", &c) != EOF) {
        scanf("%74c",garbage);

	for (j=0;j<TOTAL_QUESTIONS; j++){
 	   scanf("%c",&c);
	   if (c == ' ' || c == '*'){
	   answer[i][j]=0;}
	   else{
	   answer[i][j] = c - '0';}

	}// for
	scanf("%[^\n]", garbage); // skip reading the rest line
	scanf("%c", &c); // skip reading '\n'
	i++;
  } // while

  return i;
   
} // readAnswer



/* 
 * PrintKeyHeading:print a Key heading
 * input from main: none
 * output to main: none
 */

void PrintKeyHeading(void){
  printf("%s", "Key:\t");	
}



/* 
 * PrintAnswerHeading:print answer heading
 * input from main: none
 * output to main: none
 */


void PrintAnswerHeading(void){	
  printf("%s", "\nStudent\tGrade\t\tAnswer\t\t\t\tWrong Questions\n");
}



/* 
 * outputKey: print a 1D key array
 * input from main: a 1D key array (int), array size n(int)
 * output to main: none
 */


void outputKey(int key[], int n) {
 
	int i;
 
	for (i=0; i< TOTAL_QUESTIONS; i++){
		printf("%c", convertChar(key[i]));
	}
	printf("%s", "\n");


} // outputKey



/* 
 * outputData:print answers, miss, grade arrays
 * input from main: answers(int), miss(int), grade(double) arrays
 * output to main: none
 */

void outputData(int answer[MAX_STUDENTS][TOTAL_QUESTIONS], int miss[][TOTAL_QUESTIONS], double grade[], int n) {

	int i, j;

   for (i=0; i<n; i++) {
	   
   printf("%i\t", i+1);
   printf("%.2lf\t", grade[i]);
   for (j=0; j<TOTAL_QUESTIONS; j++){
		printf("%c" , convertChar(answer[i][j]));	
	}
 printf("\t");
   for (j=0; j<TOTAL_QUESTIONS; j++){
     if (miss[i][j] != 0){
       printf("%i ", miss[i][j]);
     }
   }
  printf("%s", "\n");
  } // for
} // outputData



char convertChar (int ans) {
   switch (ans) {
      case 1:
	 return 'A';
	 break;
      case 2:
	 return 'B';
	 break;
      case 3:
	 return 'C';
	 break;
      case 4:
	 return 'D';
	 break;
      case 5:
	 return 'E';
	 break;
      default:
	 return ' ';
   }
}


