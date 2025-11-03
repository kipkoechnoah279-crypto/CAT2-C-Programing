/*
Name: Noah kipkoech 
Reg no:PA106/G/28706/25
Description :program to prompt requests the user to enter hours worked in a week and the hourly wage and print the gross pay,the taxes and the net pay
*/

//preprocessor directive
#include <stdio.h>

//main function 
int main()
{
//variable declaration 
    float hours,wage,gross_pay=0.0,taxes=0.0,net_pay=0.0,overtime_hours,taxable_rest;

//prompt the user
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);

    printf("Enter the hourly wage: $");
    scanf("%f", &wage);

    if (hours > 40.0)
    {
        gross_pay = 40.0 * wage;
        overtime_hours = hours - 40.0;
        gross_pay += overtime_hours * wage * 1.5;
    }
    else
    {
        gross_pay = hours * wage;
    }

    if (gross_pay <= 600.0)
    {
        taxes = gross_pay * 0.15;
    }
    else
    {
        taxes = 600.0 * 0.15;
        taxable_rest = gross_pay - 600.0;
        taxes += taxable_rest * 0.20;
    }

    net_pay = gross_pay - taxes;
// display the results 
    printf("\n    Payroll Summary    \n");
    printf("Gross Pay: $%.2f\n", gross_pay);
    printf("Taxes Paid: $%.2f\n", taxes);
    printf("Net Pay: $%.2f\n", net_pay);

    return 0;
}