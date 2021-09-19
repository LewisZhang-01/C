//
//  s5q2.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reverseArray(int arraySize, int a[])
{
    printf("Reverse order:\n");
    if (arraySize%2==0)
    {// If array have even number elements.
        int last=arraySize-1;
        
        int first=0, temp=0;
        while (first<=arraySize/2)
        {// Swap the "first" element and "last" element.
            temp = a[first];
            a[first] = a[last];
            a[last] = temp;
            // Then, increase i and decrease "last" value.
            first++;
            last--;
        }
    }
    else
    {// Otherwise array have odd number elements.
        int last=arraySize-1;
        int first=0, temp=0;
        while (first<(arraySize/2)+1)
        {// Swap the "first" element and "last" element.
            temp = a[first];
            a[first] = a[last];
            a[last] = temp;
            // Then, increase i and decrease "last" value.
            first++;
            last--;
        }
    }
    
}

void randomiseArray(int arraySize, int a[])
{
    printf("Random order:\n");
    int i,j,check[arraySize];
    // Use a different seed value so that we don't get same result each time we run this program.
    srand(time(NULL));
    
    for (i=0; i<arraySize; i++) // Outer loop.
    {
        check[i]=rand() % arraySize; // Assign random numbers between 0 and max value of arraysize to the array.
        
        for (j=0;j<i;j++) // Inner loop.
        {
            if(check[j] == check[i])
            {// Determine whether or not the same number is created.
                break;
            }
        }
        
        if(i != j)
        {// Normally (no number is the same) the inner loop ends when j = j. Therefore, when the break occurs, i will not be equal to j. Before returning to the outer loop, i will need to subtract 1 in order to reassign a random value to the current position of array.
            i--;
        }
        
        // Swap arr[i] with the element at random index
        int temp=0;
        temp = a[i];
        a[i] = a[check[i]];
        a[check[i]] = temp;
    }
}

void printArray(int arraySize, int a[])
{
    // Pointer to functions.
    void (*arrayFunction[2])(int arraySize, int a[])={reverseArray,randomiseArray};
    
    // Ask the user to enter a selection.
    printf("Please enter choice:\n0 for reverse order,\n1 for random order.\n");
    size_t choice;
    scanf("%zu",&choice);
    
    // Give solution for user's chiose.
    if (choice==0||choice==1)
    {
        // Call specific functions based on the user's choice.
        (*arrayFunction[choice])(arraySize,a);
        
        // Display result.
        for (int i = 0; i < arraySize; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");// New line.
    }
}

int main(void)
{
    // Declare an array contain numbers.
    int myArray[] = {2,4,6,8,10,12,14,16,18,20};
    printArray(10,myArray);// Call "printArray" function.
    return 0;
}
