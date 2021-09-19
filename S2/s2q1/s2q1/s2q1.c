//
//  s2q1.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
#include <stdio.h>
#include <math.h>

// Declare the function of "Day_of_The_Week".
int Day_of_The_Week (int q, int m, int K);

int main(void)
{
    // Declare some variables.
    int q, m, K, h ;
    
    // Get the values from user.
    printf("Please enter the day:\n");
    scanf("%d",&q);
    printf("Please enter the month:\n");
    scanf("%d",&m);
    printf("Please enter the year:\n");
    scanf("%d",&K);
    
    h = Day_of_The_Week(q,m,K); // Use the fuction and finally return the value to here.
    
    switch (h) // convert number 0-6 to character then print out.
    {
        case 0 : printf("%d/%d/%d - Saturday.\n",q,m,K);
                 break;
            
        case 1 : printf("%d/%d/%d - Sunday.\n",q,m,K);
                 break;

        case 2 : printf("%d/%d/%d - Monday\n",q,m,K);
                 break;
                   
        case 3 : printf("%d/%d/%d - Tuesday\n",q,m,K);
                 break;
                   
        case 4 : printf("%d/%d/%d - Wednesday\n",q,m,K);
                 break;
                   
        case 5 : printf("%d/%d/%d - Thursday\n",q,m,K);
                 break;
                   
        case 6 : printf("%d/%d/%d - Friday\n",q,m,K);
                 break;
        // Give a solution to the special case where h is not equal to the number above.
        default: printf("Error!\n");
                 break;
    }
    
    return 0;
}

//Function of "Day_of_The_Week".
int Day_of_The_Week (int q, int m, int K)
{
    // Consider some special cases in Zeller’s Congruence algorithm, that is, January and February are counted as months 13 and 14 of the previous year.
    if (m==1)
    {
        m = 13; // 13 stands for January(1).
        K = K-1; // It belong to the previous year.
        return (q + ((13*(m+1))/5) + (K % 100) + ((K % 100)/4) + ((K/100)/4) - 2*(K/100))%7;
    }
    else
    {
        if (m==2)
        {
            m = 14; // 14 stands for February(2).
            K = K-1; // It belong to the previous year.
            return (q + ((13*(m+1))/5) + (K % 100) + ((K % 100)/4) + ((K/100)/4) - 2*(K/100))%7;
        }
        else
        {
            // Return the value after calculated.
            return (q + ((13*(m+1))/5) + (K % 100) + ((K % 100)/4) + ((K/100)/4) - 2*(K/100))%7;
        }
    }
}
