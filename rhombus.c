#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    //declaring variable
    int size;
    
    //taking user input for size
    printf("Please enter size of rhombus (positive integer only): ");
    scanf("%i", &size);

    //use loop to print required number of rows
    for (int j = 0; j<size; j++) {
        //use loop to print required number of spaces in a row
        for (int i=0; i<size-j;i++) {
            printf(" ");
        }
        //use loop to print required number of * in a row 
        for (int k=0; k<size;  k++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;


}