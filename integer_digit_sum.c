#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int input, sum  = 0;

    //get integer input from  user
    printf("Please enter an integer: ");
    scanf("%i", &input); 
    if (input<0) {input=-input;}

    for(int i = input; i>=1; i = (i - i%10)/10) {
        sum = sum+i%10;
    }

    printf("Sum of  the digits of %i is %i", input, sum);
}