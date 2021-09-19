//
//  s4q4.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
#include <stdio.h>
#define MAX_VALUE 100

int main(void)
{
    char str[MAX_VALUE];// Declare str[] array.
    char *p;// Declare the pointer.
    int vowels_num=0,consonants_num=0;// Declare two counter.
    
    // Get user input.
    printf("Enter any string (max 100 characters with no spaces):\n");
    fgets(str, 100, stdin); //stored the user input ins str which is an array.
    
    p=str; // Assign base address of char array to pointer.
    
    while(*p!='\n')
    {// Keep checking the character until the last one.
        if ( (*p>'a'|| *p<='z') && (*p>'A' || *p>='Z'))
        {// Filter out characters other than letters, such as numbers.
            if(*p=='A'||*p=='E'||*p=='I'||*p=='O'||*p=='U'||*p=='a'||*p=='e'||*p=='i'||*p=='o'||*p=='u')
            {// If the letter is one of the vowels, increment the vowels counter by one.
                vowels_num++;
            }
            else
            {// Otherwise, increment the consonant counter by one.
                consonants_num++;
            }
        }
        p++;// Increase the pointer to point next character.
    }
    
    // Display result.
    printf("Number of Vowels in String:%d\n",vowels_num);
    printf("Number of Consonants in String:%d\n",consonants_num);
    
    return 0;
}
