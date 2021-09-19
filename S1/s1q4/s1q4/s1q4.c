//
//  s1q4.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
#include <stdio.h>

int main(void)
{
    int year;
    
    // Get year input from user.
    printf("Please enter a year:\n");
    scanf("%d",&year);
    
    if (((year % 4 == 0) && (year % 100 != 0) ) || (year % 400 == 0))
    {// if year is divisible by 4 but not by 100 is a leap year. Or it's divisible by 400, which is a leap year.
        printf("%d year is a leap year!\n",year);
    }
    else
    {
        printf("%d year is not a leap year.\n",year);
    }
    
    return 0;
}
