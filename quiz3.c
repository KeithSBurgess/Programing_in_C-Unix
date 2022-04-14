/*
 *a.	Purpose (of Program):Find how many lines, spaces, tabs, letters, and white space in beep.c
 *b.	Assumption: Just beep.c 
 *c.	Input: beep.c
 *d.	Output: CHECK PURPOSE
 *e.	Algorithm (or processing logic): How to reach output from input
 *f.	programmer:Keith Burgess
 *    
 */


#include <stdio.h>
#include <ctype.h>


int main (void){
   char c;

   int countLetter=0;
   int countDigit=0;
   int countNewLine=0;
   int countTab=0;
   int countSpace=0;

   //int other=0;

   while(scanf("%c",&c) != EOF){

      if(isalpha(c)){
         countLetter++;
      }

      else if(isdigit(c)){
         countDigit++;

      }

      else if(c == '\n'){
         countNewLine++;

      }


      else if(c == '\t'){
         countTab++;

      }

      else if(c == ' '){
         countSpace++;

      }


  //    else{
  //       other++;
  //    }


   }//while


   printf("There are\n");
   printf("%i letters\n",countLetter);
   printf("%i digits\n",countDigit);
   printf("%i lines\n",countNewLine);
   printf("%i tabs\n",countTab);
   printf("%i spaces\n",countSpace);

//   printf("%i Other\n",other);

return 0;
}
