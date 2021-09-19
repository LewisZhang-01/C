//
//  s10q2.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
#include <stdio.h>
#include <string.h>
/* Prototype */
void printer(int sizeofNums, char *y[]);
char a[] = "one";
char b[] = "two";
char c[] = "three";
char d[] = "four";
char e[] = "five";

/* Pointer function */
void printer(int sizeofNums, char *y[])
{   /* Keep seek until the last element in num array*/
    for (int i=0; i<sizeofNums/8; i++)
    {/* The size of each array is 8, sizeofNums/8=number in "nums" array */
        /* Create a new temporary array to store each word in order to print the first character in each word */
        char temp[10];
        strcpy(&temp[0], y[i]); /* copy word into temp array */
        printf("Word %d is %s. The first letter of the word is %c\n",i+1,y[i],temp[0]);
    }
}
    
int main(void)
{
    /* Initialize the nums array */
    char *nums[] = {a,b,c,d,e};
    /* Call the printer function */
    printer(sizeof(nums), nums);
    return 0;
}
