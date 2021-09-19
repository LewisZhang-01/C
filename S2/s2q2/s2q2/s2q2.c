//
//  s2q2.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
//  The conversion principle is to first determine whether n is equal to 0. If n is not 0, put n/2 into the "recursive step", and finally end the "if statement" when n=0, then print the result.
#include <stdio.h>

// Declare the function of "Convert".
int Convert (int n);

int main(void)
{
    int n;
    // Get the values from user.
    printf("Please enter a Decimal number：\n");
    scanf("%d",&n);
    printf("Convert Decimal to Binary is:");
    
    // Convert the decimal number to binary through "Convert()" function.
    Convert(n);
    printf("\n");
    return 0;
}

//Function of "Convert".
int Convert (int n)
{
    if (n!=0)
    {// If n not equal 0, then get into the recursive step.
        Convert(n/2); // [Recursive]
    }
    else
    {// If n equal 0, then end the "if statement".
        return 0;
    }
    printf("%d ",n%2); // Display result.
    return 0;
}
