#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    
    //user input for size of array
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    while(size<1) {printf("Error. Please enter a positive size of the array: "); scanf("%d", &size);}

    int array[size];
    int element;

    //user input for elements of array
    for (int i = 0; i < size; i++) {
        printf("Please enter element %i of array: ", i);
        scanf("%i", &element);
        array[i] = element;
    }

    int flag=0;

    for(int i=0; i<=size-1; i++) {//iterates through array
        if (array[i]>array[i+1]) {//checks if every element is in ascending order
            flag=1;
            break;
        }
    }
    if(flag==0) {
        printf("Array is sorted");
    } else {
        printf("Array is not sorted");
    }

}