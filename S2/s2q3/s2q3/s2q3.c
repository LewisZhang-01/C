//
//  s2q3.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 5

int main(void)
{
    int i,j;
    int a[MAX_SIZE];
    
    // Use srand and time fuction to ensure that each run starts with a different seed to produce a truly random number.
    srand(time(NULL));
    
    for (i=0; i<5; i++) // Outer loop.
    {// Use for loop to get random number 5 times.
        
        a[i]=rand() % 39+1; // Assign random Numbers between 1 and 29 to the array.
        
        for (j=0;j<i;j++) // Inner loop.
        {
            if(a[j] == a[i])
            {// Determine whether or not the same number is created.
                break;
            }
        }
        
        if(i != j)
        {// Normally (no number is the same) the inner loop ends when j = j. Therefore, when the break occurs, i will not be equal to j. Before returning to the outer loop, i will need to subtract 1 in order to reassign a random value to the current position of array.
            i--;
        }
    }
    
    for (i=0; i<5; i++)
    {
        printf("%d ",a[i]);
    }
    
    // Print a random number between 1-14.
    printf("\nThunderball: %d\n",rand() % 14+1);
    
    return 0;
}
