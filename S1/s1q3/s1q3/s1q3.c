//
//  s1q3.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
#include <stdio.h>

int main(void)
{
    int i,counter,Num;
    counter=0;
    
    // Get number input from user.
    printf("Please enter any number to check if it is a prime number:\n");
    scanf("%d",&Num);
    
    if (Num <= 1)
    {// Some solutions are given for special cases of user input.
        if (Num < 1)
        {
            printf("Invalid input!\n");
        }
        if (Num == 1)
        {
            printf("1 is not prime number.\n");
        }
    }
    else
    {
        for (i=2; i<Num; i++)
        {// Divide "Num" by every integer from 2 to "Num"-1 .
            if (Num % i == 0)
            {// If number is divisible, add 1 to counter.
                counter++;
            }
        }
        
        if (counter == 0)
        {// If the counter is = 0, then this number is prime.
            printf("%d is prime number.\n",Num);
        }
        else
        {// If the counter is > 0, then this number is not prime.
            printf("%d is not prime number.\n",Num);
        }
    }
    
    return 0;
}
