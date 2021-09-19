//
//  s5q1.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
/*
 Please modify the absolute path of the input and output files if you want to verify this program.
 */

#include <stdio.h>
#include <string.h>
// Declares the absolute path to the input/output file.
const char *INPUT_FILE_PATH = "/Users/lewiszhang/Documents/Xcode/S5/s5q1/s5q1/myFile.txt";
const char *OUTPUT_FILE_PATH = "/Users/lewiszhang/Documents/Xcode/S5/s5q1/s5q1/myOtherFile.txt";
const char str[]="Dublin";// Declare "Dublin" array for subsequent comparisons.

int main(void)
{
    FILE *fp = fopen(INPUT_FILE_PATH, "r+" ); // Open for reading
    FILE *fp_out = fopen(OUTPUT_FILE_PATH, "w+" ); // Creat and writing
    char city[30], name[30];
    int tel_num=0, age=0, wish=0;
    
    if (fp == NULL )
    {   // Check does input file exist.
        puts("Error opening myFile.txt file!\n");
    }
    else
    {
        if (fp_out == NULL )
        {   // Check does output file creat successfully.
            puts("Error creating myOtherFile.txt file!\n");
        }
        // Read the first record from "myFile.txt"
        fscanf(fp,"%10s %10s %10d %10d %10d",city,name,&tel_num,&age,&wish);
        // Print out the title of each column.
        fprintf(fp_out,"City    Name   TEL_number Age Wish\n");
        while (!feof(fp))
        {// if not the last one in input file, then get in the loop.
            // Check if records are belong to "Dublin" and people who agreed to share their data.
            if ((wish==1)&&strcmp(str,city)==0)
            {// Print out the suitable records to the output file.
                fprintf(fp_out,"%s  %s  %d  %d  %d\n",city,name,tel_num,age,wish);
            }
            // Read the records from "myFile.txt"
            fscanf(fp,"%10s %10s %10d %10d %10d",city,name,&tel_num,&age,&wish);
        }
        // Close file.
        fclose(fp);
        fclose(fp_out);
    }
    return 0;
}
