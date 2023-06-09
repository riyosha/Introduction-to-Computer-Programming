#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void palindrome_check(char input[]);

int main()  {
    
    char input[20];

    //get user input for word 
    printf("Please enter word you would like to check: ");
    scanf("%[^\n]%*c", input);
    palindrome_check(input);
}

//user-defined function to check for palindromes 
void palindrome_check(char input[]) {
    
    int size = strlen(input); //calculate length of string 
    int unequal =  0;

    for (int i = 0; i<size/2; i++) {
        if (input[i]!=input[size-i-1]) { //compare ith char from beginning with ith char from the end
            unequal = 1;
            break;
        }
    }
    //print result 
    if(unequal!=0) {printf("%s is not a palindrome", input);}
    else {printf("%s is a palindrome", input);}
}

