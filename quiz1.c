/*





*/


#include <stdio.h>

int main(void) {

const double CONVERFACTOR = 9.0/5.0;

double celsius, fahrenheit;

printf("%s", "Please enter a Fahrenheit degree: ");
scanf("%lf",&fahrenheit);

celsius = (fahrenheit - 32.0)/CONVERFACTOR;

printf("%.2lf degrees Fahrenheit is %.2lf Celsius\n",fahrenheit, celsius);


return 0;

}//main
