//
//  s1q1.c
//  
//  Student name: Zhi Zhang
//  Student number: 18210054
//
#include <stdio.h>

int main(void)
{
    // Declare some integer type to store the input and output.
    int children_1, children_2, children_3;
    double Average = 0;
    int Tallest = 0;
    int Shortest = 0;
    
    // Get input values from user.
    printf("Please enter the height of 3 children in a class (in cm)\n");
    scanf("%d %d %d",&children_1,&children_2,&children_3);
    
    // calculate the average height of 3 children (floating point).
    Average = 1.0*(children_1 + children_2 + children_3)/3;
    
    // Get tallest and shortest value through 6 different case.
    if (children_1>=children_2 && children_2>=children_3)
    {
        Tallest = children_1;
        Shortest = children_3;
    }
    if (children_1>=children_3 && children_3>=children_2)
    {
        Tallest = children_1;
        Shortest = children_2;
    }
    if (children_2>=children_1 && children_1>=children_3)
    {
        Tallest = children_2;
        Shortest = children_3;
    }
    if (children_2>=children_3 && children_3>=children_1)
    {
        Tallest = children_2;
        Shortest = children_1;
    }
    if (children_3>=children_1 && children_1>=children_2)
    {
        Tallest = children_3;
        Shortest = children_2;
    }
    if (children_3>=children_2 && children_2>=children_1)
    {
        Tallest = children_3;
        Shortest = children_1;
    }
    
    //Use a printf statement to report answers back to the user.
    printf("Input three heights:%d %d %d\nAverage is:%lf\nTallest is:%d\nShortest is:%d\n",children_1,children_2,children_3,Average,Tallest,Shortest);
   
    return 0;
}
