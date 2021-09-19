//
//  s3q2.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // Declare some variables.
    int i, j,num;
    int row,column;
    
    // Get the values from user.
    printf("Please enter the row size of array:\n");
    scanf("%d",&row);
    printf("Please enter the column size of array:\n");
    scanf("%d",&column);
    
    // Declare array A&B.
    int arrayA[row][column], arrayB[row][column];
    // Declear the 'check' array for avoid repeat.
    int check_1[1500], check_2[1500];
    
    // Consider special cases to ensure that the maximum value of rows and columns is 20.
    if (row>20 && column>20)
    {
        printf("Invalid input! (maximum 20 rows and 20 columns)\n");
        return -1;
    }
    
    // Use srand and time fuction to ensure that each run starts with a different seed to produce a truly random number.
    srand(time(NULL));
    
    // Use for loop to assign random Numbers between 100 and 1500 to the arrayA (no repeat).
    for (i=0; i<row; i++)
    {// Outer loop to control row.
        for (j=0; j<column; j++)
        {// Inner loop to control column.
            num=rand() % 1401+100; // Assign random number to 'arrayA' via 'num'.
            arrayA[i][j]=num;
            
            if (check_1[num]==1) // If check_1[num] equal to 1, that means the newly created number is already in the 'check_1 array', because the initial value of the 'check_1' array is 0.
            {
                j--; // ask j-1 then repeat this step.
            }
            else
            {
                check_1[num]=1; // Otherwise, assign 1 to the 'check_1' array which located at the position of the number in check array, to show that it's been there.
            }
        }
    }
 
    // Use for loop to assign random Numbers between 100 and 1500 to the arrayB (no repeat).
    for (i=0; i<row; i++)
    {// Outer loop to control row.
        for (j=0; j<column; j++)
        {// Inner loop to control column.
            num=rand() % 1401+100; // Assign random number to 'arrayB' via 'num'.
            arrayB[i][j]=num;
            
            if (check_2[num]==1) // If check_2[num] equal to 1, that means the newly created number is already in the 'check_2 array', because the initial value of the 'check_2' array is 0.
            {
                j--; // ask j-1 then repeat this step.
            }
            else
            {
                check_2[num]=1; // Otherwise, assign 1 to the 'check_2' array which located at the position of the number in check array, to show that it's been there.
            }
        }
    }
    
    // Use for loop to display contents of array_A
    printf("The contents of Array_A:\n");
    for (i=0; i<row; i++)
    {
        for (j=0; j<column; j++)
        {
            printf("%d ",arrayA[i][j]);
        }
        printf("\n");
    }
    printf("\n"); // Start a new line.
    
    // Use for loop to display contents of array_B
    printf("The contents of Array_B:\n");
    for (i=0; i<row; i++)
    {
        for (j=0; j<column; j++)
        {
            printf("%d ",arrayB[i][j]);
        }
        printf("\n");
    }
    printf("\n"); // Start a new line.
    
// Calculate the product of corresponding cells in arrayA and arrayB
    int product[row][column]; // Declare the 'product' array.
    
    for (i=0; i<row; i++)
    {// Outer loop to control row.
        for (j=0; j<column; j++)
        {// Inner loop to control column.
            // let 'product' array containing the product of corresponding cells in arrayA and arrayB
            product[i][j] = arrayA[i][j] * arrayB[i][j];
        }
    }
    
    // Display result.
    printf("The product of corresponding cells in array A & B is:\n");
    for (i=0; i<row; i++)
    {
        for (j=0; j<column; j++)
        {// Use for loop to print contents of 'product'array one by one.
            printf("%d ",product[i][j]);
        }
        printf("\n");
    }
    printf("\n"); // Start a new line.

