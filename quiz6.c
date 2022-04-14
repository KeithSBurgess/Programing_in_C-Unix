/* a.	Purpose (of Program): Show parameters in all command options
** b.	Assumption: Only 2 parameters (-s and -t)
** c.	Input: Parameters in string format
** d.	Output: Result of paramater + string
** e.	Algorithm (or processing logic):check 1st + 2nd chars and output desired**      outcome with if statements
** f.	Programmer: Keith Burgess
** Run Command: a.out -L parm1 parm2 -2ndoption parm3
*/

#include <stdio.h>

int main (int argc, char* argv[]){
 int i;

 i=1;
 while (argv[i] != NULL) {
   // find option
   if (argv[i][0] == '-'){
      
      if(argv[i][1] == 's'){
         printf("Service: ");
      } //if
      
      else if(argv[i][1] == 't'){
         printf("Time: ");
      } //else if
      
      
      
      printf("%s\n",argv[i]+2);
      } //if
      
      i++;
    
 } // while

 return 0;

} //main
