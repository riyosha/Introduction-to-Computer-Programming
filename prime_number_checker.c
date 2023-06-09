#include <stdio.h>
#include <stdlib.h>

int main (){
    
    //declaring variables
    int number;
    int factors = 0;

    //take user input
    printf("Please enter decimal integer (positive): ");
    scanf("%d", &number);

    //checks divisibility of number by all numbers from 1 to number/2 and prints them in a list using loop
    printf("Factors of the %i number are: ",  number);
    for(int i = 1; i<=number/2;i++) {
        if (number%i == 0) {
            printf("%i, ", i);
            factors++;
        }
    }

    //prints the number itself as a factor
    printf("%i", number);
    factors++;
    printf("\n");

    //determines whether number is prime or not depending on value of counter 'factors'
    if (factors == 2) {
        printf("%i is a prime number!", number);
    } else {
        printf("%i is not a prime number", number);
    }

    return  0;
}