// Calculate the sum of corresponding cells in arrayA and arrayB
    int sum[row][column]; // Declare the 'sum' array.
    
    for (i=0; i<row; i++)
    {// Outer loop to control row.
        for (j=0; j<column; j++)
        {// Inner loop to control column.
            // let 'sum' array containing the sum of corresponding cells in arrayA and arrayB
            sum[i][j] = arrayA[i][j] + arrayB[i][j];
        }
    }
    
    // Display result.
    printf("The sum of corresponding cells in array A & B is:\n");
    for (i=0; i<row; i++)
    {
        for (j=0; j<column; j++)
        {// Use for loop to print contents of 'sum'array one by one.
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }
    printf("\n"); // Start a new line.

// Calculate the sum of corresponding rows in arrayA and arrayB
    int sum_row[row][column]; // Declare the 'sum_row' array.
    int total_row,z; // Declare some variables.
    
    for (i=0; i<row; i++)
    {// Outer loop to control row.
        total_row = 0; // Initial variable with 0 & Reassigned to 0 to 'total_row' when it strat a new row.
        for (j=0; j<column; j++)
        {// Inner loop to control column.
            total_row += sum[i][j]; // assign total_row with the value of 'sum' array plus it self.
            
            for (z=0; z<1; z++)
            {// let 'sum_row' array containing the sum of corresponding rows in arrayA and arrayB
                sum_row[i][z] = total_row;
            }
        }
    }
    
    // Display result.
    printf("The sum of corresponding rows in array A & B is:\n");
    // j is a fixed value(j=0) because 'sum_row' array only need one column to store values in this scenario.
    for (i=0,j=0; i<row; i++)
    {// Use for loop to print contents of 'sum_row' array one by one.
        printf("%d ",sum_row[i][j]);
        printf("\n");
    }
    printf("\n"); // Start a new line.
    
// Calculate the sum of corresponding columns in arrayA and arrayB
    int sum_column[row][column]; // Declare the 'sum_column' array.
    int total_co; // Declare the variable.
    
    for (i=0; i<column; i++)
    {// Outer loop to control column.
        total_co = 0; // Initial variable with 0 & Reassigned to 0 to 'total_co' when it strat a new column.
        for (j=0; j<row; j++)
        {// Inner loop to control row.
            total_co += sum[j][i]; // assign total_co with the value of 'sum' array plus it self.
            
            for (z=0; z<1; z++)
            {// let 'sum_row' array containing the sum of corresponding columns in arrayA and arrayB
                sum_column[z][i] = total_co;
            }
        }
    }
    
    // Display result.
    printf("The sum of corresponding columns in array A & B is:\n");
    // i is a fixed value(i=0) because 'sum_co' array only need one row to store values in this scenario.
    for (i=0,j=0; j<column; j++)
    {// Use for loop to print contents of 'sum_co' array one by one.
        printf("%d ",sum_column[i][j]);
        printf("\n");
    }
    printf("\n"); // Start a new line.
    
// Print the number of total number of numbers that occur in both arrays (if any)
    int total_both=0,check_same[1500]; // Declare the 'check_same' array and 'total_both' variable (initial with 0).
    
    // Import the contens of 'arrayA' into 'check_same' array.
    for (i=0; i<row; i++)
       {// Outer loop to control row.
           for (j=0; j<column; j++)
           {// Inner loop to control column.
               num = arrayA[i][j]; // Assign the value of 'arrayA' to 'num'.
               check_same[num] = 1; // Assign 1 to the 'check_same' array which located at the position of the number in check array, to show that it's been there.
           }
       }
    
    // Use 'check_same' array to check if it contains the same number with 'arrayA' array.
    for (i=0; i<row; i++)
    {// Outer loop to control row.
        for (j=0; j<column; j++)
        {// Inner loop to control column.
            num=arrayB[i][j]; // Assign the value of 'arrayB' to 'num'.
            
            if (check_same[num]==1)
            {// If there are exit the number occur in both arrays.
                total_both += num; // Assign 'total_both' with 'num' + itself.
            }
            else
            {
                check_same[num]=1; // If number is not same, assign 1 to the 'check_same[num]' array to show that it's been there and pass.
            }
        }
    }
    if (total_both!=0)
    {// Display result if it exists.
        printf("The total number of that occur in both arrays is:%d\n",total_both);
        printf("\n"); // Start a new line.
    }
    
// Print the word 'Wow' if the same number appears in the same cell in the two arrays.
    for (i=0; i<row; i++)
    {// Outer loop to control row.
        for (j=0; j<column; j++)
        {// Inner loop to control column.
            if (arrayA[i][j]==arrayB[i][j])
            {// If the same number appears in the same cell in two arrays.
                printf("Wow! "); // Display result.
            }
        }
    }
    printf("\n"); // Start a new line.
    
    return 0;
}
