//
//  s8q2.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // This pointer will hold the base assress of the block created.
    int *ptr, *ptr_extra = NULL;
    int n, n_extra, i, decision;
    int avg=0;
    // Declare some pointer and variable for float number.
    double *ptr_d, *ptr_d_extra = NULL;
    double avg_d = 0;
    
    // Gets the user to choose an integer or a floating point number.
    printf("Please enter the type of number:\n1.integer\n2.float\n");
    scanf("%d",&decision);
    if (decision==1) // For integer.
    {// Enter the total number.
        printf("Please enter the number of elements: ");
        scanf("%d",&n);
        
        // Dynamically allocate memory useing calloc().
        ptr = (int*)calloc(n, sizeof(int));
        
        // Check if the memory has been sussessfully allocated or not.
        if (ptr == NULL)
        {
            printf("Memory not allocated!\n");
            exit(0);
        }
        else
        {// Get user input of the content of elements.
            printf("Memory successfully allocated using alloc!\n");
            for (i=0; i<n; ++i)
            {
                printf("Please enter the NO.%d element: ",i+1);
                scanf("%d",&ptr[i]);
                avg += ptr[i];// Add value to "avg".
            }
            
            printf("The elementes of the array are: ");
            for (i=0; i<n; ++i)
            {
                printf("%d, ",ptr[i]);
            }
            
            // Average number is avg/total number,
            printf("\nThe average number is:%d.\n",avg/n);
            decision = avg = 0;
            // Ask user if they wanna add more elementd.
            printf("Add more elements?\n1.Yes\n2.No\n");
            scanf("%d",&decision);
            if (decision==2)
            {
                printf("Finish!\n");
                exit(0);
            }
            else
            {
                if (decision==1)
                {
                    // Ask user enter the total extra number of elements.
                    printf("Please enter the extra number of elements: ");
                    scanf("%d",&n_extra);
                    
                    // Dynamically re-allocate memory using realloc.
                    ptr_extra = realloc(ptr, (n+n_extra) * sizeof(int));
                    
                    if(ptr_extra==NULL)
                    {
                        printf("Error re-allocating memory!\n");
                        exit(1);
                    }
                    else
                    {
                        printf("Memory successfully re-allocated!\n");
                        for(i=0;i<n;i++)
                        {
                            ptr_extra[i]=ptr[i]; //  Assign ptr[i] to ptr_extra[i]
                            avg += ptr_extra[i]; //  Caculate the sum first.
                        }
                    
                        for(i=n;i<n+n_extra;i++)
                        {// Enter the detail of elements.
                            printf("Please enter the NO.%d element: ",i+1);
                            scanf("%d",&ptr_extra[i]);
                            avg += ptr_extra[i];
                        }
                         
                        printf("Now, the elementes of the array are: ");
                        for (i=0; i<n+n_extra; ++i)
                        {
                            printf("%d, ",ptr_extra[i]);
                        }
                        // Average number.
                        printf("\nThe average number is:%d.\n",avg/(n+n_extra));
                        // Deallocating the memory.
                        free(ptr_extra);
                     }
                 }
             }
         }
    }
    else
    {   // For floating point number.
        if (decision==2)
        {// Enter the total number.
            printf("Please enter the number of elements: ");
            scanf("%d",&n);
             
            // Dynamically allocate memory useing calloc().
             ptr_d = (double*)calloc(n, sizeof(double));
             
            // Check if the memory has been sussessfully allocated or not.
             if (ptr_d == NULL)
             {
                 printf("Memory not allocated!\n");
                 exit(0);
             }
             else
             {
                 printf("Memory successfully allocated using alloc!\n");
                 for (i=0; i<n; ++i)
                 {
                     printf("Please enter the NO.%d element: ",i+1);
                     scanf("%lf",&ptr_d[i]);
                     avg_d += ptr_d[i]; // Add value to "avg".
                 }
                 
                 printf("The elementes of the array are: ");
                 for (i=0; i<n; ++i)
                 {
                     printf("%lf, ",ptr_d[i]);
                 }
                 
                 // Average number is avg/total number,
                 printf("\nThe average number is:%lf.\n",avg_d/n);
                 
                 // Ask user if they wanna add more elementd.
                 decision = avg_d = 0;
                 printf("Add more elements?\n1.Yes\n2.No\n");
                 scanf("%d",&decision);
                 if (decision==2)
                 {
                     printf("Finish!\n");
                     exit(0);
                 }
                 else
                 {
                     if (decision==1)
                     {
                         // Ask user enter the total extra number of elements.
                         printf("Please enter the extra number of elements: ");
                         scanf("%d",&n_extra);
                         
                         // Dynamically re-allocate memory using realloc.
                         ptr_d_extra = realloc(ptr_d, (n+n_extra) * sizeof(double));
                         
                         if(ptr_d_extra==NULL)
                         {
                             printf("Error re-allocating memory!\n");
                             exit(1);
                         }
                         else
                         {
                             printf("Memory successfully re-allocated!\n");
                             for(i=0;i<n;i++)
                             {
                                 ptr_d_extra[i]=ptr_d[i];//  Assign ptr[i] to ptr_extra[i]
                                 avg_d += ptr_d_extra[i];//  Caculate the sum first.
                             }
                             
                             for(i=n;i<n+n_extra;i++)
                             {
                                 printf("Please enter the NO.%d element: ",i+1);
                                 scanf("%lf",&ptr_d_extra[i]);
                                 avg_d += ptr_d_extra[i];
                             }
                             
                             printf("Now, the elementes of the array are: ");
                             for (i=0; i<n+n_extra; ++i)
                             {
                                 printf("%lf, ",ptr_d_extra[i]);
                             }
                             
                             // Average number.
                             printf("\nThe average number is:%lf.\n",avg_d/(n+n_extra));
                             
                             // Deallocating the memory.
                             free(ptr_d_extra);
                         }
                     }
                 }
             }
        }
    }
    return 0;
}
