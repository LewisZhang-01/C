//
//  s1q2.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
#include <stdio.h>
#include <math.h>
#define MAX_SIZE 10

int main(void)
{
    int student_number,single;
    int i,j=7,sum=0;
    
    // Get student number value from user.
    printf("Please input your student number:\n");
    scanf("%d",&student_number);
    
    // Use for loop to print every single number.
    for (i=0; i<8; i++)
    {
        single = student_number/pow(10, j);// Use "student_number" divided by 10^j where j is from 7 to 0.
        printf("%d\n",single);
        sum += single; // The sum of every number that was printed before.
        student_number -= single*pow(10, j); // subtract 10^j where j is used before from "student_number".
        j--;
    }
    
    // Print the sum of every single number.
    printf("Sum = %d\n",sum);
    
    return 0;
}
