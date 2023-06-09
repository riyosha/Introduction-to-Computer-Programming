#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char a[20];
    char b[20];
    //takes user input for the first string
    printf("This program will check if string b is a prefix of string a. Please enter string a: ");
    scanf("%[^\n]%*c",a); 
    //%[^\n]%*c - %[^\n] instructs the computer to read everything until \n. %*c reads one char, which would be \n, and the discards it

    //takes user input for the second string
    printf("Please enter string b: ");
    scanf("%[^\n]%*c", b);

    int b_length = strlen(b);
    int different = 0;

    //loop compares all characters of string b with first b_length characters of string a
    //if they all are same, different = 0
    for (int i = 0; i<b_length; i++) {if (b[i]!=a[i]) {different = 1; break;}}

    if (different!=0) {printf("%s is not a prefix of %s", b, a);}
    else {printf("%s is a prefix of %s", b, a);}

}