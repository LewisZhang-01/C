//
//  s4q2.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
#include <stdio.h>

// Declare two functions.
void copyArrayIndexWay(char * const newArray1, const char * const originalArray1);
void copyPointerWay(char *newArray2, const char *originalArray2);

int main(void)
{
    // Declare some arrays.
    char originalArray1[] ="COMP10120";
    char originalArray2[] = "COMP10110";
    char newArray1[10],newArray2[10];
    
    // Call these two functions.
    copyArrayIndexWay(newArray1,originalArray1);
    copyPointerWay(newArray2, originalArray2);
    
    // Display results.
    printf("newArray1:%s\n",newArray1);
    printf("newArray2:%s\n",newArray2);
    
    return 0;
}
// Function of copy array through using index.
void copyArrayIndexWay(char * const newArray1, const char * const originalArray1)
{
    for (int i=0; i<10; i++)
    {// Assign each character in the original array to the new array.
        newArray1[i] = originalArray1[i];
    }
}
// Function of copy array through using pointer.
 void copyPointerWay(char *newArray2, const char *originalArray2)
{
    while (*originalArray2 != '\0')
    {// Keep checking until the last one.
        *newArray2 = *originalArray2; // Assign the character from original array to new array.
        originalArray2++; // Increase the originial array to pointed to next character.
        newArray2++; // Increase the new array to pointed to next character.
    }
}
