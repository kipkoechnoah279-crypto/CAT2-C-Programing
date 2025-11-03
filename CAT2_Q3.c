/*
Name Noakipkoech 
Reg no:PA106/28709/25
Description:program that reads a list of integers from a file, processes the integers, and writes the results to a different file,perform the following tasks:
-prompts the user to input 10 integers and stores them in a file named "input.txt"
-reads the integers from "input.txt" and calculates the sum and average of the numbers. Then, write the sum and average to another file named "output.txt". 
-reads and displays the contents of both "input.txt" and "output.txt" in a formatted manner.
*/

//preprocessor directives 
#include <stdio.h>
#include <stdlib.h>

void writeInputFile();
void processNumbers();
void displayFiles();

int main() {
    writeInputFile();
    processNumbers();
    displayFiles();
    return 0;
}

// 1. Write 10 integers to input.txt
void writeInputFile() {
    FILE *fp;
    int numbers[10];
    int i;

    fp = fopen("input.text", "w");
    if (fp == NULL) {
        printf("Error: Could not create input.text\n");
        exit(1);
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Integer %d: ", i + 1);
        scanf("%d", &numbers[i]);
        fprintf(fp, "%d ", numbers[i]);
    }

    fclose(fp);
    printf("Data successfully written to input.text\n");
}

// 2. Read integers, calculate sum and average, write to output.txt
void processNumbers() {
    FILE *inputFile, *outputFile;
    int num, sum = 0, count = 0;
    float average;

    inputFile = fopen("input.text", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input.text for reading.\n");
        exit(1);
    }

    while (fscanf(inputFile, "%d", &num) == 1) {
        sum += num;
        count++;
    }
    fclose(inputFile);

    if (count == 0) {
        printf("Error: No numbers found in input.text\n");
        exit(1);
    }

    average = (float) sum / count;

    outputFile = fopen("output.text", "w");
    if (outputFile == NULL) {
        printf("Error: Could not create output.text\n");
        exit(1);
    }

    fprintf(outputFile, "Sum = %d\nAverage = %.2f\n", sum, average);
    fclose(outputFile);

    printf("Sum and average written to output.text\n\n");
}

// 3. Display contents of both files
void displayFiles() {
    FILE *fp;
    char ch;

    printf("Contents of input.text:\n");
    fp = fopen("input.text", "r");
    if (fp == NULL) {
        printf("Error: Could not open input.text for display.\n");
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);

    printf("Contents of output.text:\n");
    fp = fopen("output.text", "r");
    if (fp == NULL) {
        printf("Error: Could not open output.text for display.\n");
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);

    printf("\n");
}