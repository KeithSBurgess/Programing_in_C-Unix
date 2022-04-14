#include <stdio.h>
int main(void) {
    char c;

    while (scanf("%c",&c) != EOF) {

      if (c == '\n'){
         printf("%s","2");

      }

      else{
         printf("%c",c);  

      }
    }

    return 0;

} // main
