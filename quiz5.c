/*
 * Purpose (of Program): Filter out garbage to retrieve ID and Name
 *
 * Assumption: File contains a set format 
 *
 * Input: File
 *
 * Output: characters
 *
 * Algorithm (or processing logic): Using scanf ranges and arrays to store info
 *
 * Programmer: Keith Burgess
 * */

#include <stdio.h>
#include <string.h>

void getID(char id[16]);
void outputID(char id[]);
void getName(char name[21]);
void outputName(char name[21]);


int main(void) {
   char id[16];
   char name[21];
   char c;

   printf("ID\t\tNAME\n");//Format statement

   while (scanf("%c", &c) != EOF) {
      getID(id);
      outputID(id);
      getName(name);
      outputName(name);
   } // while

   return 0;
} // main

//---------------------------

/* Retrieves ID from a pre-determined
 * set of columns. First 39 columns put into
 * garbage array.
*/

void getID(char id[16]) {
   int i;
   char garbage[1000]; // dumpster

   scanf("%39c",garbage);
   scanf("%15c",id);         

    
   

  id[15] = '\0'; // end with null character

} // getID


/* Prints out ID from the
 * ID array and also filters 
 * out leading whitespace
*/
 
void outputID(char id[]) {

   char id6[7]="      ";
   
    if (strncmp(id,"               ",16)!=0) {
            sscanf(id,"%s", id6);
    }//if
   
   printf("%s", id6);

} //outputID


/* Retrieves Name from a pre-determined
 * set of columns
*/

void getName(char name[21]) {
  
  
   char c;
   char garbage[1000];

   scanf("%20c", name);

   name[20]='\0';
   scanf("%[^\n]", garbage);


   scanf("%c", &c); // skip newline character
   
} // getName


/* Prints out the Name
 * from the Name array
*/
 
void outputName(char name[21]) {
   
   printf(" %s\n", name);

} // outputName

