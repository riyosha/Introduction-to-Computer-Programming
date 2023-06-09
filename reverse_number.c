#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int reverse_number(int number);

int main() {

    int digit =0, number;
    
    //take user input
    printf("Please enter decimal integer: ");
    scanf("%i", &number);

    if (number<0) {
        //convert negative number to positive number
        number = number*(-1);
    } else if (0==number) {
        //if number is 0, simply return 0
        printf("The entered number is 0");
        return 0;
    }

    //reverse user's number so that the output is printed in order
    number = reverse_number(number);

    printf("The digits in the number are: ");

    //use loop to separate and print digits in the inputted number
    for(int i = number, j = 0; i>1; i = (i - digit)/10, j++) {
        digit = i%10;
        printf(i<10?"%i":"%i, ", digit);
    }

    return 0;

}

//function that reverses a number
int reverse_number(int number) {

    int reverse = 0, remainder;

    while (number != 0) {
        remainder = number % 10;
        reverse = reverse*10 + remainder;
        number = number/10;
    }

    return reverse;
}
