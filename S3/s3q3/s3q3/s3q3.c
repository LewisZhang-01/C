//
//  s3q3.c
//
//  Created by Lewis Zhang on 13/02/2020.
//  Copyright © 2020 Zhi Zhang. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    // Declare some variables.
    int row_a, column_a, row_b, column_b, i, j;
    
// Get the size of matrix_A from user.
    printf("Please enter the row size of matrix_A:\n");
    scanf("%d",&row_a);
    printf("Please enter the column size of matrix_A:\n");
    scanf("%d",&column_a);
    
    int matrix_A[row_a][column_a]; // Declare 'matrix_A' array.
    
// Ask user input the contents of matrix_A.
    for (i=0; i<row_a; i++)
    {// Outer loop to control row.
        for (j=0; j<column_a; j++)
        {// Inner loop to control column.
            printf("Please enter the elements of matrix_A:\n");
            scanf("%d",&matrix_A[i][j]);
        }
    }
    printf("\n"); // Start a new line.
    
    // Get the size value of matrix_B from user.
    printf("Please enter the row size of matrix_B:\n");
    scanf("%d",&row_b);
    printf("Please enter the column size of matrix_B:\n");
    scanf("%d",&column_b);
    
    int matrix_B[row_b][column_b]; // Declare 'matrix_B' array.
    
// Ask user input the contents of matrix_B .
    for (i=0; i<row_b; i++)
    {// Outer loop to control row.
        for (j=0; j<column_b; j++)
        {// Inner loop to control column.
            printf("Please enter the elements of matrix_B:\n");
            scanf("%d",&matrix_B[i][j]);
        }
    }
    
// Display the contents of Matrix_A.
    printf("The matrix_A:\n");
    for (i=0; i<row_a; i++)
    {// Outer loop to control row.
        for (j=0; j<column_a; j++)
        {// Inner loop to control column.
            printf("%d ",matrix_A[i][j]);
        }
        printf("\n");
    }
    printf("\n"); // Start a new line.
    
// Display the contents of Matrix_B.
    printf("The matrix_B:\n");
    for (i=0; i<row_b; i++)
    {// Outer loop to control row.
        for (j=0; j<column_b; j++)
        {// Inner loop to control column.
            printf("%d ",matrix_B[i][j]);
        }
        printf("\n");
    }
    printf("\n"); // Start a new line.
    
// Calculate the product of the arrays using matrix multiplication rules.
    int product[row_a][column_b]; // Declare 'product' array to store the product value of two matrices.
    int k; // Declare a new variable.
    
    if (column_a==row_b)
    {// Only when two matrices follow the rules of matrix multiplication will they enter the calculation.
        for (i=0; i<row_a; i++)
        {// Outer loop to control row of matrix_A.
            for (j=0; j<column_b; j++)
            {// Inner loop to control column of matrix_B.
                // Initial 'product' array with 0 & Reassigned to 0 when it completes its innermost loop.
                product[i][j]=0;
                for (k=0; k<row_b; k++) // Most inner loop.
                {
                    product[i][j] += matrix_A[i][k] * matrix_B[k][j]; // Matrix multiplication rule.
                }
            }
        }

        printf("product of two matrices A & B is:\n"); // Display result.
        for (i=0; i<row_a; i++)
        {
            for (j=0; j<column_b; j++)
            {
                printf("%d ",product[i][j]);
            }
            printf("\n"); // Start a new line.
        }
        
    }
    else // Otherwise, display the error message.
    {
        printf("Error! two matrixes can't be multiplied!");
    }
    
    return 0;
}
