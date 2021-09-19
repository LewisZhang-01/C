//
//  s7q1.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Define a constant value.
const int ARRAY_SIZE = 12;
// Declare some functions.
char Printer(int words);
void shuffle(int words[]);
void Random_Select (void);

int main ()
{
    // Declare and set an array of 12 integers.
    int words[] = {0,1,2,3,4,5,6,7,8,9,10,11};
    // Declare an array of 12 pointers-to-integers.
    int i, *array_of_pointers[ARRAY_SIZE];
    
    for ( i = 0; i < ARRAY_SIZE; i++)
    {
        // For indices 1 through 12, set a pointer to point to a corresponding integer.
        array_of_pointers[i] = &words[i];
    }
    printf("The original order:\n");
    for ( i = 0; i < ARRAY_SIZE; i++)
    {
       // print the values of the integers pointed to by the pointers.
        Printer(*array_of_pointers[i]);
        printf(" ");
    }
    printf("\n\n");// New line.
    shuffle(*array_of_pointers);// Call the "shuffle" function.
    
    Random_Select();// Call the "Random_Select" function.
    
    return 0;
}

// "Shuffle" function.
void shuffle(int words[])
{
    int index_1, index_2, tmp, i;
    // Use a different seed value so that we don't get same result each time we run this program.
    srand((unsigned int)time(NULL));
    
    for(i=0; i<6; i++)
    {
        // Assign random numbers between 0 and 11 to the "index".
        index_1=rand() % 12;
        index_2=rand() % 12;
        
        //printf("index1:%d\nindex2:%d\n",index_1,index_2);
        
        if(index_1!=index_2)
        {   // If "index" is not current number, then swap them.
            tmp=words[index_2];
            words[index_2]=words[index_1];
            words[index_1]=tmp;
        }
    }
    printf("The order after the shuffle:\n");
    for ( i = 0; i < ARRAY_SIZE; i++)
    {
       // print the values of the integers pointed to by the pointers.
        Printer(words[i]);
        printf(" ");// Print a space.
    }
    printf("\n");// New line.
}

// "Random_Select" function.
void Random_Select ()
{
    // Use a different seed value so that we don't get same result each time we run this program.
    srand((unsigned int)time(NULL));
    // Assign random numbers between 0 and 11 to the "index".
    int index=rand()%12;
    printf("\nSelect a random word:\n");
    // Call "Printer" function.
    Printer(index);
    printf("\n");// New line.
}

// "Printer" function.
char Printer(int words)
{
    switch (words)
    {// Print the corresponding word according to the random number created before.
        case 0:
            printf("COMP10120");
            break;
        case 1:
            printf("is");
            break;
        case 2:
            printf("my");
            break;
        case 3:
            printf("favourite");
            break;
        case 4:
            printf("module");
            break;
        case 5:
            printf("and");
            break;
        case 6:
            printf("I");
            break;
        case 7:
            printf("learn");
            break;
        case 8:
            printf("lots");
            break;
        case 9:
            printf("of");
            break;
        case 10:
            printf("interesting");
            break;
        case 11:
            printf("things");
            break;
        default:
            break;
    }
    return 0;
}
