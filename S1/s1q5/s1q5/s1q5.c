//
//  s1q5.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
#include <stdio.h>
#define Pi 3.141592654

int main(void)
{
    double radius;
    
    // Get radius value from user.
    printf("Please enter the radius of a circle:\n");
    scanf("%lf",&radius);
    
    // Calculate the area & circumference of circle and print out.
    printf("Area of circle = %lf\n",radius*radius*Pi);
    printf("Circumference of circle = %lf\n",2*Pi*radius);
    
    return 0;
}
