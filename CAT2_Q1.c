/*
Name :Noakipkoech 
Reg no:PA106/G/28709/25
Description :program to print elements of 2D scores arrays 
*/

//preprocessor directive 
#include <stdio.h>

//main function 
int main() {
    //(i) Define an array
    // An array is a collection of elements of the same type stored in contiguous memory locations.

     // (ii) Declare and initialize a 2D array named 'scores'
    int scores[4][2] = {
        {65, 92},
        {84, 72},
        {35, 70},
        {59, 67}
    };

    int i, j;
 //(iii) Print elements using nested for loops
    printf("Elements of the scores array:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }

    return 0;
}