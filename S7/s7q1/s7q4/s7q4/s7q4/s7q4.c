//
//  s7q4.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
#include <stdio.h>

int main(void)
{
    double seconds; // Declare a double type variable.
    // Ask and get user input.
    printf("Please enter a number of seconds:\n");
    scanf("%lf",&seconds);
    
    // Use reverse order to filtrate.
    if (seconds>=86400)
    {   // If user input gather than 86400, which is the number of seconds in a day, then count the number of seconds in days.
        printf("%lf day(s) in %lf seconds\n",1.0*seconds/86400,seconds);
    }
    else
    {
        if (seconds>=3600)
        {   // If user input gather than 3600, which is the number of seconds in an hour, then count the number of seconds in hours.
            printf("%lf hour(s) in %lf seconds\n",1.0*seconds/3600,seconds);
        }
        else
        {
            if (seconds>=60)
            {   // If user input gather than 60, which is the number of seconds in a minute, then count the number of seconds in minutes.
                printf("%lf minute(s) in %lf seconds\n",1.0*seconds/60,seconds);
            }
            else
            {
                if (seconds<0)
                {   // Make a default for the user to enter an error value.
                    printf("Invalid Input! The number of seconds cannot be negative!\n");
                }
                else
                {
                    // Otherwise, print the user input as the number of seconds in seconds.
                    printf("%lf seconds in %lf seconds\n",seconds,seconds);
                }
            }
        }
    }
    return 0;
}
