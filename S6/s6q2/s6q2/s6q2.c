//
//  s6q2.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
#include <stdio.h>

// Declares the following functions.
void myprinter(int a, int b, int(*calculator)(int a, int b));
int multiplier(int a, int b);
int adder(int a, int b);

int main()
{
    // Declare some variables.
    int num_1 ,num_2, calcType;
    
    // Get first number from user inputs.
    printf("Enter the first number: ");
    scanf("%d",&num_1);
    
    // Get second number from user inputs.
    printf("Enter the second number: ");
    scanf("%d",&num_2);
    
    // Request calculation type from user inputs.
    printf("Enter 1 for multiply or 2 for addition: ");
    scanf("%d",&calcType);
    
    // Check the type which user wants to use.
    if (calcType==1)
    {
        myprinter(num_1, num_2, multiplier);// Call "multiplier" function.
    }
    else if (calcType==2)
    {
        myprinter(num_1, num_2, adder);// Call "adder" function.
    }
    else
    {// Give some solution for enter numbers other than 1 and 2.
        printf("Error, Please enter 1 or 2\n");
    }
    
    return 0;
}

// "myPrinter" function  which takes in a variable number of arguments of any type.
void myprinter(int a, int b, int(*calculator)(int a, int b))
{
    int result = (*calculator)(a,b);
    printf("Result: %d\n",result);
}

// "multiplier" funtion which has a variable number of integers as arguments.
int multiplier(int a, int b)
{
    return a*b;// Returns the product of the integers.
}

// "Adder" funtion which has a variable number of integers as arguments.
int adder(int a, int b)
{
    return a+b;// Returns the sum of the integers.
}
