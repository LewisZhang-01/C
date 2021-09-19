//
//  s2q4.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
#include <stdio.h>

// Declare the function of "multi".
int multi(int n, int i);

int main(void)
{
    int n, i;
    
    // Get the values from user.
    printf("Please enter the number of the multiplication table:\n");
    scanf("%d",&n);
    printf("Please enter the size of the multiplication table:\n");
    scanf("%d",&i);
    printf("The multiplication tables is:\n");
    
    // Caculate the multiplication table for input by user.
    multi(n,i);
   
    return 0;
}

//Function of "multi".
int multi(int n, int i)
{
    if (n*i==n)
    {// If n*i equal n, then print that value and end the if statement.
        printf("%d\n",n*i);
        return 0;
    }
    else
    {// If n*i not equal n, then get into the recursive step.
        multi(n, i-1); // [Recursive]
    }
    printf("%d\n",n*i); // Display result.
    return 0;
}
